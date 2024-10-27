#include <windows.h>
#include <cmath>
#include <time.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;

COLORREF COLORHSL(int length) {
    double h = fmod(length, 360.0);
    double s = 1.0;
    double l = 0.5;

    double c = (1.0 - fabs(2.0 * l - 1.0)) * s;
    double x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
    double m = l - c / 2.0;

    double r1, g1, b1;
    if (h < 60) {
        r1 = c;
        g1 = x;
        b1 = 0;
    }
    else if (h < 120) {
        r1 = x;
        g1 = c;
        b1 = 0;
    }
    else if (h < 180) {
        r1 = 0;
        g1 = c;
        b1 = x;
    }
    else if (h < 240) {
        r1 = 0;
        g1 = x;
        b1 = c;
    }
    else if (h < 300) {
        r1 = x;
        g1 = 0;
        b1 = c;
    }
    else {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    int red = static_cast<int>((r1 + m) * 255);
    int green = static_cast<int>((g1 + m) * 255);
    int blue = static_cast<int>((b1 + m) * 255);

    return RGB(red, green, blue);
}
typedef union COLOR {
    COLORREF rgb;
    struct {
        BYTE orange;
        BYTE yellow;
        BYTE blue;
    };
} COLOR;
typedef struct
{
	FLOAT h;
	FLOAT s;
	FLOAT l;
} HSL;

namespace Colors
{
	//These HSL functions was made by Wipet, credits to him! :D
	//OBS: I used it in 3 payloads

	//Btw ArTicZera created HSV functions, but it sucks. Mid. 
	//So I didn't used in this malware.

	HSL rgb2hsl(RGBQUAD rgb)
	{
		HSL hsl;

		BYTE r = rgb.rgbRed;
		BYTE g = rgb.rgbGreen;
		BYTE b = rgb.rgbBlue;

		FLOAT _r = (FLOAT)r / 255.f;
		FLOAT _g = (FLOAT)g / 255.f;
		FLOAT _b = (FLOAT)b / 255.f;

		FLOAT rgbMin = min(min(_r, _g), _b);
		FLOAT rgbMax = max(max(_r, _g), _b);

		FLOAT fDelta = rgbMax - rgbMin;
		FLOAT deltaR;
		FLOAT deltaG;
		FLOAT deltaB;

		FLOAT h = 0.f;
		FLOAT s = 0.f;
		FLOAT l = (FLOAT)((rgbMax + rgbMin) / 2.f);

		if (fDelta != 0.f)
		{
			s = l < .5f ? (FLOAT)(fDelta / (rgbMax + rgbMin)) : (FLOAT)(fDelta / (2.f - rgbMax - rgbMin));
			deltaR = (FLOAT)(((rgbMax - _r) / 6.f + (fDelta / 2.f)) / fDelta);
			deltaG = (FLOAT)(((rgbMax - _g) / 6.f + (fDelta / 2.f)) / fDelta);
			deltaB = (FLOAT)(((rgbMax - _b) / 6.f + (fDelta / 2.f)) / fDelta);

			if (_r == rgbMax)      h = deltaB - deltaG;
			else if (_g == rgbMax) h = (1.f / 3.f) + deltaR - deltaB;
			else if (_b == rgbMax) h = (2.f / 3.f) + deltaG - deltaR;
			if (h < 0.f)           h += 1.f;
			if (h > 1.f)           h -= 1.f;
		}

		hsl.h = h;
		hsl.s = s;
		hsl.l = l;
		return hsl;
	}

	RGBQUAD hsl2rgb(HSL hsl)
	{
		RGBQUAD rgb;

		FLOAT r = hsl.l;
		FLOAT g = hsl.l;
		FLOAT b = hsl.l;

		FLOAT h = hsl.h;
		FLOAT sl = hsl.s;
		FLOAT l = hsl.l;
		FLOAT v = (l <= .5f) ? (l * (1.f + sl)) : (l + sl - l * sl);

		FLOAT m;
		FLOAT sv;
		FLOAT fract;
		FLOAT vsf;
		FLOAT mid1;
		FLOAT mid2;

		INT sextant;

		if (v > 0.f)
		{
			m = l + l - v;
			sv = (v - m) / v;
			h *= 6.f;
			sextant = (INT)h;
			fract = h - sextant;
			vsf = v * sv * fract;
			mid1 = m + vsf;
			mid2 = v - vsf;

			switch (sextant)
			{
			case 0:
				r = v;
				g = mid1;
				b = m;
				break;
			case 1:
				r = mid2;
				g = v;
				b = m;
				break;
			case 2:
				r = m;
				g = v;
				b = mid1;
				break;
			case 3:
				r = m;
				g = mid2;
				b = v;
				break;
			case 4:
				r = mid1;
				g = m;
				b = v;
				break;
			case 5:
				r = v;
				g = m;
				b = mid2;
				break;
			}
		}

		rgb.rgbRed = (BYTE)(r * 255.f);
		rgb.rgbGreen = (BYTE)(g * 255.f);
		rgb.rgbBlue = (BYTE)(b * 255.f);

		return rgb;
	}
}

DWORD WINAPI shader1(LPVOID lpParam) {
    HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
    INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
    SelectObject(hdcMem, hbmTemp);
    for (;;) {
        hdcScreen = GetDC(0);
        BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
        for (INT i = 0; i < w * h; i++) {
            INT x = i + w, y = i * w;
            rgbScreen[i].rgb += x - y * y + x;
        }
        BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
        ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
    }
}

DWORD WINAPI train(LPVOID lpParam) // Credits to N17Pro3426 for the train effect ;)
{
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1)
    {
        HDC hdc = GetDC(0);
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 30, SRCCOPY);
    BitBlt(hdc, 0, 0, w, h, hdc, 0, -h + 30, SRCCOPY);
        ReleaseDC(0, hdc);
        Sleep(10);
    }
} 

