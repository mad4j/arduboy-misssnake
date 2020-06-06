#pragma once

#include "point.h"

struct queue {

  point items[256];
  uint8_t first;
  uint8_t size;

  queue() : first(0), size(0), items() { };
  
  bool full() const 
  { 
    return (size == 255); 
  };
  
  bool empty() const 
  { 
    return (size == 0); 
  };

  bool contains(const point& v) const
  {
    for (auto i=0; i<size; i++) {
      if (items[(first+i)%256] == v) {
        return true;
      }
    }
    return false;
  }

  void reset() 
  {
    first = 0;
    size = 0;
  }

  const point& operator[](uint8_t index) 
  { 
    return items[(first+index)%256]; 
  }

  void insert(const point& v) 
  {
    if (!full()) {
      items[(first+size)%256] = v; 
      size++;
    }
  }
  
  const point& remove() 
  {
    const point& v = items[first];
    if (!empty()) {
       first = (first+1)%256;
       size--;
       return v;
    } 
    return v;
  }
  
};
