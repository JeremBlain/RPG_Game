/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 16 June 2016
**
** Source File for the window which contain the game.
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "gamewindow.hpp"
#include <iostream>

//Constructor Main Window
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent)
{
    //creation of the map
    map = new Map();
}

//Destructor
GameWindow::~GameWindow()
{}

void GameWindow::movement(int mv)
{
    //get the position of the main character
    vec2 pos = map->getMainCharacPosition();
    int posx = pos.getx();
    int posy = pos.gety();

    if(validMove(posx, posy, mv))
    {
        map->moveCharacter(posx, posy, mv);
        repaint();
    }
}

bool GameWindow::validMove(int posx, int posy, int mv)
{
    if(posx < 10 && mv == left)
        return false;
    if(posy < 10 && mv == up)
        return false;
    if(posx > NbTile-10 && mv == right)
        return false;
    if(posy > NbTile-10 && mv == bottom)
        return false;

    return true;
}

void GameWindow::paintEvent(QPaintEvent*)
{
    //Painter/Brush style
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush = painter.brush();
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    vec2 pos = map->getMainCharacPosition();

    QPoint topL;
    QPoint bottomR;
    QRect rect;

    int y=0, x=0, ky=pos.gety();
    for(y = 0; y <= 19; ++y) //19 is the number of Tile you can get with the actual window's size
    {
        pos = map->getEntityPosition(x, ky-9); //9 is the number of tile above the maincharacter tile.
        ky = pos.gety();
        painter.setBrush(QColor(40+ky*4, 0, 0)); //set the color in a red color gradient

        for(x = 0; x <= 30; ++x) //30 is the number of Tile you can get with the actual window's size
        {
            rect.setCoords(x*sizeTile, y*sizeTile, x*sizeTile+sizeTile, y*sizeTile+sizeTile);
            painter.drawRect(rect);
        }
    }

    //calculate the rect of the main character
    x = this->geometry().width()/2-21; // divide by 2 to be in the middle of the window
    y = this->geometry().height()/2-21;

    topL.setX(x); topL.setY(y);
    bottomR = topL+QPoint(sizeTile, sizeTile);
    rect.setTopLeft(topL);
    rect.setBottomRight(bottomR);

    //set the brush in blue for the character
    painter.setBrush(QColor(0,0,255));
    painter.drawEllipse(rect);
}


