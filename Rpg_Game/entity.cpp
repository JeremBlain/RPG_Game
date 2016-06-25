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

Entity::Entity() : type(0), ID(0), pos(0, 0)
{}

Entity::Entity(int posx, int posy, int id) : type(0), ID(id), pos(posx, posy)
{}

Entity::~Entity()
{}

void Entity::setType(int ent)
{
    type = ent;
}

int Entity::getType()
{
    return type;
}

void Entity::setPosition(int posx, int posy)
{
    pos.setPosition(posx, posy);
}

vec2 Entity::getPosition()
{
    return pos.getPosition();
}


//Outside the Entity Class
int convert_strToEnt(QString ent)
{
    ent = ent.simplified(); //remove \n, \t etc...
    if( QString::compare(ent, "character", Qt::CaseInsensitive) == 0 )
        return charac;

    if(QString::compare(ent, "main_character", Qt::CaseInsensitive) == 0)
            return main_charac;

    if(QString::compare(ent, "building", Qt::CaseInsensitive) == 0)
        return building;

    return ground;
}
