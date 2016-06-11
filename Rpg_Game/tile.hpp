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
#include "null_entity.hpp"
#include <QRect>

#define sizeTile 32

class Tile
{
    // private attributes
private:
    Entity *entity;
    QRect *tile;

    // public methods
public:
    Tile(int x_debut, int y_debut); //constructor
    ~Tile(); //destructor

    /******* Get Tile *******
     * Get the rectangle of the Tile */
    const QRect* get_Tile();

    /******* Set Entity *******
     * call the function of Entity to set the type like character or house */
    void setEntity(int ent);

    /******* Get Entity *******
     * call the function of Entity to get the type like character or house */
    int getEntity();

    /******* to move the character */
    void mvment(int mv);
};

#endif // TILE_H

/* *********** FOOTER ************
** Version : 1.01
** Last update : 08 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -method to set&get the type of the entity
** ******************************/
