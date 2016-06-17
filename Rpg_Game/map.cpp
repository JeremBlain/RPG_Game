/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for the map of the game
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "map.hpp"

Map::Map()
{
    main_character = new Character(10,10);

    int kx=0;
    for(kx=0; kx<NbTile; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile; ++ky)
        {
            if(kx == 10 && ky == 10) //The main character is placed on the position 10,10
            {
                map[kx][ky] = new Tile(kx, ky, charac);
                map[kx][ky]->setEntity(main_character);
            }
            else
                map[kx][ky] = new Tile(kx, ky, null_entity);
        }
    }
}

Map::~Map()
{
    delete this;
}

const QRect* Map::getRectTile(int kx, int ky)
{
    return map[kx][ky]->getRectTile();
}

Tile *Map::getTile(int kx, int ky)
{
    return map[kx][ky];
}

Tile *Map::getTile(vec2 pos)
{
    int kx = pos.getx();
    int ky = pos.gety();
    return map[kx][ky];
}

int Map::getEntityType(int kx, int ky)
{
    return map[kx][ky]->getTypeEntity();
}

void Map::setEntityPosition(int posx, int posy)
{
    map[posx][posy]->setPosition(posx, posy);
}

vec2 Map::getEntityPosition(int posx, int posy)
{
    return map[posx][posy]->getPosition();
}

vec2 Map::getMainCharacPosition()
{
    return main_character->getPosition();
}

void Map::moveCharacter(int posx, int posy, int mv)
{
    Tile* current_tile = getTile(posx, posy);
    if(current_tile->getTypeEntity() == charac)
    {
        Tile* tmp_tile = nullptr;
        if(mv == up)
        {
            tmp_tile = getTile(posx, posy-1);
            current_tile->mvment(up);
            map[posx][posy-1] = current_tile;
            map[posx][posy-1]->setRectTile(posx, posy-1);
        }

        if(mv == right)
        {
            tmp_tile = getTile(posx+1, posy);
            current_tile->mvment(right);
            map[posx+1][posy] = current_tile;
            map[posx+1][posy]->setRectTile(posx+1, posy);
        }

        if(mv == bottom)
        {
            tmp_tile = getTile(posx, posy+1);
            current_tile->mvment(bottom);
            map[posx][posy+1] = current_tile;
            map[posx][posy+1]->setRectTile(posx, posy+1);
        }

        if(mv == left)
        {
            tmp_tile = getTile(posx-1, posy);
            current_tile->mvment(left);
            map[posx-1][posy] = current_tile;
            map[posx-1][posy]->setRectTile(posx-1, posy);
        }
        map[posx][posy] = tmp_tile;
        map[posx][posy]->setPosition(posx, posy);
        map[posx][posy]->setRectTile(posx, posy);
    }

}
