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

void GameWindow::move(int mv)
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
    if(posx == 0 && mv == left)
        return false;
    if(posy == 0 && mv == up)
        return false;
    if(posx == NbTile-1 && mv == right)
        return false;
    if(posy == NbTile-1 && mv == bottom)
        return false;

    return true;
}

void GameWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    int kx=0;
    for(kx=0; kx<NbTile; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile; ++ky)
        {
            QPoint topL( map->getRectTile(kx, ky)->topLeft() );
            QPoint bottomR( map->getRectTile(kx, ky)->bottomRight() );
            QRect rect(topL, bottomR);
            painter.drawRect(rect);

            if(map->getEntityType(kx,ky) == charac)
            {
                //set the brush in blue for the character
                brush = painter.brush();
                brush.setColor(Qt::blue);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(rect);

                //set the brush in red for the rect
                brush.setColor(Qt::red);
                painter.setBrush(brush);
            }
        }
    }
}


