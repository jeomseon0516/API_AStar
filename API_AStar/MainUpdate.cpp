#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Init()
{
	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			_closedTile[y][x] = true;
			_openTile[y][x] = false;
		}
	}
}

void MainUpdate::Start()
{
	_isFind = false;

	for (int y = 0; y < COUNT_Y; ++y)
		for (int x = 0; x < COUNT_X; ++x)
			_tiles[y][x] = (new Tile())->Start(Vector2Int(x, y));

	Init();
}