DWORD WINAPI shader2(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCERASE);
		for (INT i = 0; i < w * h; i++) {
			INT x = i % w, y = i / w;
			//rgbScreen[i].g = x + y >> i;
			double fractalX = (2.5f / w);
			double fractalY = (1.90f / h);

			double cx = x * fractalX - 2.f;
			double cy = y * fractalY - 0.95f;

			double zx = 0;
			double zy = 0;

			int fx = 0;

			while (((zx * zx) + (zy * zy)) < 10 && fx < 50)
			{
				double fczx = zx * zx - zy * zy + cx;
				double fczy = 2 * zx * zy + cy;

				zx = fczx;
				zy = fczy;
				fx++;


				rgbScreen[i].b = fx;
				rgbScreen[i].rgb += 255;
			}
			//rgbScreen[i].rgb += x * y ^ i;
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
	}
}

DWORD WINAPI shader3(LPVOID lpvd) //credits to fr4ctalz.
{
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = screenWidth;
	bmpi.bmiHeader.biHeight = screenHeight;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;


	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcCopy, bmp);

	INT i = 0;

	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				int index = y * screenWidth + x;
				int Xii = x * x + i;
				int Yii = y * y + i;
				int fx = (int)((i ^ 4) + (i * 4) * cbrt(Xii - i | Yii - i));

				rgbquadCopy = rgbquad[index];

				hslcolor = Colors::rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

				rgbquad[index] = Colors::hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 1, 0, screenWidth, screenHeight, NOTSRCERASE);
		ReleaseDC(NULL, hdc);
		DeleteDC(hdc);
	}

	return 0x00;
}


DWORD WINAPI shader4(LPVOID lpvd) //credits to fr4ctalz.
{
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = screenWidth;
	bmpi.bmiHeader.biHeight = screenHeight;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;


	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcCopy, bmp);

	INT i = 0;
	float colorShift = 400.0;
	float colorIntensity = 0.15;
	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				int index = y * screenWidth + x;
				int Xii = x * x + i;
				int Yii = y * y + i;
				int fx = (int)((i ^ 4) + (i * 4) * cbrt((Xii - i) * (Yii - i)));

				rgbquadCopy = rgbquad[index];

				hslcolor = Colors::rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / colorShift + y / static_cast<float>(screenHeight) * colorIntensity, 1.0f);
				hslcolor.s = fmod(hslcolor.s + (x % 20) / 200.0f, 1.0f);
				hslcolor.l = fmod(hslcolor.l + (y % 10) / 100.0f, 1.0f);
				rgbquad[index] = Colors::hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCERASE);
		ReleaseDC(NULL, hdc);
		DeleteDC(hdc);
	}

	return 0x00;
}

