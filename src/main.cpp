#include "common.hpp"

#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <stdio.h>

#include "renderer.hpp"
#include "windowing.h"
#include "input.h"
#include "multithreaded.hpp"

thread_local int16_t common_error = 0;

void exit_point() {
    return;
}

int main() {
    atexit(exit_point);

    multithreaded::main_window_args new_thread_args{"my window", NULL, NULL, RGB(0, 0, 0), WndProc};
    DWORD window_thread_id;
    HANDLE window_thread_handle = CreateThread(
        NULL,
        8000000,
        multithreaded::main_window,
        (LPVOID)&new_thread_args,
        0,
        &window_thread_id
    );

    if(!launched_from_console()) {
        hide_terminal();
    }
    exit(-1);
}
