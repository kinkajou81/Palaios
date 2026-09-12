#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

#include "renderer.cpp"
#include "windowing.cpp"

thread_local int16_t common_error = 0;

void exit_point() {
    return;
}

int main() {
    atexit(exit_point);

    exit(-1);
}
