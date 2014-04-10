static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Keymap: Default Layer Colemak OSX
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | Home |           | PgUp |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   F  |   P  |   G  | End  |           | PgDn |   J  |   L  |   U  |   Y  |   ;  |   #    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Esc    |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
     * |--------+------+------+------+------+------|LCtrl |           |RCtrl |------+------+------+------+------+--------|
     * |    \   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |  Up  |   /    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |  `   |      |      |   [  |   ]  |                                       |!FN0! |      | Lft  | Dn | Rght   |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Del  |  Alt |       | Alt  |Enter |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LGui |       | RGui |      |      |
     *                                 | ~LNum|Space |------|       |------|Space | ~LDev|
     *                                 |      |      |LShift|       |RShift|      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     */

// qwerty at the moment!!!
    KEYMAP(  // layer 0 : default
        // left hand
        EQL, 1,   2,   3,   4,   5,   ESC,
        BSLS,Q,   W,   E,   R,   T,   FN2,
        TAB, A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN1,
        LGUI,GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL, END,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, SPC
    ),


};



/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};


static const uint16_t PROGMEM fn_actions[] = {

    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

};


void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
