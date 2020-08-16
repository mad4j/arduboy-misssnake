#pragma once

void playPressTune()
{
  tunes.tone(425, 20);
}

void playEatTune()
{
  tunes.tone(512, 10);
}

void playDeadTune()
{
  tunes.tone(1100, 80);
  delay(100);
  tunes.tone(1000, 80);
  delay(100);
  tunes.tone(500, 500);
}

void playWinTune()
{
  tunes.tone(500, 50);
  delay(80);
  tunes.tone(800, 50);
  delay(80);
  tunes.tone(1100, 100);
}
