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
  arduboy.drawBitmap(60, 44, highscoreSprite, 40, 6, WHITE);
  printScore(70, 54, highscore, 1);

  //draw mute icon, if needed
  if (!arduboy.audio.enabled()) {
    arduboy.drawBitmap(116, 0, muteSprite, 11, 7, WHITE);
  }
  
  //reset highscore
  if (arduboy.pressed(B_BUTTON | DOWN_BUTTON)) {
    if (highscore > 0) {
      playPressTune();
      highscore = 0;
      EEPROM.write(EEPROM_ADDRESS, highscore);
    }
    
  //toggle sound on/off 
  } else if (arduboy.justPressed(B_BUTTON)) {
    arduboy.audio.toggle();

  //start game
  } else if (arduboy.justPressed(A_BUTTON)) {
    playPressTune();
    gameState = STATE_GAME_LOOP;
  }
}
