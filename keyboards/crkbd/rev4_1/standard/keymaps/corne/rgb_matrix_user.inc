RGB_MATRIX_EFFECT(NOISE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint8_t led_boot_state[RGB_MATRIX_LED_COUNT];
static uint16_t boot_timer = 0;

static bool NOISE(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (params->init) {
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            led_boot_state[i] = 0;
        }
        boot_timer = timer_read();
    }

    if (led_min == 0) {
        if (timer_elapsed(boot_timer) > 20) {
            for (uint8_t try = 0; try < 5; try++) {
                uint8_t rand_idx = random8_max(RGB_MATRIX_LED_COUNT);
                if (led_boot_state[rand_idx] == 0) {
                    led_boot_state[rand_idx] = 1;
                    boot_timer = timer_read();
                    break;
                }
            }
        }
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        if (i >= RGB_MATRIX_LED_COUNT) continue;

        if (led_boot_state[i] == 0) {
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }

        uint8_t t = timer_read() >> 5;

        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;

        uint8_t wx = x + (sin8(y * 2 + t) >> 3);
        uint8_t wy = y + (sin8(x * 2 + t * 2) >> 3);
        uint8_t n  = sin8(wx * 2 + wy * 3 + t);

        uint8_t r_raw = lerp8by8(255, 127, n);
        uint8_t g_raw = lerp8by8(227,   0, n);
        uint8_t b_raw = lerp8by8(  0, 255, n);

        uint8_t power_limit = 110;

        rgb_matrix_set_color(i,
            scale8(r_raw, power_limit),
            scale8(g_raw, power_limit),
            scale8(b_raw, power_limit)
        );
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif
