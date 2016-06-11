/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 09 June 2016
**
** Source File for Entities
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "entity.hpp"

Entity::Entity() : type(0)
{

}

Entity::~Entity()
{

}

void Entity::setType(int ent)
{
    type = ent;
}

int Entity::getType()
{
    return type;
}
