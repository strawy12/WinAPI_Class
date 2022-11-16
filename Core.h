#pragma once
#include "BWindow.h"


class Core : public BWindow
{
public:
	SINGLE(Core);

	private:
		Core();
		~Core();

public:
	int		Init(HWND hWnd, POINT ptResolution);
	void	Progress();

public:
	const HWND& GetWndHandle() { return _hWnd; }
	POINT& GetResolution() { return _ptResolution; }

private:
	void Update();
	void Render();

private:
	POINT _ptResolution;
	HDC _hDC;
	HDC _memDC;
	HBITMAP _hBit;
};
