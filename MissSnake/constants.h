#pragma once

//memory addresses
static const uint8_t EEPROM_ADDRESS = 111;

//direction values
static const point DIR_UP    = point( 0, -1);
static const point DIR_DOWN  = point( 0,  1);
static const point DIR_RIGHT = point( 1,  0);
static const point DIR_LEFT  = point(-1,  0);

//gamefield logical corners
static const point P1 = point(0, 0);
static const point P2 = point(31, 15);
static const point SNAKE_START = point(18, 8);

//game timing values
static const uint8_t GAME_FRAME_RATE   = 60;
static const uint8_t SNAKE_SPEED_START = GAME_FRAME_RATE / 6;
static const uint8_t SNAKE_SPEED_END   = GAME_FRAME_RATE / 12;
static const uint16_t SNAKE_SPEED_INCR_COUNTER = 30 * GAME_FRAME_RATE;

//game states
static const uint8_t STATE_MAIN_INTRO = 0;
static const uint8_t STATE_GAME_LOOP  = 1;
static const uint8_t STATE_GAME_OVER  = 2;
