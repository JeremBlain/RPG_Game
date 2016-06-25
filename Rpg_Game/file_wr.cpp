
/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 18 June 2016
**
** Source File for data file write and read
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "file_wr.hpp"

void files_exist()
{
    QFile tabFile[3];

    //creation of the map file if it don't exist
    tabFile[0].setFileName("../data/mapdata.txt");
    if (!tabFile[0].exists("../data/mapdata.txt") )
    {
        create_mapFile(tabFile);
    }

    tabFile[1].setFileName("../data/main_character_data.txt");
    if (!tabFile[1].exists("../data/main_character_data.txt") )
    {
        create_mainCharacterFile(tabFile+1);
    }

    tabFile[2].setFileName("../data/character_data.txt");
    if (!tabFile[2].exists("../data/character_data.txt") )
    {
        create_characterFile(tabFile+2);
    }
}


bool create_mapFile(QFile* file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Map Data File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Map Data File not created /!\\"<<std::endl;
    return false;
}

bool create_mainCharacterFile(QFile* file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Main Character File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Main Character Data File not created /!\\"<<std::endl;
    return false;
}

bool create_characterFile(QFile *file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Character File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Character Data File not created /!\\"<<std::endl;
    return false;
}

QMap<vec2, vec2> get_entities_mapFile()
{
    QMap<vec2, vec2> entity_idMap;
    QFile mapDataFile("../data/mapdata.txt");

    if( mapDataFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString line; //get the entity and coord line by line
        vec2 pos; int coordx = 0, coordy = 0;  //pos = position on the map
        vec2 ent_id; //the enum entity and the id
        std::cout<<"the file is open"<<std::endl;
        while(!mapDataFile.atEnd())
        {
            line = mapDataFile.readLine();
            coordx = line.section(' ', 0, 0).toInt();
            coordy = line.section(' ', 1, 1).toInt();
            pos.setPosition(coordx, coordy);

            ent_id.setPosition( convert_strToEnt(line.section(' ', 2, 2)) , line.section(' ', 3, 3).toInt() );
            entity_idMap.insert(pos, ent_id);
        }
        mapDataFile.close();
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
    }

    return entity_idMap;
}


QString get_name_mainCharacter()
{
    QFile mainCharacterFile("../data/main_character_data.txt");

    if( mainCharacterFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString name; //get the entity and coord line by line
        name = mainCharacterFile.readLine();
        mainCharacterFile.close();
        return name;
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
        return "";
    }
}

QString get_name_character(int id)
{
    QFile characterFile("../data/character_data.txt");

    if( characterFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString line = "";
        while(!characterFile.atEnd())
        {
            line = characterFile.readLine();
            int idFile = line.section(' ', 0, 0).toInt();
            if(id == idFile)
            {
                QString name; //get the entity and coord line by line
                name = line.section(' ', 1, 1);
                characterFile.close();
                return name;
            }
        }
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
    }
    return "";
}



