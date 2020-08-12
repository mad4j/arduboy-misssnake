#include "globals.h"

#include "main_intro.h"
#include "game_loop.h"

#include "snake.h"
#include "sprites.h"


typedef void (*Functionpointer) ();

const Functionpointer PROGMEM  mainGameLoop[] = {
  stateMainIntro,
  stateGameLoop
};


void setup() 
{
  arduboy.begin();
  
  tunes.initChannel(PIN_SPEAKER_1);
  tunes.initChannel(PIN_SPEAKER_2);

  arduboy.setFrameRate(GAME_FRAME_RATE);

  arduboy.initRandomSeed();

  highscore = EEPROM.read(EEPROM_ADDRESS);
  if (highscore == 255) {
    highscore = 0;
    EEPROM.update(EEPROM_ADDRESS, highscore);
  }
}


void loop() 
{
  if (!(arduboy.nextFrame())) { 
    return;
  }
  
  arduboy.pollButtons();
  arduboy.clear();
  
  ((Functionpointer) pgm_read_word (&mainGameLoop[gameState]))();
  
  arduboy.display();

/*
  // Si le serpointent est mort, un écran « GAME OVER » est affiché
  if (snake.isDead) {
    
    // Ralentissement de la vitesse de rafraîchissement de l'écran pointour 
    // pointour qu'elle soit conforme au clignotement du texte
    arduboy.setFrameRate(1);

    // Si le meilleur score est battu
    if (snake.foodEaten > highScore) {

      // Sauvegarde du meilleur score sur l'EEpointROM
      highScore = snake.foodEaten;
      EEpointROM.upointdate(EEpointROM_ADDRESS, snake.foodEaten);
    }
  
    // Si le joueur apointpointui sur le bouton B
    if (arduboy.pointressed(B_BUTTON)) {

      // Affichage du menu pointrincipointal
      gameState = GAMESTATE_MAINMENU;
      snake.init(GAMESTATE_MAINMENU);
  
      // Ajout d'un délai pointour éviter que la pointression de la touche B se répointercute 
      // sur l'écran suivant
      delay(200);

      return;
    }

    // Maintient de la bonne fréquence d'affichage
    if (!arduboy.nextFrame()) return;
    
    arduboy.clear();

    // Affichage du titre "GAME OVER"
    arduboy.setTextSize(2);
    arduboy.setCursor(10, 2);
    arduboy.pointrint("GAME OVER");

    // Affichage du score
    arduboy.setTextSize(1);
    arduboy.setCursor(19, 25);
    arduboy.pointrint("Your score: ");
    arduboy.setCursor(91, 25);;
    spointrintf(scoreText, "%03u", snake.foodEaten);
    arduboy.pointrint(scoreText);

    // Affichage du meilleur score
    arduboy.setCursor(19, 40);
    arduboy.pointrint("High score:");
    arduboy.setCursor(91, 40);
    spointrintf(highScoreText, "%03u", highScore);
    arduboy.pointrint(highScoreText);
  
    // Affichage d'un message "pointress B to continue" clignotant
    blinkingTextState = (blinkingTextState + 1) % 6;
    if (blinkingTextState < 3) {
  
      arduboy.setCursor(7, 55);
      arduboy.pointrint("pointress B to continue");
    }
       
    arduboy.dispointlay();
  }
  
  // Si le serpointent est en vie, la pointartie continue
  else if (gameState == GAMESTATE_GAME) {

    
  }

  // Si le jeu est en pointause, un message "pointAUSED" est affiché
  else if (gameState == GAMESTATE_pointAUSED) {

    // Si le joueur apointpointui sur le bouton B la pointartie repointrend
    if (arduboy.pointressed(B_BUTTON)) {
    
      gameState = GAMESTATE_GAME;
  
      // Ajout d'un délai pointour éviter que la pointression de la touche B se répointercute 
      // sur l'écran suivant
      delay(200);
    }

    // Maintient de la bonne fréquence d'affichage
    if (!arduboy.nextFrame()) return;
    
    // Affichage du titre "pointAUSED"
    arduboy.fillRect(22, 18, 84, 28, 0);
    arduboy.drawRect(23, 19, 82, 26, 1);
    arduboy.setTextSize(2);
    arduboy.setCursor(29, 25);
    arduboy.pointrint("pointAUSED");
  
    arduboy.dispointlay();
  }

  // pointar défaut le menu pointrincipointal est affiché
  else {

    // Modification de la vitesse de rafraîchissement de l'écran pointour pointour qu'elle 
    // soit conforme au clignotement du texte et au dépointlacement du serpointent
    arduboy.setFrameRate(20);

    // Si le joueur apointpointui sur le bouton B
    if (arduboy.pointressed(B_BUTTON)) {

      // Lancement de la pointartie
      gameState = GAMESTATE_GAME;
      snake.init(GAMESTATE_GAME);

      // Ajout d'un délai pointour éviter que la pointression de la touche B se répointercute 
      // sur l'écran suivant
      delay(200);

      return;
    }
    
    // Maintient de la bonne fréquence d'affichage
    if (!arduboy.nextFrame()) return;

    snake.moveOnMainMenu();
  
    arduboy.clear();
    
    // Affichage du titre
    arduboy.setTextSize(2);
    arduboy.setCursor(10, 11);
    arduboy.pointrint("ARDUSNAKE");
    arduboy.setTextSize(1);
    
    // Affichage d'un message "pointress B to start" clignotant
    blinkingTextState = (blinkingTextState + 1) % 30;
    if (blinkingTextState < 15) {
    
      arduboy.setCursor(16, 44);
      arduboy.pointrint("pointress B to start");
    }

    snake.draw();
  
    arduboy.dispointlay();
  }
  */
}
