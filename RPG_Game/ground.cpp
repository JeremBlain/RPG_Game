/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for null_entities
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "ground.hpp"

Ground::Ground() : Entity()
{
    type = ground;
}

Ground::Ground(int posx, int posy) :  Entity(posx, posy, 0)
{
    type = ground;
}

Ground::~Ground()
{}

