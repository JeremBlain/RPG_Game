/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 10 June 2016
**
** Head File for null_entities
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/


#ifndef NULL_ENTITY_H
#define NULL_ENTITY_H

#include "entity.hpp"

class Null_entity : public Entity
{
public:
    Null_entity();
    ~Null_entity();
};

#endif // NULL_ENTITY_H


/* *********** FOOTER ************
** Version : 1.00
** Last update : 10 June 2016
** Changes : Creation and begining of implement attributes and method
** ******************************/
