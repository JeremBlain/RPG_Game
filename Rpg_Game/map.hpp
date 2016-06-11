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

#define NbTile 30

class Map
{
    // private attributes
private:
    Tile* map[NbTile][NbTile];

    //public methods
public:
    Map(); //constructor
    ~Map(); //destructor

    /****** Get Tile ******
    * call the function of Tile to Get the rectangle of the tile */
    const QRect* getTile(int kx, int ky);

    /****** Get Entity ******
    * call the function of Entity to set the type like character or house */
    int getEntityType(int kx, int ky);
};

#endif // MAP_HPP


/* *********** FOOTER ************
** Version : 1.01
** Last update : 08 June 2016
** Changes : -Creation of the file and the map
**           -methods to get the type of entity
** ******************************/

