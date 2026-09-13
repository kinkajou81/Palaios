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
}