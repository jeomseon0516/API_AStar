#pragma once
#include "Include.h"
#include "Tile.h"

#define COST 10
#define DIAGONAL_COST 14

struct OpenNode
{
	Tile* node;
	
};

class MainUpdate
{
private:
	// .. 타일
	Tile* _tiles[COUNT_Y][COUNT_X];
	vector<Tile*> _findList; // 현재 내가 찾은 노드들..
	bool _closedTile[COUNT_Y][COUNT_X];
	bool _openTile[COUNT_Y][COUNT_X]; // 현재 내가 찾을 타일이 오픈리스트에 담겨져 있는가?
	// .. 우선순위 큐 구현..
	bool _isFind;

public:
	void Init();
	void Start();
	void Update()
	{
		for (int y = 0; y < COUNT_Y; ++y)
			for (int x = 0; x < COUNT_X; ++x)
				_tiles[y][x]->Update();
	}
	void Render()
	{
		for (int y = 0; y < COUNT_Y; ++y)
			for (int x = 0; x < COUNT_X; ++x)
				_tiles[y][x]->Render();
	}

public:
	 MainUpdate();
	~MainUpdate();
};

