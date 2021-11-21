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

#define BTN_SIGN    20
#define BTN_ADD     21
#define BTN_SUB     22
#define BTN_MULT    23
#define BTN_DIV     24
#define BTN_EQUAL   25
#define BTN_DEL     26
#define BTN_RES     27
#define BTN_POINT   50

#define BTN_EXIT    999
#define STC_RES     1000

RECT rct;
HWND staticRes;

typedef struct
{
    long double val;
    BOOL isFirst;
    BOOL isFlt;
    long double doz;
}TBuf, * PBuf;

TBuf buf1, buf2, buf3;
PBuf pBuf = &buf1;

char action = ' ';


void initBuf(PBuf buf, int value, BOOL isNumber, BOOL isFlt, long double doz)
{
    buf->val = value;
    buf->isFirst = isNumber;
    buf->isFlt = isFlt;
    buf->doz = doz;
}


void addNumber(PBuf buf, int number)
{
    if (buf->isFlt && !buf->isFirst)
    {
        buf->val += (buf->doz * number);
        buf->doz /= 10;
    }
    else
    {
        if (buf->val < 0)
        {
            buf->val = -buf->val;

            if (buf->isFirst)
            {
                buf->val += number;
                buf->isFirst = FALSE;
            }
            else
            {
                buf->val *= 10;
                buf->val += number;
            }

            buf->val = -buf->val;
        }
        else
        {
            if (buf->isFirst)
            {
                buf->val += number;
                buf->isFirst = FALSE;
            }
            else
            {
                buf->val *= 10;
                buf->val += number;
            }
        }
    }
}


void deleteNumber(PBuf buf)
{
    char tmp[32];
    sprintf(tmp, "%g", buf->val);
    int len = strlen(tmp) - 1;
    tmp[len] = '\0';
    buf->val = atof(tmp);

    if ((buf->val - (int)buf->val) == 0)
    {
        buf->isFlt = FALSE;
    }

    if (buf->isFlt)
    {
        buf->doz *= 10;
    }
}


