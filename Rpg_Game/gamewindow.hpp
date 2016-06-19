/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 16 June 2016
**
** Head File for the window which contain the game.
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change.
** *****************************/

#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPainter>
#include <QKeyEvent>
#include "map.hpp"

namespace Ui {
class GameWindow;
}

#define sizeTile 42

class GameWindow : public QWidget
{
    Q_OBJECT

private:
        Map *map;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    /******* to move the mzin character */
    void movement(int mv);

    /******* to check if the move si valid */
    bool validMove(int posx, int posy, int mv);

    void paintEvent(QPaintEvent *event);
};

#endif // GAMEWINDOW_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 16 June 2016
** Changes : Creation of the class, but I take the function PaintEvent from Mainwindow
** ******************************/
