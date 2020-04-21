  void drawMap(void)
 {
    int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

   /* On initialise mapX � la 1�re colonne qu'on doit blitter.
    Celle-ci correspond au x de la map (en pixels) divis�s par la taille d'une tile (32)
    pour obtenir la bonne colonne de notre map
    Exemple : si x du d�but de la map = 1026, on fait 1026 / 32
    et on sait qu'on doit commencer par afficher la 32eme colonne de tiles de notre map */
    mapX = map.startX / TILE_SIZE;

    /* Coordonn�es de d�part pour l'affichage de la map : permet
    de d�terminer � quels coordonn�es blitter la 1�re colonne de tiles au pixel pr�s
    (par exemple, si la 1�re colonne n'est visible qu'en partie, on devra commencer � blitter
    hors �cran, donc avoir des coordonn�es n�gatives - d'o� le -1). */
    x1 = (map.startX % TILE_SIZE) * -1;

    /* Calcul des coordonn�es de la fin de la map : jusqu'o� doit-on blitter ?
    Logiquement, on doit aller � x1 (d�part) + SCREEN_WIDTH (la largeur de l'�cran).
    Mais si on a commenc� � blitter en dehors de l'�cran la premi�re colonne, il
    va falloir rajouter une autre colonne de tiles sinon on va avoir des pixels
    blancs. C'est ce que fait : x1 == 0 ? 0 : TILE_SIZE qu'on pourrait traduire par:
    if(x1 != 0)
        x2 = x1 + SCREEN_WIDTH + TILE_SIZE , mais forc�ment, c'est plus long ;)*/
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

    /* On fait exactement pareil pour calculer y */
    mapY = map.startY / TILE_SIZE;
    y1 = (map.startY % TILE_SIZE) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);


    /* Dessine la carte en commen�ant par startX et startY */

    /* On dessine ligne par ligne en commen�ant par y1 (0) jusqu'� y2 (480)
    A chaque fois, on rajoute TILE_SIZE (donc 32), car on descend d'une ligne
    de tile (qui fait 32 pixels de hauteur) */

    for (y = y1; y < y2; y += TILE_SIZE)
    {
        /* A chaque d�but de ligne, on r�initialise mapX qui contient la colonne
        (0 au d�but puisqu'on ne scrolle pas) */

        mapX = map.startX / TILE_SIZE;

        /* A chaque colonne de tile, on dessine la bonne tile en allant
        de x = 0 � x = 640 */

        for (x = x1; x < x2; x += TILE_SIZE)
        {

            /* Suivant le num�ro de notre tile, on d�coupe le tileset */

            a = map.tile[mapY][mapX];

            /* Calcul pour obtenir son y (pour un tileset de 10 tiles
            par ligne, d'o� le 10 */

            ysource = a / 10 * TILE_SIZE;

            /* Et son x */

            xsource = a % 10 * TILE_SIZE;

            /* Fonction qui blitte la bonne tile au bon endroit */

            drawTile(map.tileSet, x, y, xsource, ysource);

            mapX++;
        }

        mapY++;
    }
  }
