// the calculator with a convenient and intuitive interface

#include <stdio.h>
#include <Windows.h>

#define BTN_NULL    10
#define BTN_ONE     11
#define BTN_TWO     12
#define BTN_THREE   13
#define BTN_FOUR    14
#define BTN_FIVE    15
#define BTN_SIX     16
#define BTN_SEVEN   17
#define BTN_EIGHT   18
#define BTN_NINE    19

#define BTN_EXIT    999
#define STC_RES     1000

RECT rct;

LRESULT WINAPI wndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        case WM_COMMAND:
        {
            switch (LOWORD(wparam))
            {
                case BTN_EXIT:
                {
                    printf("code: %d\t|\texit\n", LOWORD(wparam));
                    PostQuitMessage(0);
                    break;
                }
                case BTN_ONE:
                {
                    printf("code: %d\t|\tone\n", LOWORD(wparam));
                    break;
                }
                case BTN_TWO:
                {
                    printf("code: %d\t|\ttwo\n", LOWORD(wparam));
                    break;
                }
                case BTN_THREE:
                {
                    printf("code: %d\t|\tthree\n", LOWORD(wparam));
                    break;
                }
                case BTN_FOUR:
                {
                    printf("code: %d\t|\tfour\n", LOWORD(wparam));
                    break;
                }
                case BTN_FIVE:
                {
                    printf("code: %d\t|\tfive\n", LOWORD(wparam));
                    break;
                }
                case BTN_SIX:
                {
                    printf("code: %d\t|\tsix\n", LOWORD(wparam));
                    break;
                }
                case BTN_SEVEN:
                {
                    printf("code: %d\t|\tseven\n", LOWORD(wparam));
                    break;
                }
                case BTN_EIGHT:
                {
                    printf("code: %d\t|\teight\n", LOWORD(wparam));
                    break;
                }
                case BTN_NINE:
                {
                    printf("code: %d\t|\tnine\n", LOWORD(wparam));
                    break;
                }
                case BTN_NULL:
                {
                    printf("code: %d\t|\tnull\n", LOWORD(wparam));
                    break;
                }
            }
        }
        case WM_SIZE:
        {
            GetWindowRect(&rct, HIWORD(wparam));
            break;
        }
        default:
        {
            return DefWindowProcA(hwnd, msg, wparam, lparam);
            break;
        }
    }
}

int main()
{
    /* registering a window class */

    WNDCLASSA win;
    memset(&win, 0, sizeof(win));
    win.lpfnWndProc = wndProc;
    win.lpszClassName = "win_calc";
    win.hCursor = LoadCursor(NULL, IDC_ARROW);
    win.hbrBackground = COLOR_INACTIVECAPTION;
    RegisterClassA(&win);

    /* window creation */

    HWND hwnd = CreateWindow("win_calc", "Calculator", WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, NULL, NULL, NULL, NULL);

    HWND btnNull = CreateWindow("button", "0", WS_VISIBLE | WS_CHILD,
        90, 340, 50, 50, hwnd, BTN_NULL, NULL, NULL);
    HWND btnOne = CreateWindow("button", "1", WS_VISIBLE | WS_CHILD,
        20, 130, 50, 50, hwnd, BTN_ONE, NULL, NULL);
    HWND btnTwo = CreateWindow("button", "2", WS_VISIBLE | WS_CHILD,
        90, 130, 50, 50, hwnd, BTN_TWO, NULL, NULL);
    HWND btnThree = CreateWindow("button", "3", WS_VISIBLE | WS_CHILD,
        160, 130, 50, 50, hwnd, BTN_THREE, NULL, NULL);
    HWND btnFour = CreateWindow("button", "4", WS_VISIBLE | WS_CHILD,
        20, 200, 50, 50, hwnd, BTN_FOUR, NULL, NULL);
    HWND btnFive = CreateWindow("button", "5", WS_VISIBLE | WS_CHILD,
        90, 200, 50, 50, hwnd, BTN_FIVE, NULL, NULL);
    HWND btnSix = CreateWindow("button", "6", WS_VISIBLE | WS_CHILD,
        160, 200, 50, 50, hwnd, BTN_SIX, NULL, NULL);
    HWND btnSeven = CreateWindow("button", "7", WS_VISIBLE | WS_CHILD,
        20, 270, 50, 50, hwnd, BTN_SEVEN, NULL, NULL);
    HWND btnEight = CreateWindow("button", "8", WS_VISIBLE | WS_CHILD,
        90, 270, 50, 50, hwnd, BTN_EIGHT, NULL, NULL);
    HWND btnNine = CreateWindow("button", "9", WS_VISIBLE | WS_CHILD,
        160, 270, 50, 50, hwnd, BTN_NINE, NULL, NULL);
    HWND btnExit = CreateWindow("button", "X", WS_VISIBLE | WS_CHILD,
        570, 20, 50, 50, hwnd, BTN_EXIT, NULL, NULL);
    HWND staticRes = CreateWindow("static", "0", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
        320, 90, 300, 20, hwnd, STC_RES, NULL, NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);

    MSG msg;

    /* main loop */

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

