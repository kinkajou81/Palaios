#pragma once

#include <stdint.h>

extern uint16_t verical_counter;

typedef struct {
    uint8_t brightness;
    bool display_background_0 : 1;
    bool display_background_1 : 1;
    bool display_background_2 : 1;
    bool display_background_3 : 1;
    bool display_background_4 : 1;
    bool display_background_5 : 1;
    bool display_objects : 1;
    bool display_window_0 : 1;
    bool display_window_1 : 1;
    bool display_object_windows : 1;
} display_control;

