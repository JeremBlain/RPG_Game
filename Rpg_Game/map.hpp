/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Head File for the map of the game
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef MAP_HPP
#define MAP_HPP

/* The map is divided by tiles
 * characters walk on this tile and only in it.
 * We implement the map with a class.
 */
#include "tile.hpp"

#define NbTile 50

class Map
{
    // private attributes
private:
    Tile* map[NbTile][NbTile];

    //public methods
public:
    Map(); //constructor
    ~Map(); //destructor

    //operator
    const QRect* getTile(int kx, int ky);
};

#endif // MAP_HPP


/* *********** FOOTER ************
** Version : 1.00
** Last update : 08 June 2016
** Changes : Creation of the file and the map
** ******************************/

