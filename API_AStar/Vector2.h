#pragma once

typedef struct tagVector2
{
	float x;
	float y;

	tagVector2 operator+(const tagVector2& value) { return tagVector2(x + value.x, y + value.y); }
	tagVector2 operator-(const tagVector2& value) { return tagVector2(x - value.x, y - value.y); }
	tagVector2 operator*(const float& value) { return tagVector2(x * value, y * value); }

	tagVector2(const float& _x = 0, const float& _y = 0) : x(_x), y(_y) {}
}Vector2;

typedef struct tagVector2Int
{
	int x;
	int y;

	tagVector2Int operator+(const tagVector2Int& value) { return tagVector2Int(x + value.x, y + value.y); }
	tagVector2Int operator-(const tagVector2Int& value) { return tagVector2Int(x - value.x, y - value.y); }
	tagVector2Int operator*(int value) { return tagVector2Int(x * value, y * value); }

	tagVector2Int(int _x = 0, int _y = 0) : x(_x), y(_y) {}
}Vector2Int;