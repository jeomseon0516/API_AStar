#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Start()
{
	_tiles.resize(COUNT_Y);
	_tiles.resize(COUNT_X);

	_isFind = false;

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			_tiles[y][x] = (new Tile())->Start(Vector2Int(x, y));
			_closedTile[y][x] = true;
		}
	}
}


