#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

Personnage player; //structure pour initialiser notre player//
 #include "structs.h"

  /* Prototypes des fonctions utilis�es */

  extern void init(char *);
  extern void cleanup(void);
  extern void getInput(void);
  extern void draw(void);
  extern void loadGame(void);
  extern void delay(unsigned int frameLimit);
  extern void update(void);
  extern void initializePlayer(void);


  /* D�claration des structures globales utilis�es par le jeu */

  Input input;
  Gestion jeu;
  Map map;
  Hero player;


#endif // MAIN_H_INCLUDED
