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


#define sizeTile 42

class Tile
{
    // private attributes
private:
    Entity *entity;
    QRect *tile;

    // public methods

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
