/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Main File, only for show the window
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change.
** *****************************/


#include "window.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();

    return a.exec();
}

/* *********** FOOTER ************
** Version : 1.00
** Last update : 08 June 2016
** Normally, this file won't change in the future
** ******************************/
