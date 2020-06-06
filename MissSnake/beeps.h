#pragma once

void playPressTune()
{
  tunes.tone(425, 20);
}


void playAdvanceTune()
{
  tunes.tone(512, 10);
  delay(10);
}

void playEatTune()
{
  //verify
  //if (canMakeSound) {   
    tunes.tone(500, 50);
    delay(80);
    tunes.tone(800, 50);
    delay(80);
    tunes.tone(1100, 100);
  //}  
}

void playDeadTune()
{
  // Génération d'un son de défaite si le son est activé
  //if (canMakeSound) {
    tunes.tone(1100, 80);
    delay(100);
    tunes.tone(1000, 80);
    delay(100);
    tunes.tone(500, 500);
  //}
}
