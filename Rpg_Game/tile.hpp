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

#include <typeinfo>
#include <iostream>
#include <QRect>

#include "character.hpp"
#include "null_entity.hpp"


#define sizeTile 32

class Tile
{
    // private attributes
private:
    Entity *entity;
    QRect *tile;

    // public methods
public:
    Tile(int kx, int ky, int type_entity); //constructor
    ~Tile(); //destructor

    /******* Get Tile *******
     * Get the rectangle of the Tile */
    const QRect* getRectTile();

    /******* Set Tile *******
     * Get the rectangle of the Tile */
    void setRectTile(int kx, int ky);

    /******* Set Entity *******
     * call the function of Entity to set the type like character or house */
    void setTypeEntity(int ent);

    /******* Set Entity *******
     * call the function of Entity to set the entity */
    void setEntity(Entity *ent);

    /******* Get Entity *******
     * call the function of Entity to get the type like character or house */
    int getTypeEntity() const;

    /******* Set Position*******
     * call the function of Entity to set the position in the map */
    void setPosition(int posx, int posy);

    /******* Get Position*******
     * call the function of Entity to get the position in the map */
    vec2 getPosition();




    /******* to move the character */
    void mvment(int mv);
};

#endif // TILE_H

/* *********** FOOTER ************
** Version : 1.03
** Last update : 15 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -method to set&get the type of the entity
**           -add a parameter in the constructor
**           -add method for set the position of the entity
** ******************************/
