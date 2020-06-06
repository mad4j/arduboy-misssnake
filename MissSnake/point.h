#pragma once

struct point {

  uint8_t x;
  uint8_t y;

  point() : x(0), y(0) { }
  point(int dx, int dy) : x((dx+256)%256), y((dy+256)%256) { }

  point& operator+=(const point& p) 
  {
    x = (x+p.x) % 256;
    y = (y+p.y) % 256;
    return *this;
  }

  bool operator==(const point& p) const 
  {
    return (x == p.x) && (y == p.y);
  }

  bool within(const point& p1, const point& p2) const 
  {
    return (x>p1.x) && (x<p2.x) && (y>p1.y) && (y<p2.y);
  }

  void replace(const point& p1, const point& p2) {
    x = random(p1.x+1, p2.x);
    y = random(p1.y+1, p2.y);
  }
};

//direction values
static const point DIR_UP    = point( 0, -1);
static const point DIR_DOWN  = point( 0,  1);
static const point DIR_RIGHT = point( 1,  0);
static const point DIR_LEFT  = point(-1,  0);

//gamefield logical corners
static const point P1 = point(0, 0);
static const point P2 = point(31, 15);
