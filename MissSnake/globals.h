#pragma once

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

#include "point.h"
#include "snake.h"

#define EEPROM_ADDRESS 100   // Adresse du meilleur score sur l'EEpointROM 

Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);

static const uint8_t GAME_FRAME_RATE  = 60;

static const uint8_t SNAKE_SPEED_START = GAME_FRAME_RATE / 4;
static const uint16_t SNAKE_SPEED_INCR_COUNTER = 20 * GAME_FRAME_RATE;

static const uint8_t STATE_MAIN_INTRO = 0;
static const uint8_t STATE_GAME_LOOP  = 1;

uint8_t gameState = STATE_MAIN_INTRO;

Snake snake;
point food;
