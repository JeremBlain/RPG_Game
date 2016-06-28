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
    files_exist();

    QMap<vec2, vec2> entity_idMap = get_entities_mapFile();

    vec2 pos;
    int kx=0;
    for(kx=0; kx<NbTile; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile; ++ky)
        {
            pos.setPosition(kx, ky);

            if(entity_idMap.contains(pos))
            {
                vec2 ent_id = entity_idMap.value(pos);
                int ent = ent_id.getx(), id = ent_id.gety();
                if(ent == main_charac)
                {
                    QString name = get_name_mainCharacter();
                    main_character = new Character(pos.getx(), pos.gety(), name, id);
                    main_character->setType(main_charac);
                    map[kx][ky] = main_character;
                }

                if(ent == charac)
                {
                    QString name = get_name_character(ent_id.gety());
                    map[kx][ky] = new Character(pos.getx(), pos.gety(), name, id);
                }

                if(ent == building)
                    map[kx][ky] = new Building(pos.getx(), pos.gety(), id);
            }

            else
                map[kx][ky] = new Ground(kx, ky);
        }
    }
}

Map::~Map()
{
    delete this;
}

Entity *Map::getEntity(int kx, int ky)
{
    return map[kx][ky];
}

Entity *Map::getEntity(vec2 pos)
{
    int kx = pos.getx();
    int ky = pos.gety();
    return map[kx][ky];
}

int Map::getEntityType(int kx, int ky)
{
    return map[kx][ky]->getType();
}

void Map::setEntityPosition(int kx, int ky)
{
    map[kx][ky]->setPosition(kx, ky);
}

vec2 Map::getEntityPosition(int kx, int ky)
{
    return map[kx][ky]->getPosition();
}

vec2 Map::getMainCharacPosition()
{
    return main_character->getPosition();
}

void Map::setMainCharacOrientation(int orien)
{
    main_character->setOrientation(orien);
}

int Map::getMainCharacOrientation()
{
    return main_character->getOrientation();
}

void Map::setCharacOrientation(int posx, int posy, int orien)
{
    Entity* current_tile = getEntity(posx, posy);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        character->setOrientation(orien);
    }
}

int Map::getCharacOrientation(int posx, int posy)
{
    Entity* current_tile = getEntity(posx, posy);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        return character->getOrientation();
    }

    return 0;
}

QString Map::getCharacName(int kx, int ky)
{
    Entity* current_tile = getEntity(kx, ky);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        return character->getName();
    }

    return "";
}

int Map::getEntityID(int kx, int ky)
{
    return map[kx][ky]->getId();
}

void Map::moveCharacter(int posx, int posy, int mv)
{
    Entity* current_tile = getEntity(posx, posy);
    if(current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        Entity* tmp_tile = nullptr;
        if(mv == up)
        {
            tmp_tile = getEntity(posx, posy-1);
            character->deplacement(up);
            map[posx][posy-1] = current_tile;
        }

        if(mv == right)
        {
            tmp_tile = getEntity(posx+1, posy);
            character->deplacement(right);
            map[posx+1][posy] = current_tile;
        }

        if(mv == bottom)
        {
            tmp_tile = getEntity(posx, posy+1);
            character->deplacement(bottom);
            map[posx][posy+1] = current_tile;
        }

        if(mv == left)
        {
            tmp_tile = getEntity(posx-1, posy);
            character->deplacement(left);
            map[posx-1][posy] = current_tile;
        }

        map[posx][posy] = tmp_tile;
        map[posx][posy]->setPosition(posx, posy);
    }
}


bool Map::isType(int posx, int posy, int ent)
{
   if (map[posx][posy]->getType() == ent)
       return true;

   return false;
}

