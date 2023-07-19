#pragma once
#include "Include.h"
#include "Tile.h"

class MainUpdate
{
private:
	vector<vector<Tile*>> _tiles;
	vector<Tile*> _findList;
	bool _closedTile[COUNT_Y][COUNT_X];
	// 우선순위 큐 구현..
	bool _isFind;

public:
	void Start();
	void Update()
	{
	}

public:
	 MainUpdate();
	~MainUpdate();
};

