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
#include <QTextBrowser>
#include <QMenuBar>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <vector>
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
        bool talk; //if the main character speak
        bool menu; //if the main character open the menu
        int arrowMenu;

        //UI
        QTextBrowser* dialogBox;
        QTextBrowser* menuBox;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    /******* to move the main character */
    void movement(int mv);

    /******* to change the orientaion the main character */
    void setOrientation();

    /******* to check if the move si valid */
    bool validMove(int posx, int posy, int mv);

    /******* Talk method*/
    void Talk();

    /******* Draw text when talk to a character ******
    * method when the main character talk to a PNJ, to display his dialog/text */
    void drawDialog(int posx, int posy);

    /******* Set the talk attribute to s if the main character talk to an other*/
    void setTalk(bool t);

    /******* Set the menu attribute to m if the main character open menu*/
    void openMenu(bool m);

    /******* place an arrow for selection before the words */
    QString placeArrowInMenu(QString text);

    /******* check if the move of the arrow is valid */
    bool validMoveArrow(int mv);

    /******* Move the arrow in the menu up or down if possible */
    void moveArrow(int mv);

    /******* Get the position of the arrow in the menu*/
    int getArrowMenu();

    /******* Set the position of the arrow in the menu*/
    void setArrowMenu(int arrow);

    /******* Draw Orientation of Character
     * this method draw a line which symbolise the orientation of a character*/
    void drawOrientation(int x, int y, vec2 pos, QPainter& painter);

    void paintEvent(QPaintEvent *event);
};

#endif // GAMEWINDOW_HPP

/* *********** FOOTER ************
** Version : 1.01
** Last update : 24 June 2016
** Changes : -Creation of the class, but I take the function PaintEvent from Mainwindow
**           -add orientation move and talking to character
** ******************************/
