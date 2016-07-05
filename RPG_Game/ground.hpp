/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 24 June 2016
**
** Head File for ground class
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

#ifndef GROUND_H
#define GROUND_H

#include <QString>

enum{dirt, grass, path, river, sea};

class Ground
{
private:
    int type;
public:
    Ground();
    Ground(int T); //constructor with the position on the map
    ~Ground();

    /****** Get Type *******
     *Get the enum type of ground */
    int getType();
};

/******* Convert QString to Ground Enum *******
 * Convert the string sent to a ground enum*/
int convert_strToGround(QString gr);


#endif


/* *********** FOOTER ************
** Version : 1.00
** Last update : 24 June 2016
** Changes : -Creation and begining of implement attributes and method
**
** ******************************/
