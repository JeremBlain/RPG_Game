/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 23 June 2016
**
** Head File for Buildings
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/


#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "entity.hpp"

class Building : public Entity
{
public:
    Building();
    Building(int posx, int posy, int id); //constructor with the position on the map
};

#endif // BUILDING_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 23 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -
** ******************************/
