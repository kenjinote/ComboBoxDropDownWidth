#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>

TCHAR szClassName[] = TEXT("Window");

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hComboBox;
	switch (msg)
	{
	case WM_CREATE:
		hComboBox = CreateWindow(TEXT("COMBOBOX"), 0, WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST, 0, 0, 0, 0, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("aaa"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("bbb"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("ccc"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("ddd"));
		SendMessage(hComboBox, CB_SETCURSEL, 0, 0);
		SendMessage(hComboBox, CB_SETDROPPEDWIDTH, 512, 0);
		break;
	case WM_SIZE:
		MoveWindow(hComboBox, 10, 10, 256, 32, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wndclass = {
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		0,
		LoadCursor(0,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		0,
		szClassName
	};
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(
		szClassName,
		TEXT("コンボボックスのドロップダウンリストの幅を設定する"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		0,
		0,
		hInstance,
		0
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
