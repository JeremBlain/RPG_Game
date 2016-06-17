/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for characters
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "character.hpp"

Character::Character() : Entity(), name("")
{
    type = charac;
}

Character::Character(int posx, int posy) : Entity(posx, posy), name("")
{
    type = charac;
}

Character::Character(int posx, int posy, QString newName): Entity(posx, posy), name(newName)
{
    type = charac;
}

Character::~Character()
{
    delete this;
}

void Character::deplacement(int mv) //enum is {up, right, bottom, left}
{
    pos.movement(mv);
}


