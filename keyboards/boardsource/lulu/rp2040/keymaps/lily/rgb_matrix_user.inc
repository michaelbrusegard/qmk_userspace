RGB_MATRIX_EFFECT(NOISE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint8_t t     = 0;
static uint8_t frame = 0;

static bool NOISE(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    frame++;
    if (frame >= 4) {
        frame = 0;
        t++;
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;

        uint8_t wx = x + (sin8(y * 2 + t) >> 3);
        uint8_t wy = y + (sin8(x * 2 + t * 2) >> 3);
        uint8_t n  = sin8(wx * 2 + wy * 3 + t);

        uint8_t r = lerp8by8(255, 127, n);
        uint8_t g = lerp8by8(227,   0, n);
        uint8_t b = lerp8by8(  0, 255, n);

        rgb_matrix_set_color(i, r, g, b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif
