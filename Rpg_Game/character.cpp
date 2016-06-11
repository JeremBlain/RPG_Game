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

Character::Character() : life(100), posX(0), posY(0)
{
    type = charac;
}

Character::Character(int posx, int posy) : life(100), posX(posx), posY(posy)
{

}

Character::~Character()
{
    delete this;
}

void Character::deplacement(int mv) //enum is {up, right, bottom, left}
{
    if(mv == up)
        posY--;

    if(mv == right)
        posX++;

    if(mv == bottom)
        posY++;

    if(mv == left)
        posX--;
}


