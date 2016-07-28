/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 3 July 2016
**
** Head File for Dragon
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef DRAGON_HPP
#define DRAGON_HPP

//Dragons are flying beast who can breathe fire (Whoooo !). Characters have Dragons for fighting !

#include <QString>
#include "attack.hpp"

class Dragon
{
private:
    QString name;
    QString surname;
    int type; //see the enum above
    int lvl;
    int HP; //HP remaining (after combat for example)
    int stat[5]; //4 stats which are : HP, attack, defense, special and velocity
    int nbrAttack;
    Attack attackTab[4];

public:
    Dragon();
    Dragon(QString Name, QString Surname, int enum_type, int level, int life, int* statistique, Attack *attackData);

    /******* Get name *******
     * get the name of the dragon */
    QString getName();

    /******* Get Surname *******
     * get the surname of the dragon */
    QString getSurname();

    /******* Get type *******
     * get the type of the dragon */
    int getDragonType();

    /******* Get level *******
     * get the level of the dragon */
    int getLevel();

    /******* Get attack Tab *******
     * get the attack of the dragon */
    Attack *getAttackTab();

    /******* Get nb attack Tab *******
     * get the number of attack of the dragon */
    int getNBAttack();

    /******* Get HP *******
     * get the number of max HP of the dragon */
    int getHP();

    /******* Get current HP *******
     * get the number of current HP of the dragon */
    int getCurrentHP();
};


#endif // DRAGON_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 3 July 2016
** Changes : -Creation and begining of implement attributes and method
** ******************************/

