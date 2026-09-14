#include "common.hpp"

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

#include "windowing.h"

typedef unsigned __int64 QWORD;

HWND main_window_handle;

void open_main_window(LPCTSTR window_title, HICON window_icon, HICON small_window_icon, COLORREF background_color, WNDPROC window_process) {
    ATOM window_class = RegisterClassExA(
        &(WNDCLASSEXA) {
            .cbSize = sizeof(WNDCLASSEXA),
            .style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW,
            .lpfnWndProc = window_process,
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
    main_window_handle = window_handle;
}

LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        default: {
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
        case WM_INPUT: {
            UINT pcbSize;
            RAWINPUT pData;
            UINT used_bytes = GetRawInputBuffer(&pData, &pcbSize, sizeof(RAWINPUTHEADER));
            if(used_bytes == -1) break;

            while(true) {
                PRAWINPUT raw_input = NEXTRAWINPUTBLOCK(&pData);
                if(raw_input->header.dwType != RIM_TYPEKEYBOARD) break; // keyboard only app

                RAWKEYBOARD keyboard_input = raw_input->data.keyboard;
                // todo
            }
            
            break;
        // todo
        }
    }
    return 1;
}

bool launched_from_console() {
    DWORD processList[2];
    DWORD count = GetConsoleProcessList(processList, 2);
    return (count > 1)&&(count != 0);
}

void hide_terminal() {
    if(launched_from_console()) return;

    HWND console = GetConsoleWindow();
    if(console != NULL) ShowWindow(console, SW_HIDE);
    else {
        printf("Failed To Hide Console Window, Error Code: %lu\n", GetLastError());
        return;
    }
}