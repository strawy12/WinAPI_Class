#include "pch.h"
#include "BWindow.h"
#include "Core.h"

BWindow::BWindow()
{
}

BWindow::~BWindow()
{
}

int BWindow::Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	_hInst = hInstance;
	MyRegisterClass();
	WindowCreate();
	WindowShow(nCmdShow);
	WindowUpdate();


	if (FAILED(Core::GetInst()->Init(_hWnd, POINT{1280, 720})))
	{
		MessageBox(_hWnd, L"Core ���� ����", L"Error", MB_OK);
		return FALSE;
	}
	// ����ó��

	return MessageLoop();
}

ATOM BWindow::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = BWindow::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInst;
	wcex.hIcon = LoadIcon(_hInst, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINDOW_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	return RegisterClassExW(&wcex);
}

void BWindow::WindowCreate()
{
	_hWnd = CreateWindowW(
		WINDOW_NAME
		, L"OIF's Framework"
		, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT
		, 0
		, CW_USEDEFAULT
		, 0
		, nullptr
		, nullptr
		, _hInst
		, nullptr);
}

void BWindow::WindowShow(int nCmdShow)
{
	ShowWindow(_hWnd, nCmdShow);
}

void BWindow::WindowUpdate()
{
	UpdateWindow(_hWnd);
}
LRESULT BWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int BWindow::MessageLoop()
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// �޽����� ������ ������� -> ���� ���� ����
			Core::GetInst()->Progress();
		}
	}

	return (int)msg.wParam;
}

