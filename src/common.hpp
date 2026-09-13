#pragma once

#include <stdint.h>

// this header must be included in every file before <windows.h>

#undef UNICODE

#ifdef __cplusplus
extern "C" {
#endif

extern thread_local int16_t common_error;

#ifdef __cplusplus
}
#endif