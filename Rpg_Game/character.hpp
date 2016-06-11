/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Head File for characters
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.hpp"

enum{up,right, bottom, left};

class Character : public Entity
{
// private attributes
private:
    int life;
    int posX, posY; //his position on the map

//public methods
public:
    Character(); //constructor
    Character(int posx, int posy); //constructor with his position x,y
    ~Character(); //destructor

    /******* movement function *******
     * a function to move the character into a direction send by parameter (called 'mv')
     * We look if the movement is correct before so we are certain in this function that the mvment is correct */
    void deplacement(int mv);
};

#endif // CHARACTER_H

/* *********** FOOTER ************
** Version : 1.01
** Last update : 10 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -Set type method
** ******************************/
