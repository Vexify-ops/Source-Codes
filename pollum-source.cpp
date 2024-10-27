#include <windows.h>
#include <cmath>
#define ERROR (HICON)LoadIcon(NULL, IDI_ERROR)
#define RANDOM (COLORREF)RGB(rand () % 255, rand () % 255, rand () % 255)

VOID WINAPI Kill(HANDLE hThread) {
	TerminateThread(hThread, 0);
	CloseHandle(hThread);
}

VOID WINAPI Refresh(HWND hwnd) {
	InvalidateRect(hwnd, 0, 0);
	Sleep(1000);
}

DWORD WINAPI BitBltsin1(LPVOID lbit)
{
  int cx;
  int cy;
  HDC hdc;
  int an;
  double angle;
  int a;
  
  cx = GetSystemMetrics(0);
  cy = GetSystemMetrics(1);
  while (1) {
    hdc = GetDC(NULL);
    for (a = 0; a < cx * 2; a++) {
      angle = sin(((double)a / (cy / 10)) * M_PI);
      BitBlt(hdc,0,a,cx,1,hdc,(angle * 9.0),a,SRCCOPY);
    }
    an = rand() % 100 + 1;
    if (an == (an / 67) * 67) {
      InvalidateRect(0, 0, 0);
    }
    ReleaseDC(NULL, hdc);
  }
}

DWORD WINAPI PolyBezier1 (LPVOID poly)
{
  POINT PStack_34;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  HPEN pHStack_1c;
  HDC pHStack_18;
  int iStack_14;
  int iStack_10;
  
  iStack_10 = GetSystemMetrics(0);
  iStack_14 = GetSystemMetrics(1);
  do {
    pHStack_18 = GetDC((HWND)0x0);
    PStack_34.x = rand();
    PStack_34.x = PStack_34.x % iStack_10;
    PStack_34.y = rand();
    PStack_34.y = PStack_34.y % iStack_14;
    iStack_2c = rand();
    iStack_2c = iStack_2c % iStack_10;
    iStack_28 = rand();
    iStack_28 = iStack_28 % iStack_14;
    iStack_24 = rand();
    iStack_24 = iStack_24 % iStack_10;
    iStack_20 = rand();
    iStack_20 = iStack_20 % iStack_14;
    pHStack_1c = CreatePen(0,5,0xef);
    SelectObject(pHStack_18,pHStack_1c);
    PolyBezier(pHStack_18,&PStack_34,4);
    DeleteObject(pHStack_1c);
    ReleaseDC((HWND)0x0,pHStack_18);
    Sleep(4);
  } while( true );
}

DWORD WINAPI InvertRgn1(LPVOID lpi) // skidded from Phenylsilatrane
{
	HDC hdc = GetDC(0);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	while (1) {
		hdc = GetDC(0);
		int rand_num_x = rand() % sw;
		int rand_num_y = rand() % sh;

		int top_x = 0 + rand_num_x; // Top Left Corner
		int top_y = 0 + rand_num_y; // Top Right Corner

		int bottom_x = 100 + rand_num_x; // Bottom Left Corner
		int bottom_y = 100 + rand_num_y; // Bottom Right Corner
		HRGN circle = CreateEllipticRgn(top_x, top_y, bottom_x, bottom_y);
		InvertRgn(hdc, circle);
		DeleteObject(circle);
		ReleaseDC(0, hdc);
		Sleep(rand() % 25);
	}
}

DWORD WINAPI StretchBlt1(LPVOID ls)
{
	HDC hdc;
	int w, h;
	while (1) {
		hdc = GetDC(NULL);
		w = GetSystemMetrics(0), h = GetSystemMetrics(1);
		StretchBlt(hdc, 100, 100, w - 2, h - 2, hdc, 0, 0, w, h, SRCCOPY);
		DeleteObject(&w); DeleteObject(&h);
		ReleaseDC(NULL, hdc); DeleteDC(hdc);
		Sleep(10);
	}
}

