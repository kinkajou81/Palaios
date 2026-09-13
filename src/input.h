#pragma once

#include "common.hpp"

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void register_raw_input_devices(HWND hWnd);

#ifdef __cplusplus
}
#endif