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
#include "tile.hpp"

#define NbTile 64

class Map
{
    // private attributes
private:
    Tile* map[NbTile][NbTile];
    Character* main_character;

    //public methods
public:
    Map(); //constructor
    ~Map(); //destructor

    /****** Get Entity ******
    * call the function of Tile to Get the rectangle of the tile by coord
    * Not very usefull, only for encapsulation*/
    Entity* getTileEntity(int kx, int ky);

    /****** Get Entity******
    * call the function of Tile to Get the rectangle of the tile by vector
    * Not very usefull, only for encapsulation*/
    Entity *getTileEntity(vec2 pos);

    /****** Get Entity type ******
    * call the function of Entity to get the type like character or house */
    int getEntityType(int kx, int ky);

    /****** Get Ground type ******
    * call the function of Ground to get the type like dirt or sea */
    int getGroundType(int kx, int ky);

    /****** Set Position ******
    * call the function of Tile to set the position in the map */
    void setEntityPosition(int kx, int ky);

    /****** Get Position ******
    * call the function of Tile to get the position in the map */
    vec2 getEntityPosition(int kx, int ky);

    /****** Get main character position ******
    * get the position of the main character */
    vec2 getMainCharacPosition();

    /****** Set main character's orientation ******
    * Set the orientation of the main character */
    void setMainCharacOrientation(int orien);

    /****** Get main character's orientation ******
    * get the orientation of the main character */
    int getMainCharacOrientation();

    /****** Get main character's name ******
    * get the name of the main character */
    QString getMainCharacName();

    /******* Get name of dragon *******
     * get the name of the dragon, n is the number of the dragon in the table*/
    QString getMainCharacterDragonName(int n);

    /******* Get surname of dragon *******
     * get the surname of the dragon, n is the number of the dragon in the table*/
    QString getMainCharacterDragonSurname(int n);

    /******* Get type of dragon *******
     * get the type of the dragon, n is the number of the dragon in the table*/
    int getMainCharacterDragonType(int n);

    /******* Get level of dragon *******
     * get the level of the dragon, n is the number of the dragon in the table*/
    int getMainCharacterDragonLevel(int n);

    /****** Set character's orientation ******
    * get the orientation of the character */
    void setCharacOrientation(int posx, int posy, int orien);

    /****** Get character's orientation ******
    * get the orientation of the character */
    int getCharacOrientation(int posx, int posy);

    /****** Get character's name ******
    * get the orientation of the character */
    QString getCharacName(int kx, int ky);

    /****** Get character's ID ******
    * get the id of the character */
    int getEntityID(int kx, int ky);

    /******* to move the character */
    void moveCharacter(int posx, int posy, int mv);

    /******* is the Type of Entity is same as parameter ? ******
    * return true if the type of entity is same as ent, or false if not */
    bool isType(int posx, int posy, int ent);
};

#endif // MAP_HPP


/* *********** FOOTER ************
** Version : 1.04
** Last update : 1 July 2016
** Changes : -Creation of the file and the map
**           -methods to get the type of entity
**           -add method for moving the character
**           -add method for set the position of the entity
**           -map change from Entity to Tile (which contains Entity and ground infos)
** ******************************/

