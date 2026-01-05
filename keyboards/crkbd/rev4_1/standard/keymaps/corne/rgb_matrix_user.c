#include "quantum.h"
#include "lib/lib8tion/lib8tion.h"
#include "lib/noise.h"

#define RGB_MATRIX_CUSTOM_BINARY_NOISE 0xFF

#define COLOR_A_R 255
#define COLOR_A_G 227
#define COLOR_A_B 0

#define COLOR_B_R 127
#define COLOR_B_G 0
#define COLOR_B_B 255

#define NOISE_SPACE_SCALE 32
#define NOISE_TIME_SCALE 4

static bool rgb_matrix_effect_binary_noise(void) {
    static uint16_t time = 0;
    time += NOISE_TIME_SCALE;

    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (!rgb_matrix_is_led_enabled(i)) {
            continue;
        }

        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;

        uint16_t noise = noise16(
            x * NOISE_SPACE_SCALE,
            y * NOISE_SPACE_SCALE,
            time
        );

        uint8_t n = noise >> 8;

        uint8_t r = lerp8by8(COLOR_A_R, COLOR_B_R, n);
        uint8_t g = lerp8by8(COLOR_A_G, COLOR_B_G, n);
        uint8_t b = lerp8by8(COLOR_A_B, COLOR_B_B, n);

        rgb_matrix_set_color(i, r, g, b);
    }

    return false;
}

RGB_MATRIX_EFFECT(CUSTOM_BINARY_NOISE)
