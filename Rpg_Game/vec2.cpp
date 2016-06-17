/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 16 June 2016
**
** Source File for 2 dim vector
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "vec2.hpp"

vec2::vec2() : x(0), y(0)
{}

vec2::vec2(int posx, int posy) : x(posx), y(posy)
{}

vec2::~vec2()
{}

int vec2::getx()
{
    return x;
}

int vec2::gety()
{
    return y;
}

void vec2::setPosition(int posx, int posy)
{
    x = posx; y = posy;
}

vec2 vec2::getPosition()
{
    return *this;
}

void vec2::movement(int mv)
{
    if(mv == up)
        y--;

    if(mv == right)
        x++;

    if(mv == bottom)
        y++;

    if(mv == left)
        x--;
}