DWORD WINAPI shader5(LPVOID lpParam) { //credits to N17Pro3426 but i modded it
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); int r = 2, g = 1, b = 4, power = 22;
	HDC hdc, hdcMem; HBITMAP hbm;
	for (int i = 0;; i++, i %= 3) {
		hdc = GetDC(0); hdcMem = CreateCompatibleDC(hdc); hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcMem, hbm);
		BitBlt(hdcMem, 0, 0, w, h, hdc, 0, 0, SRCPAINT); GetBitmapBits(hbm, w * h * 4, data);
		for (int i = 0; w * h > i; i++) {
			int v = 1 + rand() % 13;
			((BYTE*)(data + i))[r] = ((BYTE*)(data + i + v + power))[r] + 5.2;
			((BYTE*)(data + i))[g] = ((BYTE*)(data + i + v + power))[g] + 5.2;
			((BYTE*)(data + i))[b] = ((BYTE*)(data + i + v + power))[b] + 5.2;
		}
		SetBitmapBits(hbm, w * h * 4, data); BitBlt(hdc, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		DeleteObject(hbm); DeleteObject(hdcMem);
		DeleteObject(hdc);
	}
}

DWORD WINAPI icon(LPVOID lpParam) {
	//POINT cursor;
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	int xf = 0;
	int yf = 0;
	int signX = 15;
	int signY = 5;
	int signX1 = 1;
	int signY1 = 1;
	int incrementor = 10;
	int radius = 100.0f;
	double angle = 0;
	int x, y;
	int centerX, centerY;
	int origX = (w / 4) - (radius / 2), origY = (h / 4) - (radius / 2);
	while (1) {
		HDC hdc = GetDC(HWND_DESKTOP);
		xf += signX;
		yf += signY;
		centerX = origX - (w / 4), centerY = origY - (h / 4);
		x = (cos(angle) * radius) + centerX, y = (sin(angle) * radius) + centerY;
		int icon_x = GetSystemMetrics(SM_CXICON);
		int icon_y = GetSystemMetrics(SM_CYICON);
		//GetCursorPos(&cursor);
		//int X = cursor.x + rand() % 3 - 1;
		//int Y = cursor.y + rand() % 3 - 1;
		//int top_x = 0 + cursor.x;
		//int top_y = 0 + cursor.y;
		//int size = rand() % 900 +100;
		//int bottom_x = 300 + cursor.x;
		//int bottom_y = 300 + cursor.y;

		for (INT i = 64; i > 8; i -= 8) {
			//SetCursorPos(50 + x - i + xf, 50 + y - i + yf);
			DrawIconEx(hdc, (50 + x - i + xf) - icon_x, (50 + y - i + yf) - icon_y, LoadIcon(0, IDI_WARNING), 5 * GetSystemMetrics(SM_CXICON), 5 * GetSystemMetrics(SM_CYICON), 0, NULL, DI_NORMAL);
			//DrawIcon(hdc, 50 + x - i + xf - icon_x, 50 + y - i + yf - icon_y, LoadIcon(0, IDI_QUESTION));
		}
		angle = fmod(angle + M_PI / radius, M_PI * radius);

		if (yf == 0)
		{
			signY = 5;
		}

		if (xf == 0)
		{
			signX = 15;
		}

		if (yf >= GetSystemMetrics(1))
		{
			signY -= 5;
		}

		if (xf >= GetSystemMetrics(0))
		{
			signX -= 15;
		}
		ReleaseDC(0, hdc);
		Sleep(10);
	}
	return(1);
}
DWORD WINAPI shader6 (LPVOID lpvd) //credits to fr4ctalz for the base
{
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = screenWidth;
	bmpi.bmiHeader.biHeight = screenHeight;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;


	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcCopy, bmp);

	INT i = 0;

	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				int index = y * screenWidth + x;

				int fx = (int)((i ^ 4) + (i * 4) * log2(x ^ x | x * i * y));

				rgbquadCopy = rgbquad[index];

				hslcolor = Colors::rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

				rgbquad[index] = Colors::hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, NOTSRCERASE);
		ReleaseDC(NULL, hdc);
		DeleteDC(hdc);
	}

	return 0x00;
}

DWORD WINAPI train2(LPVOID lpParam) // Credits to N17Pro3426 for the train effect but i modded it ;)
{
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1)
    {
        HDC hdc = GetDC(0);
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 30, NOTSRCCOPY);
    BitBlt(hdc, 0, 0, w, h, hdc, 0, -h + 30, SRCCOPY);
        ReleaseDC(0, hdc);
        Sleep(10);
    }
} 

