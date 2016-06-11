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

enum{null_entity, charac};

class Entity
{
    //private attributes
protected:
    int type; //type = enum

    //public methods
public:
    Entity();
    virtual ~Entity();

    /******* Set TYPE *******
     * Set the type of the entity to a certain value, like character or house */
    void setType(int ent);
    /******* Get TYPE *******
     * Get the type of the entity, return the value of the enum */
    int getType();
};

#endif // ENTITY_H

/* *********** FOOTER ************
** Version : 1.01
** Last update : 10 June 2016
** Changes : -Creation and begining of implement attributes and method
**           -set&get entity method
** ******************************/
