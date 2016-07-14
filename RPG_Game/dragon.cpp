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

Dragon::Dragon(): name(""), surname(""), type(fly), lvl(1), HP(30), nbrAttack(0)
{
    int i=0;
    for(i=0; i<4; i++)
    {
        stat[i] = 10;
    }
}

Dragon::Dragon(QString Name, QString Surname, int enum_type, int level, int life, int *statistique, Attack *attackData)
    : name(Name), surname(Surname), type(enum_type), lvl(level), HP(life)
{
    int i=0, nbrA=0;
    for(i=0; i < 4; i++)
    {
        stat[i] = statistique[i];
        attackTab[i] = attackData[i];

        if(QString::compare(attackTab[i].getNameAttack(), "") != 0)
            nbrA++;
    }

    nbrAttack = nbrA;
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

Attack *Dragon::getAttackTab()
{
    return attackTab;
}

int Dragon::getNBAttack()
{
    return nbrAttack;
}

int Dragon::getHP()
{
    return stat[0];
}

int Dragon::getCurrentHP()
{
    return HP;
}



