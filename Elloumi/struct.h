#include "defs.h"

// Structures qui seront utilisées pour gérer le jeu 

/ Structure pour gérer l'input

typedef struct Input
{
	int left, right, up, down, hold, pause;
} Input;


// Structure pour gérer le niveau  

typedef struct Gestion
{

    SDL_Surface *screen;
    int nombreMonstres;
    int level;

    //HUD
	SDL_Surface *HUD_scores;
    int scores;

    //Sons
    Mix_Music  *musique;

    //Sounds Fx
    Mix_Chunk  *bumper_sound, *destroy_sound, *jump_sound, *star_sound;

    //Gestion des menus
    int onMenu, menuType, choice;


} Gestion;


// Structure pour gérer la map à afficher 

typedef struct Map
{

	SDL_Surface *background, *tileSet;
	SDL_Surface *tileSetB;

	/* Coordonnées de début, lorsqu'on doit dessiner la map */
	int startX, startY;

	/* Coordonnées max de fin de la map */
	int maxX, maxY;

	/* Tableau à double dimension représentant la map de tiles */
	int tile[MAX_MAP_Y][MAX_MAP_X];

	/* Timer et numéro du tileset à afficher pour animer la map */
	int mapTimer, tileSetNumber;

} Map;


/* Structure pour gérer notre héros */

typedef struct GameObject
{
    //Sprite du héros (pas d'animation pour l'instant)
	SDL_Surface *sprite;

	/* Coordonnées du héros */
	int x, y;
	/* Largeur, hauteur du sprite */
	int h, w;

	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
	int etat, direction;

	/* Variables utiles pour la gestion des collisions */
	int onGround, timerMort;
	float dirX, dirY;
	int saveX, saveY;




} GameObject;

