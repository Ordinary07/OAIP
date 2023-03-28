// dz_lab2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "dz_lab2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DZLAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DZLAB2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DZLAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DZLAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(105, 164, 232));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen;
            HBRUSH hBrush;

            hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            //roof
            hBrush = CreateSolidBrush(RGB(66, 0, 0));
            SelectObject(hdc, hBrush);
            POINT pt[6];
            pt[0].x = 20;
            pt[0].y = 200;
            pt[1].x = 270;
            pt[1].y = 55;
            pt[2].x = 500;
            pt[2].y = 200;
            pt[3].x = 448;
            pt[3].y = 200;
            pt[4].x = 20;
            pt[4].y = 200;
            pt[5].x = 70;
            pt[5].y = 200;
            Polygon(hdc, pt, 6);
            DeleteObject(hBrush);

            //block
            hBrush = CreateSolidBrush(RGB(240, 116, 39));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 70, 200, 450, 550);
            
            //door
            hBrush = CreateSolidBrush(RGB(110, 127, 128));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 310, 350, 410, 550);

            //window
            hBrush = CreateSolidBrush(RGB(49, 140, 231));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 130, 280, 260, 420);
            //first line
            MoveToEx(hdc, 210, 280, NULL);
            LineTo(hdc, 210, 420);
            //second line
            MoveToEx(hdc, 210, 350, NULL);
            LineTo(hdc, 255, 350);
            
            //line
            hPen = CreatePen(PS_SOLID, 10, RGB(0, 128, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 0, 557, NULL);
            LineTo(hdc, 1500, 557);

            //tree
            hPen = CreatePen(PS_SOLID, 5, RGB(128, 64, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(128, 64, 0));
            SelectObject(hdc, hBrush);
            POINT tr[4];
            tr[0].x = 650;
            tr[0].y = 550;
            tr[1].x = 650;
            tr[1].y = 350;
            tr[2].x = 670;
            tr[2].y = 350;
            tr[3].x = 670;
            tr[3].y = 550;
            Polygon(hdc, tr, 4);
            Rectangle(hdc, 1190, 550, 1210, 500);

            //tree ellipse
            hPen = CreatePen(PS_SOLID, 5, RGB(0, 128, 64));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(0, 128, 64));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 550, 140, 765, 350);

            //tree 2
            POINT tr2[4];
            tr2[0].x = 1100;
            tr2[0].y = 500;
            tr2[1].x = 1300;
            tr2[1].y = 500;
            tr2[2].x = 1200;
            tr2[2].y = 350;
            tr2[3].x = 1100;
            tr2[3].y = 500;
            Polygon(hdc, tr2, 4);

            POINT tr3[4];
            tr3[0].x = 1160;
            tr3[0].y = 350;
            tr3[1].x = 1290;
            tr3[1].y = 350;
            tr3[2].x = 1200;
            tr3[2].y = 250;
            tr3[3].x = 1100;
            tr3[3].y = 350;
            Polygon(hdc, tr3, 4);

            POINT tr4[4];
            tr4[0].x = 1140;
            tr4[0].y = 250;
            tr4[1].x = 1260;
            tr4[1].y = 250;
            tr4[2].x = 1200;
            tr4[2].y = 190;
            tr4[3].x = 1140;
            tr4[3].y = 250;
            Polygon(hdc, tr4, 4);

            //home for dog
            //roof
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(141, 163, 153));
            SelectObject(hdc, hBrush);
            POINT dr[4];
            dr[0].x = 900;
            dr[0].y = 350;
            dr[1].x = 800;
            dr[1].y = 400;
            dr[2].x = 1000;
            dr[2].y = 400;
            dr[3].x = 900;
            dr[3].y = 350;
            Polygon(hdc, dr, 4);

            //block
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(49, 140, 231));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 800, 550, 1000, 400);

            //door
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(131, 137, 150));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 840, 440, 960, 550);

            //sun
            hPen = CreatePen(PS_SOLID, 3, RGB(244, 202, 22));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(244, 202, 22));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 1000, 50, 1100, 150);

            

 
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

// Обработчик сообщений для окна "О программе".
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
