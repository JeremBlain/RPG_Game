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

    createResizeWindow();

    //connect event
    connect(ui->actionSize, SIGNAL(triggered()), this, SLOT(openResizeWindow()));
}

//Destructor
Window::~Window()
{
    delete ui;
}

void Window::createResizeWindow()
{
    resizeWindow = new QMainWindow();
    resizeWindow->hide();
    resizeWindow->setFixedSize(400, 123);
    resizeWindow->setFont(QFont("Aria", 21));

    QLabel *heightText = new QLabel(resizeWindow);
    QLabel *widthText = new QLabel(resizeWindow);

    heightText->setGeometry(0, 0, 200, 36);
    widthText->setGeometry(200, 0, 200, 36);
    heightText->setText("Height");
    widthText->setText("Width");
    heightText->setAlignment(Qt::AlignCenter);
    widthText->setAlignment(Qt::AlignCenter);

    QSpinBox *heightSpinBox = new QSpinBox(resizeWindow);
    QSpinBox *widthSpinBox = new QSpinBox(resizeWindow);

    heightSpinBox->setGeometry(0, 36, 200, 36);
    widthSpinBox->setGeometry(200, 36, 200, 36);

    heightSpinBox->setSingleStep(84);
    widthSpinBox->setSingleStep(84);

    heightSpinBox->setRange(462, 1470);
    widthSpinBox->setRange(462, 1470);

    QPushButton *ButtonOK = new QPushButton("OK", resizeWindow);
    ButtonOK->setGeometry(275, 76, 100, 42);

    connect(ButtonOK, SIGNAL(clicked()), this, SLOT(okPressed()));
}

void Window::keyPressEvent(QKeyEvent *event)
{
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

    case 'L':
        create_map_ground();
        break;

    case 'C':
        gameWindow->setCombatUI(true);
        break;

    case 'V':
        gameWindow->setCombatUIAttack(true);
        break;

    case Qt::Key_Up:
        gameWindow->moveArrow(up);
        break;

    case Qt::Key_Down:
        gameWindow->moveArrow(bottom);
        break;

    case Qt::Key_Left:
        gameWindow->moveArrow(mv_left);
        break;

    case Qt::Key_Right:
        gameWindow->moveArrow(mv_right);
        break;

    default:
        break;
    }
}

void Window::openResizeWindow()
{
    resizeWindow->show();
}

void Window::okPressed()
{
    QWidget *WSB = resizeWindow->childAt(200, 37), *HSB = resizeWindow->childAt(0, 37);
    QSpinBox *wSB = dynamic_cast<QSpinBox*>(WSB);
    QSpinBox *hSB = dynamic_cast<QSpinBox*>(HSB);

    int w = wSB->value(), h = hSB->value();
    gameWindow->setSizeGameWindow(w, h);
    setFixedSize(w, h+21);

    resizeWindow->hide();

    gameWindow->majBox();
}

