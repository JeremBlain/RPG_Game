/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 18 June 2016
**
** Head File for data file write and read
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change. See the header to understand what this file is for.
** *****************************/

/* *********** FILE ***********
 * this code file permit to open, create, modify the files nedded to save game's data */

#ifndef FILE_WR_HPP
#define FILE_WR_HPP

#include <QFile>
#include <iostream>

enum typeFile{mapFile, characterFile};

/******* Create FILE *******
 * create a file according the type of data you want to save*/
bool create_file(int type_file);

/******* Create FILE *******
 * create a file for map data*/
bool create_mapFile();



#endif // FILE_WR_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 18 June 2016
** Changes : Creation of the file
** ******************************/
