
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
    QFile tabFile[5];

    //creation of the map file if it don't exist
    tabFile[0].setFileName("../data/map_entity_data.txt");
    if (!tabFile[0].exists("../data/map_entity_data.txt") )
    {
        create_mapEntityFile(tabFile);
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

    tabFile[3].setFileName("../data/dialog_data.txt");
    if (!tabFile[3].exists("../data/dialog_data.txt") )
    {
        create_dialogFile(tabFile+3);
    }

    tabFile[4].setFileName("../data/map_ground_data.txt");
    if (!tabFile[4].exists("../data/map_ground_data.txt") )
    {
        create_dialogFile(tabFile+4);
    }
}


bool create_mapEntityFile(QFile* file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Map Entity Data File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Map Entity Data File not created /!\\"<<std::endl;
    return false;
}

bool create_mapGroundFile(QFile *file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Map Ground Data File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Map Ground Data File not created /!\\"<<std::endl;
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

bool create_dialogFile(QFile *file)
{
    if( file->open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Dialog File created"<<std::endl;
        file->close();
        return true;
    }

    std::cout<<"/!\\ Dialog Data File not created /!\\"<<std::endl;
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
        QTextStream out(&ground_map);

        int x =0, y=0;
        for(x=0; x<64; x++)
        {
            for(y=0; y<64; y++)
            {
                out<<x<<' '<<y<<" Dirt\n";
            }
        }
    }
}


