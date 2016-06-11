/* *********** HEADER ************
** Auteur : Jérémy Blain
** Ecole : CPE Lyon
** Date début : 08 June 2016
**
** Head File for the window itself, init the layout.
** For more informations about the project, see the Readme.md file
** See below for what's the file version and what change.
** *****************************/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPainter>
#include <QKeyEvent>
#include "map.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

private:
        QPushButton *bouton;
        QHBoxLayout *game_window;
        QMenuBar *menuBar;
        Map *map;
        void keyPressEvent(QKeyEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);



};

#endif // MAINWINDOW_HPP

/* *********** FOOTER ************
** Version : 1.00
** Last update : 08 June 2016
** Changes : Creation of the first layout : a menubar and a empty layout which gonna contain the map int the future
** ******************************/
