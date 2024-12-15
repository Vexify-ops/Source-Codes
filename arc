#include <windows.h>
#pragma comment(lib, "winmm.lib")
#define _USE_MATH_DEFINES 1
#include <cmath>
#define M_PI 3.14159265358979323846264338327950288

int red = 0, green = 0, blue = 0;
bool ifcolorblue = false, ifblue = false;

COLORREF Hue(int length) {
    if (red != length) {
        red++;
        if (ifblue == true) {
            return RGB(red, 0, length);
        } else {
            return RGB(red, 0, 0);
        }
    } else {
        if (green != length) {
            green++;
            return RGB(length, green, 0);
        } else {
            if (blue != length) {
                blue++;
                return RGB(0, length, blue);
            } else {
                red = 0; green = 0; blue = 0;
                ifblue = true;
            }
        }
    }
}

int main()
{
    HDC hdc;
    HPEN hp;
    POINT cursorPos;
    int incrementation = 5;
    
    while (1) {
        // Get current cursor position
        GetCursorPos(&cursorPos);

        // Get the device context for the screen
        hdc = GetDC(NULL);

        // Create a pen with random color
        hp = CreatePen(PS_SOLID, 10, Hue(239));
        SelectObject(hdc, hp);

        // Draw an arc that follows the cursor position
        Arc(hdc, 
            cursorPos.x - 100, cursorPos.y - 100, // Bounding rectangle start
            cursorPos.x + 100, cursorPos.y + 100, // Bounding rectangle end
            cursorPos.x + 100, cursorPos.y + 100, // Arc's starting point
            cursorPos.x + 100, cursorPos.y + 100  // Arc's ending point
        );

        // Clean up resources
        DeleteObject(hp);
        ReleaseDC(NULL, hdc);

        // Sleep to allow smooth movement
        Sleep(10);
    }

    return 0;
}
