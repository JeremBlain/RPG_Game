/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 24 June 2016
**
** Source File for ground
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "ground.hpp"

Ground::Ground()
{
    type = dirt;
}

Ground::Ground(int T)
{
    type = T;
}

Ground::~Ground()
{}

int Ground::getType()
{
    return type;
}


//outside the ground class
int convert_strToGround(QString gr)
{
    gr = gr.simplified(); //remove \n, \t etc...
    if( QString::compare(gr, "Dirt", Qt::CaseInsensitive) == 0 )
        return dirt;

    if(QString::compare(gr, "Grass", Qt::CaseInsensitive) == 0)
            return grass;

    if(QString::compare(gr, "Path", Qt::CaseInsensitive) == 0)
        return path;

    if(QString::compare(gr, "River", Qt::CaseInsensitive) == 0)
        return river;

    if(QString::compare(gr, "Sea", Qt::CaseInsensitive) == 0)
        return sea;

    return dirt;
}
