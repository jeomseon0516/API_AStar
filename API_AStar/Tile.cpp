#include "Tile.h"

Tile::Tile() : _isMove(true)
{
}

Tile::~Tile()
{
}

Tile* Tile::Start(const Vector2Int& point)
{
	_imageFrame = Frame(0, 0, 1);
	_image = (new Bitmap())->Loadbmp(L"../Resource/Tile.bmp");
	_tilePoint = point;

	_g = _h = 0;

	Vector2 position = Vector2(TILE_SIZE * 0.5f + TILE_SIZE * point.x,
							   TILE_SIZE * 0.5f + TILE_SIZE * point.y);

	transform = Transform(position, Vector2(TILE_SIZE, TILE_SIZE));

	return this;
}