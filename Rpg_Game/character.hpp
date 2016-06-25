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

class Character : public Entity
{
// private attributes
private:
    QString name;
    int orientation;

//public methods
public:
    Character(); //constructor
    Character(int posx, int posy, int id); //constructor with the position on the map
    Character(int posx, int posy, QString newName, int id); //constructor with the position on the map + the name of the character
    ~Character(); //destructor

    /******* movement method *******
     * a method to move the character into a direction send by parameter (called 'mv')
     * We look if the movement is correct before so we are certain in this function that the mvment is correct */
    void deplacement(int mv);

    /******* Get orientation *******
     * get the orientation of the character */
    int getOrientation();

    /******* set orientation *******
     * set the orientation of the character */
    void setOrientation(int orien);
};

#endif // CHARACTER_H

/* *********** FOOTER ************
** Version : 1.02
** Last update : 24 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -Set type method
**           -add orientation
** ******************************/
