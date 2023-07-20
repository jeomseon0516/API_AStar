#pragma once
#include "Tile.h"

#define COST          10
#define DIAGONAL_COST 14

struct NodeCompare
{
	bool operator()(Tile* a, Tile* b)
	{
		return a->GetF() > b->GetF();
	}
};

class AStar
{
private:
	// .. 타일
	Tile* _tiles[COUNT_Y][COUNT_X];
	// .. 현재 내가 찾은 노드들..
	stack<Tile*> _findList; 
	// .. pivot 노드가 탐색할 타일이 닫힌 리스트에 담겨져 있는가?
	bool _closedTile[COUNT_Y][COUNT_X]; 
	// .. pivot 내가 찾을 타일이 오픈리스트에 담겨져 있는가?
	bool _openList[COUNT_Y][COUNT_X];
	// .. 우선순위 큐 구현..
	priority_queue<Tile*, vector<Tile*>, NodeCompare> _openPq;
	Tile* _startNode;
	Tile* _endNode;

	bool _isFind;
private:

	void findWay();

	void pushOpenList(Tile* tile);
	Tile* popOpenList();

	bool checkEdge(int y, int x);
	bool decideMakingNode(Tile* pivotNode, Vector2Int nodePoint, int cost);

	bool setNormalNode(Tile* pivotNode, Tile* node);

public:
	void Init();
	AStar* Start();

	void Update()
	{
		if (!_isFind)
		{
			if (_findList.empty())
			{
				for (int y = 0; y < COUNT_Y; ++y)
					for (int x = 0; x < COUNT_X; ++x)
						_tiles[y][x]->Update();

				if (GetAsyncKeyState(VK_RETURN) && _startNode != nullptr && _endNode != nullptr)
				{
					pushOpenList(_startNode);
					_isFind = true;
				}
			}

			if (GetAsyncKeyState(VK_ESCAPE))
				Init();
		}
		else
			findWay();
	}

	void Render()
	{
		for (int y = 0; y < COUNT_Y; ++y)
			for (int x = 0; x < COUNT_X; ++x)
				_tiles[y][x]->Render();
	}

	void SetStartNode(Tile* node);
	void SetEndNode(Tile* node);

public:
	 AStar();
	~AStar();
};

