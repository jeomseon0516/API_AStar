#pragma once
#include "Transform.h"
#include "Bitmap.h"

class AStar;

enum TILE_KIND
{
	NORMAL = 0,
	START  = 1,
	END    = 2,
	OPEN   = 3,
	CLOSE  = 4,
	FIND   = 5,
	WALL   = 6
};

class Tile
{
private:
	TILE_KIND _tileKind;
	AStar* _aStar;
	Tile* _parentNode;

	Transform transform;
	Bitmap* _image;
	Frame _imageFrame;

	int _g;
	int _h;

	Vector2Int _tilePoint; // .. 키 값이 되어줄 포인트 값

public:
	void Init();
	Tile* Start(Tile* parentNode, AStar* aStar, const Vector2Int& point);
	void Update();

	void Render()
	{
		TransparentBlt(g_hdc,
			int(transform.position.x - transform.size.x * 0.5f),
			int(transform.position.y - transform.size.y * 0.5f),
			(int)transform.size.x,
			(int)transform.size.y,
			_image->GetMemDC(),
			int(_imageFrame.frameX * transform.size.x),
			int(_imageFrame.frameY * transform.size.x),
			(int)transform.size.x,
			(int)transform.size.y,
			RGB(255, 0, 255));
	}

	bool CheckCursorCollision(POINT cursorPoint);

	int GetG() { return _g; }
	int GetH() { return _h; }

	void SetG(int g) { _g = g; }
	void SetH(int h) { _h = h; }

	// start노드와 end 노드는 하나 씩만 존재 할 수 있기 때문에
	void SetTileKind(const TILE_KIND& tileKind) 
	{ 
		_tileKind = tileKind;
		_imageFrame.frameX = _tileKind;
	}

	Tile* GetParentNode()const { return _parentNode; }
	void SetParentNode(Tile* parentNode) { _parentNode = parentNode; }

	Vector2Int GetTilePoint()const { return _tilePoint; }
	TILE_KIND GetTileKind()const   { return _tileKind; }

	int GetF() { return _g + _h; }
public:
	Tile();
	virtual ~Tile();
};