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

    //creation of the menu bar
    menuBar = new QMenuBar(this);
    menuBar->addAction("bouton");

    //creation du layout
    gameLayout = new QHBoxLayout();

    gameWindow = new GameWindow();
    gameLayout->addWidget(gameWindow);

    this->setLayout(gameLayout);
}

//Destructor
MainWindow::~MainWindow()
{}


// Key press event
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //move the main character
    switch(event->key())    {
    case 'Z':
        gameWindow->move(up);
        break;

    case 'Q':
        gameWindow->move(left);
        break;

    case 'S':
        gameWindow->move(bottom);
        break;

    case 'D':
        gameWindow->move(right);
        break;

    default:
        break;
    }
}


