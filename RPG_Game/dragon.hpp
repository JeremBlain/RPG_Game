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

//Dragons are flying beast who can (Whoooo !). Characters have Dragons for fighting !

#include <QString>

enum{fly, fire, water, earth, magic, dark, metal}; //enum type
//Earth type = can't flying....

class Dragon
{
private:
    QString name;
    QString surname;
    int type; //see the enum above
    int lvl;
    int HP;
    int stat[4]; //4 stats which are : attack, defense, special and velocity

public:
    Dragon();
    Dragon(QString Name, QString SurName, int enum_type, int level, int life, int* statistique);

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
};

/******* Convert QString to Dragon type Enum */
int convert_strToType(QString enum_type);


#endif // DRAGON_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 3 July 2016
** Changes : -Creation and begining of implement attributes and method
** ******************************/

