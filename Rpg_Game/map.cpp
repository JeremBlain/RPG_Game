/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for the map of the game
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "map.hpp"

Map::Map()
{
    int kx=0;
    for(kx=0; kx<NbTile; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile; ++ky)
        {
            map[kx][ky] = new Tile(kx*sizeTile, ky*sizeTile);
        }
    }
}

Map::~Map()
{
    delete this;
}

const QRect* Map::getTile(int kx, int ky)
{
    return map[kx][ky]->get_Tile();
}
