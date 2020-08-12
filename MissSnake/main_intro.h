#pragma once

#include "globals.h"
#include "beeps.h"
#include "sprites.h"

static uint8_t animCounter = 0;

static char highscoreText[4];

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

  //draw score
  arduboy.setTextSize(1);

  arduboy.setCursor(55, 40);
  arduboy.print("High Score");
  
  arduboy.setCursor(55, 48);
  sprintf(highscoreText, "%03u", highscore);
  arduboy.print(highscoreText);

  
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    playPressTune();
    gameState = STATE_GAME_LOOP;
  }
}
