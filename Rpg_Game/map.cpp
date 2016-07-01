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
    int kx=0, ky=0;
    for(kx=0; kx<NbTile; ++kx)
    {
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
                    map[kx][ky] = new Tile(main_character);
                }

                if(ent == charac)
                {
                    QString name = get_name_character(ent_id.gety());
                    Character* character = new Character(pos.getx(), pos.gety(), name, id);
                    map[kx][ky] = new Tile(character);
                }

                if(ent == building)
                    map[kx][ky] = new Tile(new Building(pos.getx(), pos.gety(), id));
            }

            else
                map[kx][ky] = new Tile(nullptr);
        }
    }
}

Map::~Map()
{
    delete this;
}

Entity* Map::getTileEntity(int kx, int ky)
{
    return map[kx][ky]->getEntity();
}

Entity* Map::getTileEntity(vec2 pos)
{
    int kx = pos.getx();
    int ky = pos.gety();
    return map[kx][ky]->getEntity();
}

int Map::getEntityType(int kx, int ky)
{
    if(map[kx][ky]->getEntity() != nullptr)
        return map[kx][ky]->getEntityType();

    return 0;
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

QString Map::getMainCharacName()
{
    return main_character->getName();
}

void Map::setCharacOrientation(int posx, int posy, int orien)
{
    Entity* current_tile = getTileEntity(posx, posy);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        character->setOrientation(orien);
    }
}

int Map::getCharacOrientation(int posx, int posy)
{
    Entity* current_tile = getTileEntity(posx, posy);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        return character->getOrientation();
    }

    return 0;
}

QString Map::getCharacName(int kx, int ky)
{
    Entity* current_tile = getTileEntity(kx, ky);
    if(current_tile->getType() == charac || current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        return character->getName();
    }

    return "";
}

int Map::getEntityID(int kx, int ky)
{
    return map[kx][ky]->getEntityId();
}

void Map::moveCharacter(int posx, int posy, int mv)
{
    Entity* current_tile = getTileEntity(posx, posy);
    if(current_tile->getType() == main_charac)
    {
        Character* character = dynamic_cast<Character*>(current_tile);

        if(mv == up)
        {
            character->deplacement(up);
            map[posx][posy-1]->setEntity(current_tile);
        }

        if(mv == mv_right)
        {
            character->deplacement(mv_right);
            map[posx+1][posy]->setEntity(current_tile);
        }

        if(mv == bottom)
        {
            character->deplacement(bottom);
            map[posx][posy+1]->setEntity(current_tile);
        }

        if(mv == mv_left)
        {
            character->deplacement(mv_left);
            map[posx-1][posy]->setEntity(current_tile);
        }

        map[posx][posy]->setEntity(nullptr);
    }
}


bool Map::isType(int posx, int posy, int ent)
{
    //if Entity is null, there is no entity and the mv is valid
    if(map[posx][posy]->getEntity() == nullptr)
            return true;

    if(map[posx][posy]->getEntityType() == ent)
        return true;

    return false;
}

