/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for tile
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "tile.hpp"

Tile::Tile(int kx, int ky, int type_entity)
{
    if(type_entity == null_entity)
         entity = new Null_entity(kx, ky);
    if(type_entity == charac)
         entity = new Character(kx, ky);

    tile = new QRect(kx*sizeTile, ky*sizeTile, sizeTile, sizeTile);
}

Tile::~Tile()
{
    delete this;
}


void Tile::setTypeEntity(int ent)
{
    entity->setType(ent);
}

void Tile::setEntity(Entity *ent)
{
    entity = ent;
}

int Tile::getTypeEntity() const
{
    return entity->getType();
}

void Tile::setPosition(int posx, int posy)
{
    entity->setPosition(posx, posy);
}

vec2 Tile::getPosition()
{
    return entity->getPosition();
}

void Tile::mvment(int mv)
{
        try{
            Character* character = dynamic_cast<Character*>(entity);
            character->deplacement(mv);
        }
        catch(const std::bad_cast &)
        {
            std::cout<<"not a character, cannot be moved"<<std::endl;
        }
}

