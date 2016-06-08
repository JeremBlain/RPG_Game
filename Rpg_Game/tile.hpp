/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Head File for tile
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef TILE_H
#define TILE_H

#include "character.hpp"
#include <QRect>

#define sizeTile 50

class Tile
{
    // private attributes
private:
    Character *charac;
    QRect *tile;

    // public methods
public:
    Tile(int x_debut, int y_debut); //constructor
    ~Tile(); //destructor
    const QRect* get_Tile();
};

#endif // TILE_H

/* *********** FOOTER ************
** Version : 1.00
** Last update : 08 June 2016
** Changes : Creation and begining of implement attributes and method
** ******************************/
