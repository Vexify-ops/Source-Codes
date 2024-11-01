#include <windows.h>
#include <cmath>
#include "main.h"

DWORD fakeerror() {
	MessageBoxW(NULL, L"Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.", L"Windows - Virtual Minimum Memory Too Low", MB_OK | 16);
	return 0;
}

DWORD fakeerror2() {
	MessageBoxW(NULL, L"USIOIJAJA", L"tabby", MB_OK | 32);
	return 0;
}

DWORD fakeerror3() {
	MessageBoxW(NULL, L"345676543", L"tabby", MB_OK | 32);
}

DWORD WINAPI msg(LPVOID lpParam)
{
	while (1) {
		MessageBoxW(NULL, L"QWERTYUIOPASDFGHJKLZXCVBNM", L"tabby", 0 | 32);
		MessageBoxW(NULL, L"QWERTYUIOPASDFGHJKLZXCVBNM", L"tabby", 1 | 32);
		MessageBoxW(NULL, L"MNBVCXZLKJHGFDSAPOIUYTREWQ", L"tabby", 2 | 32 | MB_RTLREADING);
		MessageBoxW(NULL, L"MNBVCXZLKJHGFDSAPOIUYTREWQ", L"tabby", 3 | 32 | MB_RTLREADING);
		MessageBoxW(NULL, L"QWERTYUIOPASDFGHJKLZXCVBNM", L"tabby", 4 | 32);
		MessageBoxW(NULL, L"QWERTYUIOPASDFGHJKLZXCVBNM", L"tabby", 5 | 32);
	}
	return 0;
}

DWORD WINAPI infodraw(LPVOID lpParam)
{
	while(1){
		HDC hdc = GetDC(HWND_DESKTOP);
		int icon_x = GetSystemMetrics(SM_CXICON);
		int icon_y = GetSystemMetrics(SM_CYICON) ;
		POINT cursor;
        GetCursorPos(&cursor);
        DrawIcon(hdc, cursor.x - icon_x, cursor.y - icon_y, LoadIcon(NULL, IDI_ASTERISK));
        ReleaseDC(0, hdc);
	}
}

DWORD WINAPI paste(LPVOID lpParam)
{
	HDC hdc = GetDC(HWND_DESKTOP);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	
	while (TRUE)
	{
		HDC hdc = GetDC(HWND_DESKTOP);
		int X = GetSystemMetrics(SM_CXSCREEN);
		int Y = GetSystemMetrics(SM_CYSCREEN);
		BitBlt(hdc, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), hdc, rand() % (X - 0), rand() % (Y - 0), NOTSRCCOPY);
		Sleep(10);
	}
}

DWORD WINAPI zoomout(LPVOID lpParam)
{
	int sw, sh;
	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(hdc, 20, 20, sw - 40, sh - 40, hdc, 0, 0, sw, sh, SRCCOPY);
		ReleaseDC(0, hdc);
		Sleep(4);
	}
}

VOID WINAPI sfx1() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>((t&t>>6)+(t|t>>7)+(t|t>>8)+(t|t>>9)&t>>6);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

DWORD WINAPI glitch(LPVOID lpParam)
{
    int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
    double moveangle = 0;
    while (1) {
        HDC hdc = GetDC(0);
        SelectObject(hdc, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        int rx = rand() % sw;
        int ry = rand() % sh;
        BitBlt(hdc, 10, ry, sw, 96, hdc, 0, ry, SRCCOPY);
        BitBlt(hdc, -10, ry, sw, -96, hdc, 0, ry, SRCCOPY);
        ReleaseDC(0, hdc);
        Sleep(10);
    }
}

DWORD WINAPI wefc(LPVOID lpParam)
{
    RECT rect;
    GetWindowRect(GetDesktopWindow(), &rect);
    int w = rect.right - rect.left - 500, h = rect.bottom - rect.top - 500;
    for (int t = 0;; t++)
    {
        const int size = 1000;
        int x = rand()%(w+size)-size/2, y = rand()%(h+size)-size/2;
        for (int i = 0; i < size; i+=100)
        {
            ci(x-i/2, y-i/2, i, i);
            Sleep(10);
        }
    }
}

DWORD WINAPI rgbquad(LPVOID lpParam)
{
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = rand()%0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h && rand() % 110)
                v = rand() % 100;
            *((BYTE*)data + 4 * i + v) -= 5;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
} 

