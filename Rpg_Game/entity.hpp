/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 09 June 2016
**
** Head File for Entities
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

/* ******* Explanation
 * Entity is an object which can be found on tile, like character, object or building or.... nothing (null_entity)
 * Mother of : Character and Null classes
 */


#ifndef ENTITY_H
#define ENTITY_H

enum{ground, charac, main_charac, building};

#include <QString>
#include "vec2.hpp"

class Entity
{
    //private attributes
protected:
    int type; //type = enum
    int ID; //an unique Id for each entity
    vec2 pos; //his position on the map

    //public methods
public:
    Entity();
    Entity(int posx, int posy, int id); //constructor with the position on the map
    virtual ~Entity();

    /******* Set TYPE *******
     * Set the type of the entity to a certain value, like character or house */
    void setType(int ent);

    /******* Get TYPE *******
     * Get the type of the entity, return the value of the enum */
    int getType();

    /******* Set Position *******
     * Set the position in the map of the entity */
    void setPosition(int posx, int posy);

    /******* Get Position *******
     * Get the position in the map of the entity */
    vec2 getPosition();
};

/******* Convert QString to Entity Enum *******
 * Get the position in the map of the entity */
int convert_strToEnt(QString ent);

#endif // ENTITY_H

/* *********** FOOTER ************
** Version : 1.02
** Last update : 15 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -set&get entity method
**           -add set position method
** ******************************/
