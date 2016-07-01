/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 30 June 2016
**
** Source File for tile
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "tile.hpp"

Tile::Tile(Entity *ent)
{
    entity = ent;
    ground = new Ground(dirt);
}

int Tile::getEntityType()
{
        return entity->getType();
}

void Tile::setEntity(Entity* ent)
{
    entity = ent;
}

Entity* Tile::getEntity()
{
    return entity;
}

void Tile::setPosition(int posx, int posy)
{
    entity->setPosition(posx, posy);
}

vec2 Tile::getPosition()
{
    return entity->getPosition();
}

int Tile::getEntityId()
{
    return entity->getId();
}
