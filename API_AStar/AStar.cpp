#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

void AStar::Init()
{
	_isFind = false;
	_startNode = _endNode = nullptr;

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			_closedTile[y][x] = false;
			_openTile[y][x]   = false;
		}
	}
}

AStar* AStar::Start()
{
	for (int y = 0; y < COUNT_Y; ++y)
		for (int x = 0; x < COUNT_X; ++x)
			_tiles[y][x] = (new Tile())->Start(this, Vector2Int(x, y));

	Init();

	return this;
}

void AStar::findWay()
{
	if (_startNode == nullptr || _endNode == nullptr) return;

	pushOpenList(_startNode);

	Tile* pivotNode = popOpenList();

	for (; pivotNode->GetTilePoint() != _endNode->GetTilePoint(); pivotNode = popOpenList())
	{
		_closedTile[pivotNode->GetTilePoint().y][pivotNode->GetTilePoint().x] = true;

		Vector2Int searchPoint = Vector2Int(pivotNode->GetTilePoint().x - 1, pivotNode->GetTilePoint().y - 1); // .. LeftTop

		if (checkEdge(searchPoint.y, searchPoint.x) && !containClosedList(searchPoint));
		
	}
}

void AStar::pushOpenList(Tile* tile)
{
	_openTile[tile->GetTilePoint().y][tile->GetTilePoint().x] = true;
	_openPq.push(tile);
}

Tile* AStar::popOpenList()
{
	Tile* bestNode = _openPq.top();
	_openPq.pop();

	_openTile[bestNode->GetTilePoint().y][bestNode->GetTilePoint().x] = false;

	return nullptr;
}

bool AStar::checkEdge(int y, int x)
{
	return y > 0 && x > 0 && y < COUNT_Y && x < COUNT_X;
}

bool AStar::containClosedList(const Vector2Int& tilePoint)
{
	return _closedTile[tilePoint.y][tilePoint.x];
}

bool AStar::containOpenList(const Vector2Int& tilePoint)
{
	return _openTile[tilePoint.y][tilePoint.x];
}

void AStar::SetStartNode(Tile* node)
{
	if (setNormalNode(_startNode, node)) return;
	_startNode = node;
}

void AStar::SetEndNode(Tile* node)
{
	if (setNormalNode(_endNode, node)) return;
	_endNode = node;
}

bool AStar::setNormalNode(Tile* pivotNode, Tile* node)
{
	if (pivotNode == node) return true;

	if (pivotNode != nullptr)
		pivotNode->SetNormalNode();

	return false;
}