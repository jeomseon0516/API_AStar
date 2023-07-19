#pragma once
#include "Vector2.h"

typedef struct tagTransform
{
	Vector2 position;
	Vector2 size;

	tagTransform(const Vector2& _position = Vector2(), const Vector2& _size = Vector2()) : position(_position), size(_size) {}
}Transform;

typedef struct tagFrame
{
	int maxFrameX;
	int frameX;
	int frameY;

	tagFrame() : frameX(0), frameY(0), maxFrameX(0) {}
	tagFrame(int _frameX, int _frameY, int _maxFrameX) : frameX(_frameX), frameY(_frameY), maxFrameX(_maxFrameX) {}
}Frame;