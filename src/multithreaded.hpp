#pragma once

#include "common.hpp"

#include <windows.h>

namespace multithreaded {
    typedef struct {
        LPCTSTR window_title;
        HICON window_icon;
        HICON small_window_icon;
        COLORREF background_color;
        WNDPROC window_process;
    } main_window_args;

    DWORD __stdcall main_window(LPVOID lpThreadParameter) {
        main_window_args* args = (main_window_args*)lpThreadParameter;
        open_main_window(args->window_title, args->window_icon, args->small_window_icon, args->background_color, args->window_process);
        register_raw_input_devices(main_window_handle);
        
        MSG msg = {};
        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return 0;
    }
}