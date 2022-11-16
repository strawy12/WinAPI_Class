#pragma once
class BWindow
{
public:
	BWindow();
	~BWindow();

public:
	int							Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow);

protected:
	ATOM						MyRegisterClass();
	//BOOL                InitInstance(HINSTANCE, int);
	void						WindowCreate();
	void						WindowShow(int nCmdShow);
	void						WindowUpdate();
	int							MessageLoop();
	static LRESULT CALLBACK		WndProc(HWND, UINT, WPARAM, LPARAM);

protected:
	HWND						_hWnd = nullptr;
	HINSTANCE					_hInst = nullptr;
};

