#pragma once

#include "globals.h"
#include "beeps.h"
#include "sprites.h"

static uint16_t counter = SNAKE_SPEED_INCR_COUNTER;
static uint8_t speed = SNAKE_SPEED_START;


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
  }

  if (arduboy.justPressed(B_BUTTON)) {
    arduboy.audio.toggle();
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
    gameState = STATE_GAME_OVER;
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
  arduboy.drawRect(2, 2, 124, 60, WHITE);

  //draw snake
  arduboy.drawBitmap(snake.head.x*SPRITE_SIZE, snake.head.y*SPRITE_SIZE, snakeSprite, SPRITE_SIZE, SPRITE_SIZE, WHITE);
  for (auto i=0; i<snake.body.size; i++) {
    const point& p = snake.body[i];
    arduboy.drawBitmap(p.x*SPRITE_SIZE, p.y*SPRITE_SIZE, snakeSprite, SPRITE_SIZE, SPRITE_SIZE, WHITE);
  }

  //draw food
  arduboy.drawBitmap(food.x*SPRITE_SIZE, food.y*SPRITE_SIZE, foodSprite, SPRITE_SIZE, SPRITE_SIZE, WHITE);
}
