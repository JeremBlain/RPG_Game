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
    QFile mapDataFile("../data/mapdata.txt");
    if (!mapDataFile.exists() )
    {
        if ( create_file(mapFile) )
        {
            if( mapDataFile.open(QIODevice::ReadOnly | QIODevice::Text) )
            {
                std::cout<<"the file is open"<<std::endl;
                mapDataFile.close();
            }
            else
            {
                std::cout<<"the file is NOT open"<<std::endl;
            }

        }
    }



    main_character = new Character(20, 20);

    int kx=0;
    for(kx=0; kx<NbTile; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile; ++ky)
        {
            if(kx == 20 && ky == 20) //The main character is placed on the position 10,10
            {
                map[kx][ky] = main_character;
            }
            else
                map[kx][ky] = new Null_entity(kx, ky);
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
    Entity* current_tile = getEntity(posx, posy);
    if(current_tile->getType() == charac)
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
