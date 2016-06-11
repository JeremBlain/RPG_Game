/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for the window itself, init the layout.
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "mainwindow.hpp"
#include <iostream>

//Constructor Main Window
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    //** Taille fenetre **
    this->setFixedSize(1000, 666);

    //bouton = new QPushButton("?");

    //creation of the menu bar
    menuBar = new QMenuBar(this);
    menuBar->addAction("bouton");

    //creation of the map
    map = new Map();


    //creation du layout
    game_window = new QHBoxLayout();
    //game_window->addWidget(bouton);
    this->setLayout(game_window);


}

//Destructor
MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    int kx=0;
    for(kx=0; kx<NbTile-1; ++kx)
    {
        int ky=0;
        for(ky=0; ky<NbTile-1; ++ky)
        {
            QPoint topL( map->getTile(kx, ky)->topLeft() );
            QPoint bottomR( map->getTile(kx,ky)->bottomRight() );
            QRect rect(topL, bottomR);
            painter.drawRect(rect);

            if(map->getEntityType(kx,ky) == charac)
            {
                brush.setColor(Qt::blue);
                painter.setBrush(brush);
                painter.drawEllipse(rect);
                brush.setColor(Qt::red);
                painter.setBrush(brush);
            }
        }
    }

}

// Key press event
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())    {
    case 'z':
        break;
    default:
        break;
    }
}



