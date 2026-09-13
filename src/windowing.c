#include "common.hpp"

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

#include "windowing.hpp"

void open_main_window(LPCTSTR window_title, HICON window_icon, HICON small_window_icon, COLORREF background_color, WNDPROC Wndproc) {
    ATOM window_class = RegisterClassExA(
        &(WNDCLASSEXA) {
            .cbSize = sizeof(WNDCLASSEXA),
            .style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW,
            .lpfnWndProc = Wndproc,
            .cbClsExtra = 0,
            .cbWndExtra = 0,
            .hInstance = GetModuleHandle(NULL),
            .hIcon = window_icon,
            .hCursor = LoadCursor(NULL, IDC_ARROW),
            .hbrBackground = CreateSolidBrush(background_color),
            .lpszMenuName = NULL,
            .lpszClassName = "Main Window",
            .hIconSm = small_window_icon
        }
    );
    if(window_class == 0) {
        printf("Main Window Class Failed To Be Created, Error code: %lu\n", GetLastError());
        exit(-1);
    }

    HWND window_handle = CreateWindowExA(
        WS_EX_WINDOWEDGE,
        MAKEINTATOM(window_class),
        window_title,
        WS_MAXIMIZEBOX | WS_SYSMENU | WS_MINIMIZEBOX | WS_SIZEBOX | WS_VISIBLE,
        CW_USEDEFAULT,
        SW_SHOWNORMAL,
        256,
        192,
        NULL,
        NULL,
        NULL,
        NULL
    );
    if(window_handle == NULL) {
        printf("Main Window Failed To Be Created, Error code: %lu\n", GetLastError());
        exit(-1);
    }
}