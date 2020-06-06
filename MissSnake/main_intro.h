#pragma once

#include "globals.h"
#include "beeps.h"

static bool blinkingFlag = false;

void stateMainIntro() {

  arduboy.setTextSize(2);
  arduboy.setCursor(10, 11);
  arduboy.print("MissSnake");

  if (arduboy.everyXFrames(GAME_FRAME_RATE/2)) {
    blinkingFlag = !blinkingFlag;
  }
  
  if (blinkingFlag) {
    arduboy.setTextSize(1);
    arduboy.setCursor(16, 44);
    arduboy.print("press A to start");
  }

  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    playPressTune();
    gameState = STATE_GAME_LOOP;
  }
}
