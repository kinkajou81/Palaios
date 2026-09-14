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

typedef struct {
    uintptr_t tile_data_base;
    uintptr_t map_data_base;
    uint16_t x_offset;
    uint16_t y_offset;
    uint8_t priority : 5;
    bool mosaic : 1;
} background_control;

typedef struct {
    uint16_t x1;
    uint16_t x2;
    uint16_t y1;
    uint16_t y2;
    bool background_0_inside : 1;
    bool background_1_inside : 1;
    bool background_2_inside : 1;
    bool background_3_inside : 1;
    bool background_4_inside : 1;
    bool background_5_inside : 1;
    bool objects_inside : 1;
    bool background_0_outside : 1;
    bool background_1_outside : 1;
    bool background_2_outside : 1;
    bool background_3_outside : 1;
    bool background_4_outside : 1;
    bool background_5_outside : 1;
    bool objects_outside : 1;
} window_control;

