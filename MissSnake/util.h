#pragma once


void printScore(uint8_t x, uint8_t y, uint8_t score, uint8_t size)
{
  char text[4];
  
  arduboy.setTextSize(size);
  arduboy.setCursor(x, y);
  
  sprintf(text, "%03u", score);
  
  arduboy.print(text);
}


void printText(uint8_t x, uint8_t y, const char* text, uint8_t size)
{
  arduboy.setTextSize(size);
  arduboy.setCursor(x, y);
  arduboy.print(text);
}
