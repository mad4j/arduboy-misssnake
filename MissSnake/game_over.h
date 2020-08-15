#pragma once

#include "globals.h"

static bool newHighscoreFlag = false;

void stateGameOver() 
{ 
  if (toBeInitFlag) {
    if (score > highscore) {
      highscore = score;
      EEPROM.write(EEPROM_ADDRESS, highscore);
      newHighscoreFlag = true;    
    } else {
      newHighscoreFlag = false; 
    }
    toBeInitFlag = false;
  }
  
  if (arduboy.everyXFrames(GAME_FRAME_RATE/2)) {
    animCounter++;
  }

  arduboy.drawBitmap((128-116)/2, 8, gameoverSprite, 116, 16, WHITE);
  printScore(48, 32, score, 2);

  if ((newHighscoreFlag) && (animCounter%2 == 0)) {
    arduboy.drawBitmap((128-61)/2, 56, newhighscoreSprite, 61, 6, WHITE);
  }
  
  //check for keys
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    toBeInitFlag = true;
    gameState = STATE_MAIN_INTRO;
  }
}
