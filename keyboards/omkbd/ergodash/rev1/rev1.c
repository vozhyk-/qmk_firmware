#include "ergodash.h"

#ifdef AUDIO_ENABLE
    float tone_startup[][2] = SONG(STARTUP_SOUND);
    float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

void matrix_init_kb(void) {

    #ifdef AUDIO_ENABLE
        _delay_ms(20); // gets rid of tick
        PLAY_SONG(tone_startup);
    #endif

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);

	matrix_init_user();
};

void shutdown_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_goodbye);
	_delay_ms(150);
	stop_all_notes();
    #endif
}

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}, {6,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}, {6,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}, {6,7}},
    {{0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}, {6,8}},
    {{0,9}, {1,9}, {2,9}, {3,9}, {4,9}, {5,9}, {6,9}},
    /* Right hand, matrix positions */
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}},
    {{0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2}},
    {{0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}, {6,3}},
    {{0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4}},
};
#endif
