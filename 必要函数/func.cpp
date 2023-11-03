
#include"func.h"

using namespace std;



void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
bool timer(long long ms, int id)  //��ʱ�����ã�
{
    static long long  start[1000] = { 0 };
    long long end = clock();

    if (end - start[id] > ms)
    {
        start[id] = end;
        return 1;
    }
    return 0;
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = 0;
    cursor.dwSize = 1;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(hOut, &cursor);
}
void full_screen()
{
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

    LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
    /* ���ô�����Ϣ ��� ȡ�����������߿� */
    SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { 10000,10000 });
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void SetColor(int fore, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back << 4) + fore);
}
void clearKeyCache()
{
    for (int i = 0; i <= 100; ++i)
    {
        GetAsyncKeyState(VK_SPACE); GetAsyncKeyState('Q'); GetAsyncKeyState(VK_UP); GetAsyncKeyState(VK_DOWN); GetAsyncKeyState(VK_LEFT);
        GetAsyncKeyState(VK_RIGHT); GetAsyncKeyState('G'); GetAsyncKeyState('H'); GetAsyncKeyState('Y'); GetAsyncKeyState('J');
        GetAsyncKeyState(VK_NUMPAD1); GetAsyncKeyState(VK_NUMPAD2); GetAsyncKeyState(VK_NUMPAD3); GetAsyncKeyState(VK_NUMPAD5);
    }
}



