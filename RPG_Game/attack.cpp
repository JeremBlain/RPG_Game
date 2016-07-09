/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 3 July 2016
**
** Source File for Dragon Attacks
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "attack.hpp"

Attack::Attack() : name(""), type(fly), strength(0)
{}

Attack::Attack(QString nameAttack, int enum_type, int stg) : name(nameAttack), type(enum_type), strength(stg)
{}

QString Attack::getNameAttack()
{
    return name;
}

int Attack::getTypeAttack()
{
    return type;
}

int Attack::getStrengthAttack()
{
    return strength;
}

//outside the class
int convert_str2Type(QString enum_type)
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

    if( QString::compare(enum_type, "electrik", Qt::CaseInsensitive) == 0 )
        return electrik;

    if( QString::compare(enum_type, "metal", Qt::CaseInsensitive) == 0 )
        return metal;

    if( QString::compare(enum_type, "fly", Qt::CaseInsensitive) == 0 )
        return fly;

    return fly;
}

QString convert_Type2Str(int enum_type)
{
    if(enum_type == fly)
        return "fly";

    if(enum_type == fire)
        return "fire";

    if(enum_type == earth)
        return "earth";

    if(enum_type == water)
        return "water";

    if(enum_type == magic)
        return "magic";

    if(enum_type == metal)
        return "metal";

    if(enum_type == electrik)
        return "electrik";

    return "";
}
