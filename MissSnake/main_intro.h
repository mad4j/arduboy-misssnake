#pragma once

#include "globals.h"
#include "beeps.h"
#include "sprites.h"



void stateMainIntro() 
{
  //draw title animation
  arduboy.drawBitmap(52, 0, titleSprite, 56, 41, WHITE);

  if (arduboy.everyXFrames(GAME_FRAME_RATE)) {
    animCounter++;
  }
  
  if (animCounter%4 == 0) {
    arduboy.drawBitmap(0, 0, titleSprite2, 52, 64, WHITE);
  } else {
    arduboy.drawBitmap(0, 0, titleSprite1, 52, 64, WHITE);
  }

  //draw highscore
  printText(56, 44, "High Score", 1);
  printScore(76, 56, highscore, 1);

  //check for keys
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    playPressTune();
    gameState = STATE_GAME_LOOP;
  }
}
