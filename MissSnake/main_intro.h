#pragma once

#include "globals.h"
#include "beeps.h"
#include "sprites.h"

static uint8_t animCounter = 0;

void stateMainIntro() {

  arduboy.drawBitmap(52, 0, titleSprite, 56, 41, 1);

  if (arduboy.everyXFrames(GAME_FRAME_RATE)) {
    animCounter++;
  }
  
  if (animCounter%4 == 0) {
    arduboy.drawBitmap(0, 0, titleSprite2, 52, 64, 1);
  } else {
    arduboy.drawBitmap(0, 0, titleSprite1, 52, 64, 1);
  }
  
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    playPressTune();
    gameState = STATE_GAME_LOOP;
  }
}
