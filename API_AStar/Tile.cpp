#include "Tile.h"
#include "AStar.h"

Tile::Tile()
{
	_image = (new Bitmap())->Loadbmp(L"../Resource/Tile.bmp");
}

Tile::~Tile()
{
}

void Tile::Init()
{
	_imageFrame = Frame(0, 0, 1);
	_g = _h = 0;
}

Tile* Tile::Start(AStar* aStar, const Vector2Int& point)
{
	_aStar = aStar;
	_tilePoint = point;

	Init();

	Vector2 position = Vector2(TILE_SIZE * 0.5f + TILE_SIZE * point.x,
							   TILE_SIZE * 0.5f + TILE_SIZE * point.y);

	transform = Transform(position, Vector2(TILE_SIZE, TILE_SIZE));

	return this;
}

void Tile::Update()
{
	POINT cursorPoint;

	GetCursorPos(&cursorPoint);
	ScreenToClient(g_hWnd, &cursorPoint);

	if (GetAsyncKeyState(VK_LBUTTON) && CheckCursorCollision(cursorPoint))
	{
		if (GetAsyncKeyState(VK_SPACE)) // .. 벽 생성
			_imageFrame.frameX = WALL;
		else if (GetAsyncKeyState(VK_LCONTROL)) // .. 일반 타일로 변경
			_imageFrame.frameX = NORMAL;
		else if (GetAsyncKeyState('S')) // .. startNode 생성
		{
			_imageFrame.frameX = START;
			_aStar->SetStartNode(this);
		}
		else if (GetAsyncKeyState('E')) // .. endNode 생성
		{
			_imageFrame.frameX = END;
			_aStar->SetEndNode(this);
		}
	}
}

bool Tile::CheckCursorCollision(POINT cursorPoint)
{
	return transform.position.x - transform.size.x * 0.5f < cursorPoint.x &&
		   transform.position.x + transform.size.x * 0.5f > cursorPoint.x &&
		   transform.position.y - transform.size.y * 0.5f < cursorPoint.y &&
		   transform.position.y + transform.size.y * 0.5f > cursorPoint.y;
}