void showBuf(PBuf buf)
{
    char tmp[32];
    sprintf(tmp, "%g", buf->val);
    SetWindowText(staticRes, tmp);
}


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
                    addNumber(pBuf, 1);
                    showBuf(pBuf);
                    break;
                }
                case BTN_TWO:
                {
                    printf("code: %d\t|\ttwo\n", LOWORD(wparam));
                    addNumber(pBuf, 2);
                    showBuf(pBuf);
                    break;
                }
                case BTN_THREE:
                {
                    printf("code: %d\t|\tthree\n", LOWORD(wparam));
                    addNumber(pBuf, 3);
                    showBuf(pBuf);
                    break;
                }
                case BTN_FOUR:
                {
                    printf("code: %d\t|\tfour\n", LOWORD(wparam));
                    addNumber(pBuf, 4);
                    showBuf(pBuf);
                    break;
                }
                case BTN_FIVE:
                {
                    printf("code: %d\t|\tfive\n", LOWORD(wparam));
                    addNumber(pBuf, 5);
                    showBuf(pBuf);
                    break;
                }
                case BTN_SIX:
                {
                    printf("code: %d\t|\tsix\n", LOWORD(wparam));
                    addNumber(pBuf, 6);
                    showBuf(pBuf);
                    break;
                }
                case BTN_SEVEN:
                {
                    printf("code: %d\t|\tseven\n", LOWORD(wparam));
                    addNumber(pBuf, 7);
                    showBuf(pBuf);
                    break;
                }
                case BTN_EIGHT:
                {
                    printf("code: %d\t|\teight\n", LOWORD(wparam));
                    addNumber(pBuf, 8);
                    showBuf(pBuf);
                    break;
                }
                case BTN_NINE:
                {
                    printf("code: %d\t|\tnine\n", LOWORD(wparam));
                    addNumber(pBuf, 9);
                    showBuf(pBuf);
                    break;
                }
                case BTN_NULL:
                {
                    printf("code: %d\t|\tnull\n", LOWORD(wparam));
                    addNumber(pBuf, 0);
                    showBuf(pBuf);
                    break;
                }
                case BTN_DEL:
                {
                    printf("code: %d\t|\tdelete\n", LOWORD(wparam));
                    deleteNumber(pBuf);
                    showBuf(pBuf);
                    break;
                }
                case BTN_RES:
                {
                    printf("code: %d\t|\treset\n", LOWORD(wparam));
                    pBuf = &buf1;
                    buf1.val = 0;
                    buf1.isFirst = TRUE;
                    buf1.isFlt = FALSE;
                    buf1.doz = 0.1;
                    buf2.val = 0;
                    buf2.isFirst = TRUE;
                    buf2.isFlt = FALSE;
                    buf2.doz = 0.1;
                    buf3.val = 0;
                    buf3.isFirst = TRUE;
                    buf3.isFlt = FALSE;
                    buf3.doz = 0.1;
                    showBuf(pBuf);
                    break;
                }
                case BTN_SIGN:
                {
                    printf("code: %d\t|\tchange sign\n", LOWORD(wparam));
                    pBuf->val = -pBuf->val;
                    showBuf(pBuf);
                    break;
                }
                case BTN_POINT:
                {
                    printf("code: %d\t|\tpoint\n", LOWORD(wparam));
                    pBuf->isFlt = TRUE;
                    break;
                }
                case BTN_ADD:
                {
                    printf("code: %d\t|\t+\n", LOWORD(wparam));
                    pBuf = &buf2;
                    action = '+';
                    showBuf(pBuf);
                    break;
                }
                case BTN_SUB:
                {
                    printf("code: %d\t|\t-\n", LOWORD(wparam));
                    pBuf = &buf2;
                    action = '-';
                    showBuf(pBuf);
                    break;
                }
                case BTN_MULT:
                {
                    printf("code: %d\t|\t*\n", LOWORD(wparam));
                    pBuf = &buf2;
                    action = '*';
                    showBuf(pBuf);
                    break;
                }
                case BTN_DIV:
                {
                    printf("code: %d\t|\t/\n", LOWORD(wparam));
                    pBuf = &buf2;
                    action = '/';
                    showBuf(pBuf);
                    break;
                }
                case BTN_EQUAL:
                {
                    printf("code: %d\t|\t=\n", LOWORD(wparam));
                    
                    switch (action)
                    {
                        case '+':
                        {
                            pBuf = &buf3;
                            pBuf->val = buf1.val + buf2.val;
                            buf1.val = pBuf->val;
                            pBuf = &buf1;
                            showBuf(pBuf);
                            break;
                        }
                        case '-':
                        {
                            pBuf = &buf3;
                            pBuf->val = buf1.val - buf2.val;
                            buf1.val = pBuf->val;
                            pBuf = &buf1;
                            showBuf(pBuf);
                            break;
                        }
                        case '*':
                        {
                            pBuf = &buf3;
                            pBuf->val = buf1.val * buf2.val;
                            buf1.val = pBuf->val;
                            pBuf = &buf1;
                            showBuf(pBuf);
                            break;
                        }
                        case '/':
                        {
                            pBuf = &buf3;
                            pBuf->val = buf1.val / buf2.val;
                            buf1.val = pBuf->val;
                            pBuf = &buf1;
                            showBuf(pBuf);
                            break;
                        }
                    }

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
    HWND btnSign = CreateWindow("button", "+/-", WS_VISIBLE | WS_CHILD,
        20, 340, 50, 50, hwnd, BTN_SIGN, NULL, NULL);
    HWND btnPoint = CreateWindow("button", ".", WS_VISIBLE | WS_CHILD,
        160, 340, 50, 50, hwnd, BTN_POINT, NULL, NULL);
    HWND btnDel = CreateWindow("button", "Del", WS_VISIBLE | WS_CHILD,
        230, 130, 50, 50, hwnd, BTN_DEL, NULL, NULL);
    HWND btnRes = CreateWindow("button", "C", WS_VISIBLE | WS_CHILD,
        300, 130, 50, 50, hwnd, BTN_RES, NULL, NULL);
    HWND btnAdd = CreateWindow("button", "+", WS_VISIBLE | WS_CHILD,
        230, 200, 50, 50, hwnd, BTN_ADD, NULL, NULL);
    HWND btnSub = CreateWindow("button", "-", WS_VISIBLE | WS_CHILD,
        300, 200, 50, 50, hwnd, BTN_SUB, NULL, NULL);
    HWND btnMult = CreateWindow("button", "*", WS_VISIBLE | WS_CHILD,
        230, 270, 50, 50, hwnd, BTN_MULT, NULL, NULL);
    HWND btnDiv = CreateWindow("button", "/", WS_VISIBLE | WS_CHILD,
        300, 270, 50, 50, hwnd, BTN_DIV, NULL, NULL);
    HWND btnEqual = CreateWindow("button", "=", WS_VISIBLE | WS_CHILD,
        230, 340, 50, 50, hwnd, BTN_EQUAL, NULL, NULL);
    HWND btnExit = CreateWindow("button", "X", WS_VISIBLE | WS_CHILD,
        570, 20, 50, 50, hwnd, BTN_EXIT, NULL, NULL);
    staticRes = CreateWindow("static", "0", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
        320, 90, 300, 20, hwnd, STC_RES, NULL, NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);

    MSG msg;

    initBuf(&buf1, 0, TRUE, FALSE, 0.1);
    initBuf(&buf2, 0, TRUE, FALSE, 0.1);
    initBuf(&buf3, 0, TRUE, FALSE, 0.1);

    /* main loop */

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