DWORD WINAPI DrawIcon1(LPVOID lpd)
{
	HWND hWnd;
	HDC hdc;
	int x, y;
	while (1) {
		hWnd = GetDesktopWindow();
		hdc = GetWindowDC(hWnd);
		x  = GetSystemMetrics(0), y = GetSystemMetrics(1);
		DrawIcon(hdc, rand () % x, rand () % y, ERROR);
	    DeleteObject(&x); DeleteObject(&y);
		ReleaseDC(hWnd, hdc); DeleteDC(hdc);
		Sleep(10);
	}
}

DWORD WINAPI BitBlt1(LPVOID lbit)
{
	HDC hdc;
	int x, y;
	while (true) {
		hdc = GetDC(NULL);
		x = GetSystemMetrics(0), y = GetSystemMetrics(1);
		BitBlt(hdc, rand () % 2, rand () % 2, x, y, hdc, rand () % 2, rand () % 2, SRCCOPY);
		DeleteObject(&x); DeleteObject(&y);
		ReleaseDC(NULL, hdc); DeleteDC(hdc);
		Sleep(10);
	}
}

DWORD WINAPI TextOutW1(LPVOID ltxt)
{
	HDC hdc;
	int x, y;
	LPCWSTR text;
	while (1) {
		hdc = GetDC(NULL);
		x = GetSystemMetrics(0), y = GetSystemMetrics(1);
		SetTextColor(hdc, RANDOM);
		SetBkColor(hdc, RGB(0, 0, 0));
		text = L"L000000000000000000000000L";
		TextOutW(hdc, rand () % x, rand () % y, text, wcslen(text));
		DeleteObject(&x); DeleteObject(&y);
		ReleaseDC(NULL, hdc); DeleteDC(hdc);
		Sleep(10);
	}
}

int CALLBACK WinMain(HINSTANCE inst, HINSTANCE hpi, LPSTR lps, int n) {
	if (MessageBoxA(NULL, "WARNING!!\r\nYou have to execute a safety malware named Pollum.safety.exe\r\nPress yes to continue\r\nPress no to quit.\r\nif you dont want to not kill your system.\r\n\r\nCLOSE THIS MESSAGE AND DELETE THIS FILE, STILL EXECUTE IT?", "pollux.. then NOW POLLUM? (GDI only)", MB_YESNO | MB_ICONWARNING) == IDNO)
	{
		return 0;
	}
	else
	{
		if (MessageBoxA(NULL, "LAST WARNING!!!\r\n\r\nTHE AUTHOR IS NOT RESPONSIBLE FOR PHYSICAL DAMAGES!!\r\nSTII CONTINUE TO EXECUTE IT?", "OH NO MY PC!!!!", MB_YESNO | MB_ICONWARNING) == IDNO)
		{
			return 0;
		}
		else
		{
			// you asked for it
			Sleep(5000);
			HANDLE a = CreateThread(0, 0, BitBltsin1, 0, 0, 0);
			Sleep(25000);
			Kill(a);
			Refresh(0);
			HANDLE b = CreateThread(0, 0, PolyBezier1, 0, 0, 0);
			Sleep(30000);
			Kill(b);
			Refresh(0);
			HANDLE c = CreateThread(0, 0, InvertRgn1, 0, 0, 0);
			Sleep(30000);
			Kill(c);
			Refresh(0);
			HANDLE d = CreateThread(0, 0, StretchBlt1, 0, 0, 0);
			Sleep(30000);
			Kill(d);
			Refresh(0);
			HANDLE e = CreateThread(0, 0, DrawIcon1, 0, 0, 0);
			Sleep(30000);
			Kill(e);
			Refresh(0);
			HANDLE f = CreateThread(0, 0, BitBlt1, 0, 0, 0);
			HANDLE ff = CreateThread(0, 0, TextOutW1, 0, 0, 0);
			Sleep(30000);
		}
	}
}
