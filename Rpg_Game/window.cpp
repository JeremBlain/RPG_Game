/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Source File for the window itself, init the layout.
** For more informations about the project, see the Readme.md file
** See in the head file for what's the file version and what change, and to understand what this file is for.
** *****************************/


#include "window.hpp"
#include <iostream>

//Constructor Main Window
Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    gameWindow = new GameWindow();
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    ui->layoutGame->addWidget(gameWindow);
}

//Destructor
Window::~Window()
{
    delete ui;
}


// Key press event
void Window::keyPressEvent(QKeyEvent *event)
{
    //move the main character
    switch(event->key())    {
    case 'Z':
        gameWindow->movement(up);
        break;

    case 'Q':
        gameWindow->movement(left);
        break;

    case 'S':
        gameWindow->movement(bottom);
        break;

    case 'D':
        gameWindow->movement(right);
        break;

    case 'A':
        gameWindow->Talk();
        break;

    case 'E':
        gameWindow->setTalk(false);
        gameWindow->openMenu(false);
        break;

    case Qt::Key_Return:
        gameWindow->openMenu(true);
        break;

    default:
        break;
    }
}

