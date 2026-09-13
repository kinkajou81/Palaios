#include "common.hpp"

#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <stdio.h>

#include "windowing.h"

thread_local int16_t common_error = 0;

void exit_point() {
    return;
}

int main() {
    atexit(exit_point);

    exit(-1);
}
