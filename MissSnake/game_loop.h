#pragma once

#include "globals.h"
#include "beeps.h"
#include "sprites.h"

char scoreText[4];             // Score à afficher
uint8_t highScore = 0;         // Meilleur score
char highScoreText[4];         // Meilleur score à afficher 


static bool toBeInitFlag = true;
static uint16_t counter = SNAKE_SPEED_INCR_COUNTER;
static uint8_t speed = SNAKE_SPEED_START;
static uint8_t score = 0;

void drawGameField();

void stateGameLoop() 
{
  if (toBeInitFlag) {
    snake.init();
    food.replace(P1, P2);

    score = 0;
    counter = SNAKE_SPEED_INCR_COUNTER;
    speed = SNAKE_SPEED_START;
    score = 0;
    
    toBeInitFlag = false;
  }

  if (arduboy.justPressed(UP_BUTTON)) {
    if (snake.direction != DIR_DOWN) {
      snake.direction = DIR_UP;
    }
  }

  if (arduboy.justPressed(DOWN_BUTTON)) {
    if (snake.direction != DIR_UP) {
      snake.direction = DIR_DOWN;
    }
  }

  if (arduboy.justPressed(LEFT_BUTTON)) {
    if (snake.direction != DIR_RIGHT) {
      snake.direction = DIR_LEFT;
    }
  }
  
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    if (snake.direction != DIR_LEFT) {
      snake.direction = DIR_RIGHT;
    }
  }

  if (arduboy.justPressed(A_BUTTON)) {
    //toggle sound
  }

  if (arduboy.justPressed(B_BUTTON)) {
    //toggle pause
  }
  
  if (arduboy.everyXFrames(speed)) {
    
    snake.move();

    if (snake.checkFood(food)) {
      snake.grow++;
      score++;
      food.replace(P1, P2);
      playEatTune();
    }
  }

  if (snake.checkBody() || snake.checkBorder(P1, P2)) {
    toBeInitFlag = true;
    gameState = STATE_MAIN_INTRO;
    playDeadTune();
  }

  drawGameField();

  counter--;
  if (counter == 0) {
    if (speed > SNAKE_SPEED_END) {
      speed--;
    }
    counter = SNAKE_SPEED_INCR_COUNTER;
  }
}


void drawGameField()
{
  //draw border
  arduboy.drawRect(2, 2, 124, 60, 1);

  //draw score
  arduboy.setTextSize(1);
  arduboy.setCursor(49, 0);
  arduboy.print("     ");
  arduboy.setCursor(55, 0);
  sprintf(scoreText, "%03u", score);
  arduboy.print(scoreText);

  //draw snake
  arduboy.drawBitmap(snake.head.x*SPRITE_SIZE, snake.head.y*SPRITE_SIZE, snakeSprite, SPRITE_SIZE, SPRITE_SIZE, 1);
  for (auto i=0; i<snake.body.size; i++) {
    const point& p = snake.body[i];
    arduboy.drawBitmap(p.x*SPRITE_SIZE, p.y*SPRITE_SIZE, snakeSprite, SPRITE_SIZE, SPRITE_SIZE, 1);
  }

  //draw food
  arduboy.drawBitmap(food.x*SPRITE_SIZE, food.y*SPRITE_SIZE, foodSprite, SPRITE_SIZE, SPRITE_SIZE, 1);
}
