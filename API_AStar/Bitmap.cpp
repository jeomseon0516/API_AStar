#include "Bitmap.h"

Bitmap* Bitmap::Loadbmp(const LPCWSTR& _fileName)
{
	m_hdc = GetDC(g_hWnd);
	m_memDC = CreateCompatibleDC(m_hdc);

	m_bitmap = (HBITMAP)LoadImage(NULL, _fileName, IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_oldBitmap = (HBITMAP)SelectObject(m_memDC, m_bitmap);

	ReleaseDC(g_hWnd, m_hdc);

	return this;
}

void Bitmap::Release()
{
	SelectObject(m_hdc, m_bitmap);

	DeleteObject(m_bitmap);
	DeleteDC(m_hdc);
}

Bitmap::Bitmap() {}

Bitmap::~Bitmap() {}
