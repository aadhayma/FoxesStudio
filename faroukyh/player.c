//fonction pour l affichage de notre Personnage
void drawplayer()
{
    /* Rectangle de destination � blitter */
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    dest.w = PLAYER_WIDTH;//d�finir la hauteur et la largeur de notre Personnage.
    dest.h = PLAYER_HEIGTH;//d�finir la hauteur et la largeur de notre Personnage

    /* Rectangle source � blitter */
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre Personnage sur l'�cran aux coordonn�es x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}
