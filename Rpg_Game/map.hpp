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
#include "character.hpp"
#include "ground.hpp"
#include "building.hpp"
#include "file_wr.hpp"

#define NbTile 64

class Map
{
    // private attributes
private:
    Entity* map[NbTile][NbTile];
    Character* main_character;

    //public methods
public:
    Map(); //constructor
    ~Map(); //destructor

    /****** Get Entity ******
    * call the function of Tile to Get the rectangle of the tile by coord
    * Not very usefull, only for encapsulation*/
    Entity* getEntity(int kx, int ky);

    /****** Get Entity******
    * call the function of Tile to Get the rectangle of the tile by vector
    * Not very usefull, only for encapsulation*/
    Entity* getEntity(vec2 pos);

    /****** Get Entity ******
    * call the function of Entity to set the type like character or house */
    int getEntityType(int kx, int ky);

    /****** Set Position ******
    * call the function of Tile to set the position in the map */
    void setEntityPosition(int posx, int posy);

    /****** Get Position ******
    * call the function of Tile to get the position in the map */
    vec2 getEntityPosition(int posx, int posy);

    /****** Get main character position ******
    * get the position of the main character */
    vec2 getMainCharacPosition();

    /****** Set main character orientation ******
    * Set the orientation of the main character */
    void setMainCharacOrientation(int orien);

    /****** Get main character orientation ******
    * get the orientation of the main character */
    int getMainCharacOrientation();

    /****** Set character orientation ******
    * get the orientation of the character */
    void setCharacOrientation(int posx, int posy, int orien);

    /****** Get character orientation ******
    * get the orientation of the character */
    int getCharacOrientation(int posx, int posy);

    /******* to move the character */
    void moveCharacter(int posx, int posy, int mv);

    /******* is the Type of Entity is same as parameter ? ******
    * return true if the type of entity is same as ent, or false if not */
    bool isType(int posx, int posy, int ent);
};

#endif // MAP_HPP


/* *********** FOOTER ************
** Version : 1.03
** Last update : 15 June 2016
** Changes : -Creation of the file and the map
**           -methods to get the type of entity
**           -add method for moving the character
**           -add method for set the position of the entity
** ******************************/

