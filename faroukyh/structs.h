#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

 /* Structure pour g�rer notre personnage */

   typedef struct Personnage
   {
       //Sprite du personnage (
       SDL_Surface *sprite;

       /* Coordonn�es du Personnage */
       int x, y;

   } Personnage;


#endif // STRUCTS_H_INCLUDED
