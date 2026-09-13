#pragma once

#include "common.hpp"

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void open_main_window(LPCTSTR window_title, HICON window_icon, HICON small_window_icon, COLORREF background_color, WNDPROC Wndproc);

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#ifdef __cplusplus
}
#endif