VOID WINAPI sfx2() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 16000, 16000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[16000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t*(t>>10&t>>6&t>>5));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

VOID WINAPI sfx3() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t*(3+(1^t>>10&5))*(5+(1&t>>14))>>(t>>9&3)|t>>4);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

DWORD WINAPI hues(LPVOID lpParam)
{
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    _RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        for (int i = 0; w * h > i; i++) {
            data[i].rgb = (data[i].rgb * 2) % (RGB(255, 255, 255));
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
}

DWORD WINAPI notcopytrain(LPVOID lpParam)
{
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        HDC hdc = GetDC(0);
        BitBlt(hdc, 0, 0, w, h, hdc, 30, 0, SRCCOPY);
        BitBlt(hdc, 0, 30, w, h, hdc, w - 30, 0, NOTSRCCOPY);
        ReleaseDC(0, hdc);
        Sleep(10);
    }
}

VOID WINAPI sfx4() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[22050 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t+((t>>(t&8192?3:2)>>2|t)&t>>10));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

DWORD WINAPI vertrays(LPVOID lpParam)
{
	HDC desk;
	int sw, sh;
	while(1){
		desk = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(desk, 0, -20, sw, sh+40, desk, 0, 0, sw, sh, SRCPAINT);
		ReleaseDC(0, desk);
		Sleep(4);
	}
}

DWORD WINAPI square(LPVOID lpParam)
{
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
    int signY = 1;
    int signX1 = 1;
    int signY1 = 1;
    int incrementor = 10;
    int x = 10;
    int y = 10;
	while(1){
		HDC hdc = GetDC(0);
        x += incrementor * signX;
        y += incrementor * signY;
		int top_x = 0 + x;
        int top_y = 0 + y;
        int bottom_x = 100 + x;
        int bottom_y = 100 + y; 
    	HBRUSH brush = CreateSolidBrush(Hue(239));
    	SelectObject(hdc, brush);
		Rectangle(hdc, top_x, top_y, bottom_x, bottom_y);
        if (y >= GetSystemMetrics(SM_CYSCREEN))
        {
                signY = -1;
        }
        if (x >= GetSystemMetrics(SM_CXSCREEN))
        {
            signX = -1;
        }
        if (y == 0)
        {
            signY = 1;
        }
        if (x == 0)
        {
            signX = 1;
        }
        Sleep(10);
    	DeleteObject(brush);
        ReleaseDC(0, hdc);
	}
}

VOID WINAPI sfx5() {
	PlaySoundW(L"sfx5.wav", NULL, SND_FILENAME | SND_ASYNC);
}

DWORD WINAPI whirl(LPVOID lpParam)
{
    HDC desk = GetDC(0);
    int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN), xSize = sh/10, ySize = 9;
    while (1) {
    	HDC desk = GetDC(0);
        for (int i = 0; i < sh*2; i++) {
            int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
            BitBlt(desk, i, 0, 1, sh, desk, i, wave, SRCCOPY);
        }
        for (int i = 0; i < sw*2; i++) {
            int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
            BitBlt(desk, 0, i, sw, 1, desk, wave, i, SRCCOPY);
        }
    }
}

DWORD WINAPI pie(LPVOID lpParam)
{
	while(1){
		HDC hdc = GetDC(0);
		int x = GetSystemMetrics(0);
		int y = GetSystemMetrics(1);
		HBRUSH brush = CreateSolidBrush(Hue(239));
		SelectObject(hdc, brush);
		Pie(hdc, rand() % x, rand() % y, rand() % x, rand() % y, rand() % x, rand() % y, rand() % x, rand() % y);
    	DeleteObject(brush);
    	ReleaseDC(NULL, hdc);
    	Sleep(10);
	}
}

VOID WINAPI sfx6() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t>>6|t*t*(t>>6&8^8)*(t>>11^t/3>>12)/(7+(t>>10&t>>14&3)));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

DWORD WINAPI cube(LPVOID lpParam)
{
	while(1){
		HDC hdc = GetDC(0);
    	int x = GetSystemMetrics(0);
    	int y = GetSystemMetrics(1);
    	StretchBlt(hdc, -10, -10, x + 20, y + 20, hdc, 0, 0, x, y, SRCCOPY);
    	StretchBlt(hdc, 10, 10, x - 20, y - 20, hdc, 0, 0, x, y, SRCCOPY);
    	ReleaseDC(0, hdc);
	}
}

