/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for characters
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/

#include "character.hpp"

Character::Character() : Entity(), name(""), orientation(bottom), nbrDragon(0)
{
    type = charac;
}

Character::Character(int posx, int posy, int id) : Entity(posx, posy, id), name(""), orientation(bottom), nbrDragon(0)
{
    type = charac;
}

Character::Character(int posx, int posy, QString newName, int id, int nbrD, Dragon *dragonData)
    : Entity(posx, posy, id), name(newName), orientation(bottom), nbrDragon(nbrD)
{
    type = charac;

    if(dragonData == nullptr)
        return;

    int i=0;

    while(QString::compare( dragonData[i].getName(), "") != 0)
    {
        dragonTab[i] = dragonData[i];
        i++;
    }
}

Character::~Character()
{
    delete this;
}

void Character::deplacement(int mv) //enum is {up, right, bottom, left}
{
    pos.movement(mv);
}

int Character::getOrientation()
{
    return orientation;
}

void Character::setOrientation(int orien)
{
    orientation = orien;
}

QString Character::getName()
{
    return name;
}

QString Character::getDragonName(int n)
{
    return dragonTab[n].getName();
}

QString Character::getDragonSurname(int n)
{
    return dragonTab[n].getSurname();
}

int Character::getNBDragon()
{
    return nbrDragon;
}

Attack *Character::getDragonAttack(int n)
{
    return dragonTab[n].getAttackTab();
}

int Character::getDragonAttackNB(int n)
{
    return dragonTab[n].getNBAttack();
}

int Character::getDragonType(int n)
{
    return dragonTab[n].getDragonType();
}

int Character::getDragonLevel(int n)
{
    return dragonTab[n].getLevel();
}