DWORD WINAPI shader7(LPVOID lpvd) { //credits to soheil shahrab.
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;
	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = screenWidth;
	bmpi.bmiHeader.biHeight = screenHeight;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;
	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;
	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcCopy, bmp);
	INT i = 0;
	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);
		RGBQUAD rgbquadCopy;

		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				int index = y * screenWidth + x;
				FLOAT fx = (x | y) + (i + i * 10);

				rgbquadCopy = rgbquad[index];

				hslcolor = Colors::rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 400.f + y / screenHeight * .10f, 1.f);

				rgbquad[index] = Colors::hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCINVERT);
		ReleaseDC(NULL, hdc);
		DeleteDC(hdc);
	}

	return 0x00;
}

DWORD WINAPI textout(LPVOID lpParam) {
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
	int signY = 1;
	int signX1 = 1;
	int signY1 = 1;
	int incrementor = 10;
	int x = 10;
	int y = 10;
	LPCSTR lpText = "VenraTech";
	while (1) {
		HDC hdc = GetDC(0);
		x += incrementor * signX;
		y += incrementor * signY;
		int top_x = 0 + x;
		int top_y = 0 + y;
		SetBkMode(hdc, 0);
		SetTextColor(hdc, (239));
		SetBkColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		HFONT font = CreateFontA(43, 32, rand() % 3600, rand() % 3600, FW_EXTRALIGHT, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Comic Sans MS");
		SelectObject(hdc, font);
		TextOutA(hdc, top_x, top_y, lpText, strlen(lpText));
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
		Sleep(4);
		DeleteObject(font);
		ReleaseDC(0, hdc);
	}
}


int main () 
{
	if (MessageBoxA(NULL, "I have expected this.\n\nYou clicked on this program because you are dumb. Anyways.\n\nYou are attempting to run a copy of a Trojan.Win32.Generic.\n\nClick yes to continue.\r\nClick no to exit.", "2XMM J083026+524133.exe", MB_YESNO | MB_ICONWARNING) == IDNO)
	{
		return 0;
	}
	else
	{
		if (MessageBoxA(NULL, "Man. You really are dumb. I must remind you that malware is not a toy and can cause serious harm to your device. This is one of them.\n\nClick yes to continue.\r\nClick no to exit.", "2XMM J083026+524133.exe", MB_YESNO | MB_ICONWARNING) == IDNO)
		{
			return 0;
		}
		else
		{
		

	HANDLE a = CreateThread(0, 0, shader1, 0, 0, 0);
    HANDLE b = CreateThread(0, 0, train, 0, 0, 0);
    Sleep(40000);
    TerminateThread(a, 0);
    TerminateThread(b, 0);
    CloseHandle(a);
    InvalidateRect(0, 0, 0);
    CloseHandle(b);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    HANDLE c = CreateThread(0, 0, shader2, 0, 0, 0);
	Sleep(50000);
    TerminateThread(c, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(c);
    InvalidateRect(0, 0, 0);
	Sleep(1000);
    HANDLE d = CreateThread(0, 0, shader3, 0, 0, 0);
	Sleep(40000);
    TerminateThread(d, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(d);
    InvalidateRect(0, 0, 0);
    HANDLE e = CreateThread(0, 0, shader4, 0, 0, 0);
	Sleep(30000);
    TerminateThread(e, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(e);
    InvalidateRect(0, 0, 0);
    HANDLE f = CreateThread(0, 0, shader5, 0, 0, 0);
	Sleep(30000);
    TerminateThread(f, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(f);
    InvalidateRect(0, 0, 0);
	HANDLE g = CreateThread(0, 0, icon, 0, 0, 0);
    HANDLE h = CreateThread(0, 0, shader6, 0, 0, 0);
    Sleep(40000);
    TerminateThread(h, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(h);
    InvalidateRect(0, 0, 0);
    HANDLE i = CreateThread(0, 0, train2, 0, 0, 0);
    Sleep(20000);
    TerminateThread(i, 0);
    InvalidateRect(0, 0, 0);
    CloseHandle(i);
    InvalidateRect(0, 0, 0);
    HANDLE j = CreateThread(0, 0, shader7, 0, 0, 0);
    HANDLE k = CreateThread(0, 0, textout, 0, 0, 0);
    Sleep(40000);
    TerminateThread(a, 0);
    TerminateThread(b, 0);
    CloseHandle(j);
    InvalidateRect(0, 0, 0);
    CloseHandle(k);
    InvalidateRect(0, 0, 0);
	Sleep(1000);
}}}
