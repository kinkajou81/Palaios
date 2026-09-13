#pragma once

// this header must be included in every file before <windows.h>

#include <stdint.h>

#ifndef __cplusplus
#define thread_local __declspec(thread)
#endif

#undef UNICODE

#ifdef __cplusplus
extern "C" {
#endif

extern thread_local int16_t common_error;

#ifdef __cplusplus
}
#endif