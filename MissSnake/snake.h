#pragma once

#include "globals.h"
#include "point.h"
#include "queue.h"


struct Snake {
  
    point head;
    queue body;
    
    point direction;
    
    uint8_t grow;
    uint8_t speed;

    Snake();
    void init();
    void move();
   
    bool checkFood(const point& food) const;
    bool checkBody() const;
    bool checkBorder(const point& p1, const point& p2) const;
};


Snake::Snake() { }

void Snake::init() 
{
  direction = DIR_RIGHT;

  grow = 3;

  head = point(18, 8);
  body.reset();

    speed = 1;
}

void Snake::move() 
{
  body.insert(head);
  head += direction;
  
  if (grow > 0) {
    grow--;
  } else {
    body.remove();
  }
}

bool Snake::checkFood(const point& food) const 
{
  return (head == food);
}

bool Snake::checkBorder(const point& p1, const point& p2) const 
{ 
  return !head.within(p1, p2);
}

bool Snake::checkBody() const
{
  return body.contains(head);
}
