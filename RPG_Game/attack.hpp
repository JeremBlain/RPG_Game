/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 5 July 2016
**
** Head File for Dragon Attacks
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/


#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <QString>

enum{fly, fire, water, earth, magic, electrik, metal}; //enum type
//Earth type = can't flying....

class Attack
{
private:
    QString name;
    int type;
    int strength;

public:
    Attack();
    Attack(QString nameAttack, int enum_type, int stg);

    /******* Get name attack *******
     * get the name of attack */
    QString getNameAttack();

    /******* Get type *******
     * get the type of attack */
    int getTypeAttack();

    /******* Get strength *******
     * get the strength of attack */
    int getStrengthAttack();
};

/******* Convert QString to Dragon type Enum */
int convert_str2Type(QString enum_type);

/******* Convert Dragon type Enum to QString */
QString convert_Type2Str(int enum_type);



#endif // ATTACK_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 5 July 2016
** Changes : -Creation and begining of implement attributes and method
**           -
** ******************************/
