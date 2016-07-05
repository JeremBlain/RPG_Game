
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
    QFile tabFile[7];

    //creation of the map file if it don't exist
    tabFile[0].setFileName("../data/map_entity_data.txt");
    if (!tabFile[0].exists("../data/map_entity_data.txt") )
    {
        create_File(tabFile);
    }

    tabFile[1].setFileName("../data/main_character_data.txt");
    if (!tabFile[1].exists("../data/main_character_data.txt") )
    {
        create_File(tabFile+1);
    }

    tabFile[2].setFileName("../data/character_data.txt");
    if (!tabFile[2].exists("../data/character_data.txt") )
    {
        create_File(tabFile+2);
    }

    tabFile[3].setFileName("../data/dialog_data.txt");
    if (!tabFile[3].exists("../data/dialog_data.txt") )
    {
        create_File(tabFile+3);
    }

    tabFile[4].setFileName("../data/map_ground_data.txt");
    if (!tabFile[4].exists("../data/map_ground_data.txt") )
    {
        create_File(tabFile+4);
    }

    tabFile[5].setFileName("../data/dragon_data.txt");
    if (!tabFile[5].exists("../data/dragon_data.txt") )
    {
        create_File(tabFile+5);
    }

    tabFile[6].setFileName("../data/attack_data.txt");
    if (!tabFile[6].exists("../data/attack_data.txt") )
    {
        create_File(tabFile+6);
    }
}

bool create_File(QFile* file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\File not created /!\\"<<std::endl;
    return false;
}


QMap<vec2, vec2> get_entities_mapFile()
{
    QMap<vec2, vec2> entity_idMap;
    QFile mapDataFile("../data/map_entity_data.txt");

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


QMap<vec2, int> get_ground_mapFile()
{
    QMap<vec2, int> ground_Map;

    QFile groundMapDataFile("../data/map_ground_data.txt");

    if( groundMapDataFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString line; //get the entity and coord line by line
        vec2 pos; int coordx = 0, coordy = 0;  //pos = position on the map
        int gr=0; //the enum ground
        std::cout<<"the file is open"<<std::endl;
        while(!groundMapDataFile.atEnd())
        {
            line = groundMapDataFile.readLine();
            coordx = line.section(' ', 0, 0).toInt();
            coordy = line.section(' ', 1, 1).toInt();
            pos.setPosition(coordx, coordy);

            gr = convert_strToGround(line.section(' ', 2, 2));
            ground_Map.insert(pos, gr);
        }
        groundMapDataFile.close();
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
    }

    return ground_Map;
}


QString get_name_mainCharacter()
{
    QFile mainCharacterFile("../data/main_character_data.txt");

    if( mainCharacterFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString name; //get the entity and coord line by line
        name = mainCharacterFile.readLine().simplified();
        mainCharacterFile.close();
        return name;
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
        return "";
    }
}


void get_dragons_main_character(Dragon* dragonTab)
{
    QFile mainCharacterFile("../data/main_character_data.txt");

    if( mainCharacterFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QString name, surname; int type, level, hp;
        mainCharacterFile.readLine();
        int statTab[4];

        int i=0;
        while(!mainCharacterFile.atEnd())
        {
            QString line = mainCharacterFile.readLine();

            name = line.section(' ', 0, 0);
            surname = line.section(' ', 1, 1);
            type = convert_strToType(line.section(' ', 2, 2));
            level = line.section(' ', 3, 3).toInt();
            hp = line.section(' ', 4, 4).toInt();
            statTab[0] = line.section(' ', 5, 5).toInt();
            statTab[1] = line.section(' ', 6, 6).toInt();
            statTab[2] = line.section(' ', 7, 7).toInt();
            statTab[3] = line.section(' ', 8, 8).toInt();

            dragonTab[i] = Dragon(name, surname, type, level, hp, statTab);

            i++;
        }

        mainCharacterFile.close();
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
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
                name = line.section(' ', 1, 1).simplified();
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

/* a dialog line in the file is :
 * # id "text" */
QString get_dialog_charac(int id)
{
    QFile dialogFile("../data/dialog_data.txt");

    if(dialogFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line = "", text=""; int idFile;

        while(!dialogFile.atEnd())
        {
            line = dialogFile.readLine();

            if(line.left(1) == "#") //the first char of a dialog must be #
            {
                idFile = line.section(' ', 1, 1).toInt();
                if(id == idFile)
                {
                    text.insert(0, line.section(' ', 2));
                    line = dialogFile.readLine();
                    while(line.left(1) != "#" && !dialogFile.atEnd()) //line.left(1) give the first char of the line
                    {
                        text.append(line);
                        line = dialogFile.readLine();
                    }//end of text of character
                    if(line.left(1) != "#") //if text is last one, not enter the while for append the last line
                         text.append(line); //so have to add an another append (but not if there is another text = not end of file)

                    return text;
                }
            }
        }
    }
    else
    {
        std::cout<<"the file is NOT open"<<std::endl;
    }
    return "";
}


void create_map_ground()
{
    QFile ground_map("../data/map_ground_data.txt");

    if(ground_map.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        srand(time(NULL));
        int randomNB;
        QTextStream out(&ground_map);

        int x =0, y=0;
        for(x=0; x<64; x++)
        {
            for(y=0; y<64; y++)
            {
                randomNB = rand()%4;
                if(randomNB == 0)
                    out<<x<<' '<<y<<" Dirt\n";
                if(randomNB == 1)
                    out<<x<<' '<<y<<" Grass\n";
                if(randomNB == 2)
                    out<<x<<' '<<y<<" Path\n";
                if(randomNB == 3)
                    out<<x<<' '<<y<<" River\n";
                if(randomNB == 4)
                    out<<x<<' '<<y<<" Sea\n";
            }
        }
    }
}




