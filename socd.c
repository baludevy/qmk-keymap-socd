bool socd_enabled = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool wHeld = false;
    static bool sHeld = false;
    static bool aHeld = false;
    static bool dHeld = false;

    // set kc_f23 to enable socd and set kc_f24 to disable socd
    switch (keycode) {
        case KC_F23:
            if (record->event.pressed) {
                socd_enabled = true;
            }
            return false;

        case KC_F24:
            if (record->event.pressed) {
                socd_enabled = false;
            }
            return false;
    }

    switch (keycode) {
        case KC_W:
            wHeld = record->event.pressed;
            if (socd_enabled) {
                if (sHeld && wHeld) {
                    unregister_code(KC_S);
                } else if (sHeld && !wHeld) {
                    unregister_code(KC_W);
                    register_code(KC_S);
                    return false;
                }
            }
            break;
        case KC_S:
            sHeld = record->event.pressed;
            if (socd_enabled) {
                if (wHeld && sHeld) {
                    unregister_code(KC_W);
                } else if (wHeld && !sHeld) {
                    unregister_code(KC_S);
                    register_code(KC_W);
                    return false;
                }
            }
            break;

        case KC_A:
            aHeld = record->event.pressed;
            if (socd_enabled) {
                if (dHeld && aHeld) {
                    unregister_code(KC_D);
                } else if (dHeld && !aHeld) {
                    unregister_code(KC_A);
                    register_code(KC_D);
                    return false;
                }
            }
            break;

        case KC_D:
            dHeld = record->event.pressed;
            if (socd_enabled) {
                if (aHeld && dHeld) {
                    unregister_code(KC_A);
                } else if (aHeld && !dHeld) {
                    unregister_code(KC_D);
                    register_code(KC_A);
                    return false;
                }
            }
            break;

        default:
            break;
    }

    return true;
}