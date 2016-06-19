
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


bool create_file(int type_file)
{
    if(type_file == mapFile)
        if ( create_mapFile() )
            return true;

    return false;
}

bool create_mapFile()
{
    QFile fichier("../data/mapdata.txt");
    if( fichier.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        std::cout<<"Map Data File created"<<std::endl;
        fichier.close();
        return true;
    }

    std::cout<<"/!\\ Map Data File not created /!\\"<<std::endl;
    return false;
}
