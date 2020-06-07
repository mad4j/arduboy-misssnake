#pragma once

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

#include "point.h"
#include "snake.h"

#include "constants.h"


#define EEPROM_ADDRESS 100   // Adresse du meilleur score sur l'EEpointROM 


Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);

uint8_t gameState = STATE_MAIN_INTRO;

Snake snake;
point food;

uint8_t hihgScore;
