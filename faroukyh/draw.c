 void draw(void)
{

    /* Affiche le fond (background) aux coordonn�es (0,0) */
    drawImage(map.background, 0, 0);

    /* Affiche la map de tiles */
    drawMap();

    /* Affiche le joueur */
    drawplayer();

    /* Affiche l'�cran */
    SDL_Flip(jeu.screen);

    /* Delai */

    SDL_Delay(1);

}
