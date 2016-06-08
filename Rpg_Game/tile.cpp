/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for tile
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "tile.hpp"

Tile::Tile(int x_debut, int y_debut)
{
    charac = new Character();
    tile = new QRect(x_debut, y_debut, sizeTile, sizeTile);
}

Tile::~Tile()
{
    delete this;
}

const QRect* Tile::get_Tile()
{
    return tile;
}

