// WinAPI_Class.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WinAPI_Class.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];              // 제목 표시줄 텍스트입니다.
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
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
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

int x = GetSystemMetrics(SM_CXSCREEN) * 0.5f - WINSIZEX / 2;
int y = GetSystemMetrics(SM_CYSCREEN) * 0.5f - WINSIZEY / 2;

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		x, y, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static wchar_t str[100];
	static int count;
	static int yPos = 0;

	static SIZE size;
	PAINTSTRUCT ps;
	RECT rt = { 0,0,1000,1000 };

	switch (message)
	{
	case WM_CREATE:
		count = 0;
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);

		break;
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);


	}
	break;



	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
		{

		}
		break;

		}
	}
	break;
	case WM_KEYUP:
	{
		switch (wParam)
		{
		case VK_UP:
			break;

		}
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_CHAR:
	{
		if (wParam == VK_BACK && count > 0)
		{
			count--;
		}

		//else if (wParam == VK_RETURN)
		//{
		//	count = 0;
		//	yPos = yPos + 20;
		//}

		else
		{
			str[count++] = wParam;
		}

		str[count] = '\0';

		hdc = GetDC(hWnd);
		int x = rand() % WINSIZEX;
		int y = rand() % WINSIZEY;
		str[0] = wParam;
		TextOut(hdc, x, y, str, wcslen(str));

		InvalidateRect(hWnd, nullptr, false);
		ReleaseDC(hWnd, hdc);
	}
	break;

	case WM_PAINT:
	{
		HDC hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 100, 100, wstr.c_str(), wstr.length());

		/*RECT rt
		{ x,y ,x + WINSIZEX, y + WINSIZEY };

		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
		MoveWindow(hWnd, x, y, rt.right - rt.left, rt.bottom - rt.top, true);




		int h = 16;
		int v = 9;
		for (int i = 0; i < h; i++)
		{
			int posX = (WINSIZEX / h) * i;
			MoveToEx(hdc, posX, 0, nullptr);
			LineTo(hdc, posX, WINSIZEY);
		}

		for (int i = 0; i < v; i++)
		{
			int posY = (WINSIZEY / v) * i;
			MoveToEx(hdc, 0, posY, nullptr);
			LineTo(hdc, WINSIZEX, posY);
		}
*/
/*int startPosX = 100;
int size = 50;
int	dist = 20;
int xPos = 100, yPos = 100;
bool drawRectangle = true;

for (int i = 1; i <= 25; i++)
{
	if (drawRectangle)
	{
		Rectangle(hdc, xPos, yPos, xPos+ size, yPos+ size);
	}

	else
	{
		Ellipse(hdc, xPos, yPos, xPos + size, yPos + size);
	}

	if (i % 5 == 0)
	{
		xPos = startPosX;
		yPos += size + dist;
		drawRectangle = !drawRectangle;
	}
	else
	{
		xPos += size + dist;
	}


}*/
/*HPEN hRedPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
HPEN hOldPen = (HPEN)SelectObject(hdc, hRedPen);



HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);

int xPos = g_ptObjPos.x - g_ptObjScale.x / 2;
int yPos = g_ptObjPos.y - g_ptObjScale.y / 2;
Rectangle(hdc,
	xPos,
	yPos,
	xPos + g_ptObjScale.x,
	yPos + g_ptObjScale.y);

DeleteObject(hRedPen);
DeleteObject(hBlueBrush);*/
		GetTextExtentPoint(hdc, str, wcslen(str), &size);
		SetCaretPos(size.cx, 0);
		//TextOut(hdc, 0, yPos, str, wcslen(str));
		//DrawText(hdc, str, wcslen(str), &rt, DT_LEFT | DT_TOP);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		HideCaret(hWnd);
		DestroyCaret();
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
