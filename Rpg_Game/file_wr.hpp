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
#include <QMap>
#include <QTextStream>
#include <iostream>
#include <time.h>
#include "entity.hpp"
#include "ground.hpp"
#include "dragon.hpp"


enum typeFile{map_file, main_character_file, character_file, dialog_file};

/******* Files Exist ? *******
 * check if files exists. if not, create the file with function below*/
void files_exist();

/******* Create Map Entity FILE *******
 * create a file for entity in the map data*/
bool create_File(QFile* file);

/******* Get Entity in map file*******
 * get the type of entity + ID (in a vec2) in the position (kx,ky) if possible
 * if there is no entity set in the position (kx,ky) the function return by default 0, ie ground
 * the entity are places on a map, with the position as the key*/
QMap<vec2, vec2> get_entities_mapFile();

/******* Get Ground in map file*******
 * get the type of ground in the position (kx,ky) if possible
 * the ground are places on a map, with the position as the key*/
QMap<vec2, int> get_ground_mapFile();

/******* Get the name of the main character *******
 * get the name of MC on the main character file*/
QString get_name_mainCharacter();

/******* Get the dragons of the main character *******
 * get dragons of MC on the main character file*/
void get_dragons_main_character(Dragon *dragonTab);

/******* Get the name of the main character *******
 * get the name of MC on the main character file*/
QString get_name_character(int id);

/******* Get the text of character *******
 * get the text of a character when you talk to him*/
QString get_dialog_charac(int id);

/*Just lazy to create the map, made the program do itself :) */
void create_map_ground();

#endif // FILE_WR_HPP

/* *********** FOOTER ************
** Version : 1.03
** Last update : 1 July 2016
** Changes : -Creation of the file : createFile & create_mapFile functions
**           -add functions get_entity_map
**           -add mainCharacter file related functions
**           -add ground file related functions
** ******************************/
