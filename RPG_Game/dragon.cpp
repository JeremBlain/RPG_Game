/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 3 July 2016
**
** Source File for Dragon
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "dragon.hpp"

Dragon::Dragon(): name(""), surname(""), type(fly), lvl(1), HP(30)
{
    int i=0;
    for(i=0; i<4; i++)
    {
        stat[i] = 10;
    }
}

Dragon::Dragon(QString Name, QString SurName, int enum_type, int level, int life, int *statistique)
    : name(Name), surname(SurName), type(enum_type), lvl(level), HP(life)
{
    int i=0;
    for(i=0; i<4; i++)
    {
        stat[i] = *(statistique+i);
    }
}

QString Dragon::getName()
{
    return name;
}

QString Dragon::getSurname()
{
    return surname;
}

int Dragon::getDragonType()
{
    return type;
}

int Dragon::getLevel()
{
    return lvl;
}


//outside the class
int convert_strToType(QString enum_type)
{
    enum_type = enum_type.simplified(); //remove \n, \t etc...
    if( QString::compare(enum_type, "fire", Qt::CaseInsensitive) == 0 )
        return fire;

    if( QString::compare(enum_type, "water", Qt::CaseInsensitive) == 0 )
        return water;

    if( QString::compare(enum_type, "earth", Qt::CaseInsensitive) == 0 )
        return earth;

    if( QString::compare(enum_type, "magic", Qt::CaseInsensitive) == 0 )
        return magic;

    if( QString::compare(enum_type, "dark", Qt::CaseInsensitive) == 0 )
        return dark;

    if( QString::compare(enum_type, "metal", Qt::CaseInsensitive) == 0 )
        return metal;

    if( QString::compare(enum_type, "fly", Qt::CaseInsensitive) == 0 )
        return fly;

    return fly;
}
