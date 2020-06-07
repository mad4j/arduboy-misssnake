#pragma once

struct point {

  uint8_t x;
  uint8_t y;

  point();
  point(int dx, int dy);

  point& operator=(const point& p);
  point& operator+=(const point& p);  
  bool operator==(const point& p) const;

  bool within(const point& p1, const point& p2) const;

  void replace(const point& p1, const point& p2);
};

point::point() : x(0), y(0) { }
point::point(int dx, int dy) : x((dx+256)%256), y((dy+256)%256) { }

point& point::operator=(const point& p)
{
  x = p.x;
  y = p.y;
}

point& point::operator+=(const point& p) 
  {
    x = (x+p.x) % 256;
    y = (y+p.y) % 256;
    return *this;
  }

bool point::operator==(const point& p) const
{
  return (x == p.x) && (y == p.y);
}

bool point::within(const point& p1, const point& p2) const 
{
  return (x>p1.x) && (x<p2.x) && (y>p1.y) && (y<p2.y);
}

void point::replace(const point& p1, const point& p2)
{
  x = random(p1.x+1, p2.x);
  y = random(p1.y+1, p2.y);
}
