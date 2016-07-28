/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Head File for the window itself, init the layout.
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change.
** *****************************/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QKeyEvent>
#include <QSpinBox>
#include <QPushButton>
#include "map.hpp"
#include "gamewindow.hpp"
#include "ui_mainwindow.h"


namespace Ui {
class MainWindow;
}
class GameWindow;

class Window : public QMainWindow
{
    Q_OBJECT

private:
        Ui::MainWindow *ui;
        GameWindow *gameWindow;
        QMainWindow *resizeWindow;

        void createResizeWindow();

        void actionEvent(QAction *event);
        void keyPressEvent(QKeyEvent *event);

private slots:
        void openResizeWindow();
        void okPressed();

public:
        Window(QWidget *parent = nullptr);
        ~Window();
};

#endif // NWINDOW_HPP

/* *********** FOOTER ************
** Version : 1.01
** Last update : 17 June 2016
** Changes : -Major change (name class from MainWindow to Window)
**           -decide to use ui
** ******************************/