DWORD WINAPI invert(LPVOID lpParam)
{
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	while(1)
	{
		hdc = GetDC(0);
		PatBlt(hdc, 0, 0, x, y, PATINVERT);
		Sleep(10);
	        ReleaseDC(0, hdc);
	}
}

VOID WINAPI sfx7() {
	HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t*(0xCA98>>(-t>>9&14)&15)|t>>8);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

VOID WINAPI destroy(HANDLE h){
	TerminateThread(h, 0);
	CloseHandle(h);
}


int main() {
	if (MessageBoxW(NULL, L"Run?", L"tabby", MB_YESNO | 48 | MB_DEFBUTTON2) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"Are you sure?", L"tabby 1/3", MB_YESNO | 48 | MB_RTLREADING | MB_DEFBUTTON2) == IDNO)
		{
			ExitProcess(0);
		}
		else
		{
			if (MessageBoxW(NULL, L"Are you sure?", L"tabby 2/3", MB_YESNO | 48 | MB_DEFBUTTON2) == IDNO)
			{
				ExitProcess(0);
			}
			else
			{
				if (MessageBoxW(NULL, L"Are you sure?", L"tabby 3/3", MB_YESNO | 48 | MB_RTLREADING | MB_DEFBUTTON2) == IDNO)
				{
					ExitProcess(0);
				}
				else
				{
					Sleep(4000);
					CreateThread(0, 0, (LPTHREAD_START_ROUTINE)fakeerror, 0, 0, 0);
					Sleep(3000);
					CreateThread(0, 0, (LPTHREAD_START_ROUTINE)fakeerror2, 0, 0, 0);
					Sleep(2000);
					CreateThread(0, 0, (LPTHREAD_START_ROUTINE)fakeerror3, 0, 0, 0); //Zen.exe reference
					Sleep(2000);
					CreateThread(0, 0, msg, 0, 0, 0);
					Sleep(3000);
					CreateThread(0, 0, infodraw, 0, 0, 0);
					Sleep(5000);
					HANDLE a = CreateThread(0, 0, paste, 0, 0, 0);
					HANDLE b = CreateThread(0, 0, zoomout, 0, 0, 0);
					sfx1();
					Sleep(30000);
					destroy(a);
					destroy(b);
					InvalidateRect(0, 0, 0);
					Sleep(1000);
					HANDLE c = CreateThread(0, 0, glitch, 0, 0, 0);
					sfx2();
					Sleep(30000);
					destroy(c);
					InvalidateRect(0, 0, 0);
					HANDLE d = CreateThread(0, 0, wefc, 0, 0, 0);
					HANDLE dd = CreateThread(0, 0, rgbquad, 0, 0, 0);
					sfx3();
					Sleep(30000);
					destroy(d);
					destroy(dd);
					InvalidateRect(0, 0, 0);
					Sleep(1000);
					HANDLE e = CreateThread(0, 0, hues, 0, 0, 0);
					HANDLE ee = CreateThread(0, 0, notcopytrain, 0, 0, 0);
					sfx4();
					Sleep(30000);
					destroy(e);
					destroy(ee);
					InvalidateRect(0, 0, 0);
					Sleep(1000);
					HANDLE f = CreateThread(0, 0, vertrays, 0, 0, 0);
					HANDLE ff = CreateThread(0, 0, square, 0, 0, 0);
					sfx5();
					Sleep(30000);
					destroy(f);
					destroy(ff);
					InvalidateRect(0, 0, 0);
					Sleep(1000);
					HANDLE g = CreateThread(0, 0, whirl, 0, 0, 0);
					HANDLE gg = CreateThread(0, 0, pie, 0, 0, 0);
					sfx6();
					Sleep(30000);
					destroy(g);
					destroy(gg);
					InvalidateRect(0, 0, 0);
					Sleep(1000);
					HANDLE h = CreateThread(0, 0, cube, 0, 0, 0);
					HANDLE hh = CreateThread(0, 0, invert, 0, 0, 0);
					sfx7();
					Sleep(30000);
					destroy(h);
					destroy(hh);
					InvalidateRect(0, 0, 0);
					ExitProcess(0);
				}
			}
		}
	}
}
