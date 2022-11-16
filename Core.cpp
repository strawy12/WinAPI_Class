#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

Core::Core()
	: _ptResolution{}
	, _hDC(0)
{
}

Core::~Core()
{
	ReleaseDC(_hWnd, _hDC);
	DeleteObject(_hBit);
	DeleteDC(_memDC);
}

int Core::Init(HWND hWnd, POINT ptResolution)
{
	_hWnd = hWnd;
	_ptResolution = ptResolution;
	_hDC = GetDC(hWnd);

	

	_hBit = CreateCompatibleBitmap(_hDC, _ptResolution.x, _ptResolution.y);
	_memDC = CreateCompatibleDC(_hDC);
	SelectObject(_memDC, _hBit);

	TimeManager::GetInst()->Init();
	KeyManager::GetInst()->Init();
	SceneManager::GetInst()->Init();

	
	RECT rt = { 0,0,_ptResolution.x, _ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	return S_OK;
}


void Core::Progress()
{
	
	Update();
	Render();
}

void Core::Update()
{
	TimeManager::GetInst()->Update();
	KeyManager::GetInst()->Update();
	SceneManager::GetInst()->Update();

	
}

void Core::Render()
{
	PatBlt(_memDC, 0, 0, _ptResolution.x, _ptResolution.y, WHITENESS);
	SceneManager::GetInst()->Render(_memDC);

	
	

	BitBlt(_hDC, 0, 0, _ptResolution.x, _ptResolution.y, _memDC, 0, 0, SRCCOPY);
}


