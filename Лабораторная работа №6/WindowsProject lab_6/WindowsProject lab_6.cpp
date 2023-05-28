// WindowsProject lab_6.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject lab_6.h"
#include <stdio.h>
#include <stdlib.h>


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int arr[1000];
int n, min, max, min_idx = -1, max_idx = -1, m = 0;//agar -1 ni uzgartirsak 2 chi koord. ta katakchalar kupayadi

int arr_old[1000];// massivlar soni 
int n_old;


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
    LoadStringW(hInstance, IDC_WINDOWSPROJECTLAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECTLAB6));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECTLAB6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECTLAB6);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    FILE* f;
    fopen_s(&f, "C:\\TEMP\\input_6.txt", "rt");

    fscanf_s(f, "%d", &n_old);
    n = n_old;

    for (int i = 0; i < n; i++)
    {
        fscanf_s(f, "%d", &arr_old[i]);
        arr[i] = arr_old[i];
    }

    fclose(f);

    min = arr[0];
    max = arr[0];

    for (int q = 0; q < n; q++)
    {
        if (arr[q] > max)
        {
            max = arr[q];
            max_idx = q;
        }
    }

    for (int q = 0; q < n; q++)
    {
        if (arr[q] < min)
        {
            min = arr[q];
            min_idx = q;
        }
    }

    int i, j;

    if (min_idx <= max_idx)
    {
        i = min_idx;
        j = max_idx;
    }
    else
    {
        i = max_idx;
        j = min_idx;
    }

    for (int q = 0; q < n; q++)//2 chi kordinatada 4 burchakni kupayishi va kamayishi  0 ga taluqli
    {
        if (arr[q] % 2 == 0 && q > i && q < j && arr[q] != max && arr[q] != min)//max va minni topilgan
        {
            for (int h = q; h < n - 1; h++)
            {
                int tmp = arr[h];
                arr[h] = arr[h + 1];
                arr[h + 1] = tmp;
            }

            q--;
            n--;
        }

        if (n == 2) break;//bu 2 >>>max va minga taluqli
    }

    m = n;
    
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
void diagramma(HDC hdc, int x, int y, int h)
{
    Rectangle(hdc, x, y - h, x + 20, y);
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
          
            HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));


            HPEN LightBluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 20));
            HPEN BlackPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));

            //Координатные оси
            MoveToEx(hdc, 200, 400, NULL);
            LineTo(hdc, 200, 200);
            MoveToEx(hdc, 200, 400, NULL);
            LineTo(hdc, 400, 400);
            MoveToEx(hdc, 200, 400, NULL);
            LineTo(hdc, 200, 500);

            MoveToEx(hdc, 600, 400, NULL);
            LineTo(hdc, 600, 200);
            MoveToEx(hdc, 600, 400, NULL);
            LineTo(hdc, 800, 400);
            MoveToEx(hdc, 600, 400, NULL);
            LineTo(hdc, 600, 500);

            //Стрелки на координатных осях
            SelectObject(hdc, BlackPen);
            MoveToEx(hdc, 590, 210, NULL);
            LineTo(hdc, 600, 200);
            LineTo(hdc, 610, 210);
            MoveToEx(hdc, 790, 390, NULL);
            LineTo(hdc, 800, 400);
            LineTo(hdc, 790, 410);

            MoveToEx(hdc, 190, 210, NULL);
            LineTo(hdc, 200, 200);
            LineTo(hdc, 210, 210);
            MoveToEx(hdc, 390, 390, NULL);
            LineTo(hdc, 400, 400);
            LineTo(hdc, 390, 410);
            DeleteObject(BlackPen);

            SelectObject(hdc, GreenBrush);
            for (int i = 0; i < n_old; i++)
            {
                diagramma(hdc, 200 + i * 20, 400, arr_old[i]);//har br turtburchakni orasidagi masofa
            }



            for (int i = 0; i < m; i++)
            {
                if (arr[i] == max)
                {
                    SelectObject(hdc, RedBrush);//macsimalhiy elementni rangi
                }
                else if (arr[i] == min)
                {
                    SelectObject(hdc, BlueBrush);
                }
                else
                {
                    SelectObject(hdc, GreenBrush);
                }

                diagramma(hdc, 600 + i * 20, 400, arr[i]);//max va min masofasi

            }

            DeleteObject(GreenBrush);
            DeleteObject(BlueBrush);
            DeleteObject(RedBrush);


            
            
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
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
