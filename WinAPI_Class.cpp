#include "framework.h"
#include "WinAPI_Class.h"
#include <time.h>
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

POINT g_ptObjPos = { 500,300 };
POINT g_ptObjScale = { 100,100 };

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	// TODO: 여기에 코드를 입력합니다.


	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPICLASS, szWindowClass, MAX_LOADSTRING);
	srand((unsigned int)time(NULL));

	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPICLASS));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		// msg.message == WM_QUIT
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPICLASS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPICLASS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
int Resolutionx = GetSystemMetrics(SM_CXSCREEN);
int Resolutiony = GetSystemMetrics(SM_CYSCREEN);
int winposx = Resolutionx / 2 - WINSIZEX / 2;
int winposy = Resolutiony / 2 - WINSIZEY / 2;
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(
		szWindowClass
		, szTitle
		, WS_OVERLAPPEDWINDOW
		, winposx
		, winposy
		, WINSIZEX
		, WINSIZEY
		, nullptr
		, nullptr
		, hInstance
		, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static POINT pos;
	static SIZE size;
	switch (message)
	{
	case WM_CREATE:
		pos = { 1,1 };
		size = { WINSIZEX / 16 / 4, WINSIZEY / 9 / 4 };

		break;
	case WM_KEYDOWN:
	{
		switch(wParam)
		{
		case VK_UP:
			if (pos.y <= 0)
			{
				pos.y = 8;
				break;
			}
			pos.y--;
			break;
		case VK_LEFT:
			if (pos.x <= 0)
			{
				pos.x = 15;
				break;
			}

				pos.x--;
			break;
		case VK_DOWN:
			if (pos.y >= 8)
			{
				pos.y = 0;
				break;
			}
				pos.y++;
			break;
		case VK_RIGHT:
			if (pos.x >= 15)
			{
				pos.x = 0;
				break;
			}

				pos.x++;
			break;
		}

		InvalidateRect(hWnd, nullptr, true);
	}
	break;

	case WM_PAINT: // 무효화 영역(invalidate)이 발생한 경우
	{

		PAINTSTRUCT ps;

		// DC(Device Context): 그리기 위해 필요한 데이터 집합체
		HDC hdc = BeginPaint(hWnd, &ps);

		POINT point = pos;
		point.x = pos.x * (WINSIZEX / 16) + ((WINSIZEX / 16) / 2);
		point.y = pos.y* (WINSIZEY / 9) + ((WINSIZEY / 9) / 2);

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, brush);

		Rectangle(hdc, point.x - size.cx, point.y - size.cy, point.x + size.cx, point.y + size.cy);

		RECT rt = { winposx, winposy, winposx + WINSIZEX, winposy + WINSIZEY };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
		MoveWindow(hWnd, winposx,winposy,rt.right - rt.left, rt.bottom - rt.top, true);

		for (int i = 0; i < 10; ++i)
		{
			MoveToEx(hdc, 0, i * WINSIZEY / 9, NULL);
			LineTo(hdc, WINSIZEX, i * WINSIZEY / 9);
		}
		// 세로줄
		for (int j = 0; j < 17; ++j)
		{
			MoveToEx(hdc, j * WINSIZEX / 16, 0, NULL);
			LineTo(hdc, j * WINSIZEX / 16, WINSIZEY);
		}


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}