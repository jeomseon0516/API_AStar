#pragma once
#include "Include.h"

class Bitmap
{
private:
	HDC m_hdc, m_memDC;
	HBITMAP m_bitmap, m_oldBitmap;
public:

	Bitmap* Loadbmp(const LPCWSTR& _fileName);
	void Release();

	HDC GetMemDC()const { return m_memDC; }

	Bitmap();
	~Bitmap();
};

