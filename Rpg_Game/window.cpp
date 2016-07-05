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
        gameWindow->movement(mv_left);
        break;

    case 'S':
        gameWindow->movement(bottom);
        break;

    case 'D':
        gameWindow->movement(mv_right);
        break;

    case 'A':
        gameWindow->Talk();
        break;

    case 'E':
        gameWindow->setTalk(false);
        gameWindow->setMenuBox(false);
        gameWindow->setDragonBox(false);
        gameWindow->setCombatUI(false);
        break;

    case Qt::Key_Return:
        gameWindow->setMenuBox(true);
        break;

    case 'B':
        gameWindow->openRubrikMenu();
        break;

    case 'P':
        gameWindow->moveArrow(up);
        break;

    case 'M':
        gameWindow->moveArrow(bottom);
        break;

    case 'L':
        create_map_ground();
        break;

    case 'C':
        gameWindow->setCombatUI(true);
        break;

    default:
        break;
    }
}

