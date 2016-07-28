/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 23 June 2016
**
** Source File for characters
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "building.hpp"

Building::Building() :Entity()
{
    type = building;
}

Building::Building(int posx, int posy, int id) : Entity(posx, posy, id)
{
    type = building;
}
