#pragma once

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

#include "point.h"
#include "snake.h"

#include "constants.h"

Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);

uint8_t highscore = 0;
uint8_t score = 0;

uint8_t gameState = STATE_MAIN_INTRO;

bool toBeInitFlag = true;
uint8_t animCounter = 0;

Snake snake;
point food;
