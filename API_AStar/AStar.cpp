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

	int max = COUNT_X * COUNT_Y;

	fill(&_closedTile[0][0], &_closedTile[0][0] + max, false);
	fill(&_openList[0][0], &_openList[0][0] + max, false);

	while (!_openPq.empty())
		_openPq.pop();

	while (!_findList.empty())
		_findList.pop();

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			_tiles[y][x]->SetParentNode(nullptr);
			_tiles[y][x]->SetTileKind(NORMAL);
			_tiles[y][x]->SetH(0);
			_tiles[y][x]->SetG(0);
		}
	}
}

AStar* AStar::Start()
{
	for (int y = 0; y < COUNT_Y; ++y)
		for (int x = 0; x < COUNT_X; ++x)
			_tiles[y][x] = (new Tile())->Start(nullptr, this, Vector2Int(x, y));

	Init();

	return this;
}

void AStar::findWay()
{
	if (_openPq.empty())
	{
		_isFind = false;
		return;
	}

	Tile* pivotNode = popOpenList();

	if (pivotNode->GetTilePoint() != _endNode->GetTilePoint())
	{
		_closedTile[pivotNode->GetTilePoint().y][pivotNode->GetTilePoint().x] = true;
		_tiles[pivotNode->GetTilePoint().y][pivotNode->GetTilePoint().x]->SetTileKind(CLOSE);

		int cost = pivotNode->GetG() + COST;
		int diagonalCost = pivotNode->GetG() + DIAGONAL_COST;

		bool left   = decideMakingNode(pivotNode, Vector2Int(-1, 0), cost); // .. Left
		bool right  = decideMakingNode(pivotNode, Vector2Int(1, 0),  cost); // .. Right
		bool top    = decideMakingNode(pivotNode, Vector2Int(0, -1), cost); // .. Top
		bool bottom = decideMakingNode(pivotNode, Vector2Int(0, 1),  cost); // .. Bottom

		if (left && top)
			decideMakingNode(pivotNode, Vector2Int(-1, -1), diagonalCost); // .. LeftTop
		if (right && top)
			decideMakingNode(pivotNode, Vector2Int(1, -1), diagonalCost); // .. RightTop
		if (left && bottom)
			decideMakingNode(pivotNode, Vector2Int(-1, 1), diagonalCost); // .. LeftBottom
		if (right && bottom)
			decideMakingNode(pivotNode, Vector2Int(1, 1), diagonalCost); // .. RightBottom
	}
	else
	{
		pivotNode = pivotNode->GetParentNode(); // .. endNode 표시를 위해서

		while (pivotNode->GetParentNode())
		{
			_findList.push(pivotNode);
			pivotNode->SetTileKind(FIND);
			pivotNode = pivotNode->GetParentNode();
		}

		_isFind = false;
	}
}

void AStar::pushOpenList(Tile* tile)
{
	_openList[tile->GetTilePoint().y][tile->GetTilePoint().x] = tile;
	_tiles[tile->GetTilePoint().y][tile->GetTilePoint().x]->SetTileKind(OPEN);
	_openPq.push(tile);
}

Tile* AStar::popOpenList()
{
	Tile* bestNode = _openPq.top();
	_openPq.pop();

	_openList[bestNode->GetTilePoint().y][bestNode->GetTilePoint().x] = false;

	return bestNode;
}

bool AStar::checkEdge(int y, int x)
{
	return y < 0 || x < 0 || y >= COUNT_Y || x >= COUNT_X;
}

// .. 벽인 경우 false return 대각선 이동시 인접한 수평, 수직의 노드들이 벽인지 확인해야함
bool AStar::decideMakingNode(Tile* pivotNode, Vector2Int nodePoint, int cost)
{
	Vector2Int searchPoint = pivotNode->GetTilePoint() + nodePoint;

	int x = searchPoint.x;
	int y = searchPoint.y;

	if (checkEdge(y, x) || _closedTile[y][x])
		return true;

	if (_tiles[y][x]->GetTileKind() == WALL)
		return false;

	if (_openList[y][x])
	{
		// .. 경로 개선
		if (cost < _tiles[y][x]->GetG())
		{
			_tiles[y][x]->SetParentNode(pivotNode);
			_tiles[y][x]->SetG(cost);
		}
	}
	else // .. 새로운 노드 생성
	{
		_tiles[y][x]->SetParentNode(pivotNode);

		// .. 맨해튼 거리 측정
		int intervalX = abs(_endNode->GetTilePoint().x - x);
		int intervalY = abs(_endNode->GetTilePoint().y - y);

		_tiles[y][x]->SetH((intervalX + intervalY) * COST);
		_tiles[y][x]->SetG(cost);

		pushOpenList(_tiles[y][x]);
	}

	return true;
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
		pivotNode->SetTileKind(NORMAL);

	return false;
}