#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

void register_raw_input_devices(HWND hWnd) {
    RAWINPUTDEVICE Rid;

    // keyboard
    Rid = (RAWINPUTDEVICE) {
        .usUsagePage = 0x01,
        .usUsage = 0x07,
        .dwFlags = 0,
        .hwndTarget = hWnd
    };

    if (RegisterRawInputDevices(&Rid, 1, sizeof(Rid)) == FALSE) {
        printf("Failed To Register Raw Input Keyboard. Error Code: %lu\n", GetLastError());
        exit(-1);
    }
}