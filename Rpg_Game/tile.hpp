/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 30 June 2016
**
** Head File for tile
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef TILE_H
#define TILE_H

#include <typeinfo>
#include <iostream>
#include <QRect>

#include "character.hpp"
#include "building.hpp"
#include "ground.hpp"


#define sizeTile 42

class Tile
{
    // private attributes
private:
    Entity *entity;
    Ground *ground;

    // public methods
public:
    Tile(Entity* ent);

    /******* Get Entity TYPE *******
     * Get the type of the entity, return the value of the enum */
    int getEntityType();

    /****** Set Entity******
    * call the function of Tile to set the entity of the  */
    void  setEntity(Entity *ent);

    /****** Get Entity******
    * call the function of Tile to get the entity of the  */
    Entity* getEntity();

    /******* Set Position *******
     * Set the position in the map of the entity */
    void setPosition(int posx, int posy);

    /******* Get Position *******
     * Get the position in the map of the entity */
    vec2 getPosition();

    /******* Get ID *******
     * Get the id of the entity */
    int getEntityId();
};

#endif // TILE_H

/* *********** FOOTER ************
** Version : 1.00
** Last update : 30 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -
** ******************************/
