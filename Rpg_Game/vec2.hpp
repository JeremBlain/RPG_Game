/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 16 June 2016
**
** Head File for 2 dimensions vector
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/


#ifndef VEC2_H
#define VEC2_H

enum{up,right, bottom, left};

class vec2
{
private:
    int x, y;

public:
    vec2(); //position (0,0)
    vec2(int posx, int posy);
    ~vec2();

    /******* Get coordinates x or y *******/
    int getx(); int gety();

    /******* Set Position *******
     * This function change the x, y of the vector, but in this case, the x,y represent the position in the map */
    void setPosition(int posx, int posy);

    /******* Get Position *******
     * This function return the x, y of the vector, but in this case, the x,y represent the position in the map */
    vec2 getPosition();

    /******* movement function *******
     * This function change the x,y position in a position close to it (in his V4 neighbourhood) */
    void movement(int mv);
};

bool operator<(vec2 v1, vec2 v2);

#endif // VEC2_H

/* *********** FOOTER ************
** Version : 1.00
** Last update : 15 June 2016
** Changes : -Creation and begining of implement attributes and method
** ******************************/
