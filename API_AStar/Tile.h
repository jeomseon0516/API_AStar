#pragma once
#include "Transform.h"
#include "Bitmap.h"

enum TILE_KIND
{
	NORMAL = 0,
	START  = 1,
	END    = 1,
	OPEN   = 2,
	CLOSE  = 3,
	FIND   = 4
};

class Tile
{
private:
	Transform transform;
	Bitmap* _image;
	Frame _imageFrame;

	int _g;
	int _h;

	Vector2Int _tilePoint;
	bool _isMove;

public:
	virtual Tile* Start(const Vector2Int& point);
	virtual void Update()
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (GetAsyncKeyState(VK_SPACE))
			else if (VK_)
		}
	}

	virtual void Render()
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

	bool GetIsMove()const { return _isMove; }
	void SetIsMove(bool isMove) { _isMove = _isMove; }

	int GetG() { return _g; }
	int GetH() { return _h; }

	void SetG(int g) { _g = g; }
	void SetH(int h) { _h = h; }

	int GetF() { return _g + _h; }
public:
	Tile();
	virtual ~Tile();
};

