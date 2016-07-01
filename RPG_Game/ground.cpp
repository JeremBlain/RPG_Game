/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 24 June 2016
**
** Source File for ground
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "ground.hpp"

Ground::Ground()
{
    type = dirt;
}

Ground::Ground(int T)
{
    type = T;
}

Ground::~Ground()
{}

