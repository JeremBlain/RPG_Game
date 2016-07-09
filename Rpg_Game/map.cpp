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
    QMap<vec2, int> groundMap = get_ground_mapFile();

    vec2 pos;
    int kx=0, ky=0;
    Entity* E; Ground* G;
    for(kx=0; kx<NbTile; ++kx)
    {
        for(ky=0; ky<NbTile; ++ky)
        {
            pos.setPosition(kx, ky);

            if(groundMap.contains(pos))
            {
                int gr = groundMap.value(pos);

                G = new Ground(gr);
            }

            if(entity_idMap.contains(pos))
            {
                vec2 ent_id = entity_idMap.value(pos);
                int ent = ent_id.getx(), id = ent_id.gety();
                if(ent == main_charac)
                {
                    QString name = get_name_mainCharacter();
                    Dragon dragonData[5];
                    int nbrDrag = get_dragons_main_character(dragonData);
                    main_character = new Character(pos.getx(), pos.gety(), name, id, nbrDrag, dragonData);
                    main_character->setType(main_charac);
                    E = main_character;
                }

                if(ent == charac)
                {
                    QString name = get_name_character(id);
                    E = new Character(pos.getx(), pos.gety(), name, id, 0, nullptr);
                }

                if(ent == building)
                    E = new Building(pos.getx(), pos.gety(), id);
            }

            else
                E = nullptr;

            map[kx][ky] = new Tile(E, G); //E = Entity class, G = Ground class
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

int Map::getGroundType(int kx, int ky)
{
    return map[kx][ky]->getGroundType();
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

QString Map::getMainCharacterDragonName(int n)
{
    return main_character->getDragonName(n);
}

QString Map::getMainCharacterDragonSurname(int n)
{
    return main_character->getDragonSurname(n);
}

int Map::getMainCharacterDragonType(int n)
{
    return main_character->getDragonType(n);
}

int Map::getMainCharacterDragonLevel(int n)
{
    return main_character->getDragonLevel(n);
}

int Map::getMainCharacterNBDragon()
{
    return main_character->getNBDragon();
}

Attack *Map::getMainCharacDragonAttack(int n)
{
    return main_character->getDragonAttack(n);
}

int Map::getMainCharacDragonAttackNB(int n)
{
    return main_character->getDragonAttackNB(n);
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
    //if Entity is null, there is no entity and the mv is valid if ent == ground == 0
    if(map[posx][posy]->getEntity() == nullptr)
    {
        if(ent == ground)
            return true;

        return false;
    }

    if(map[posx][posy]->getEntityType() == ent)
        return true;

    return false;
}

