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
#include <QTextBrowser>
#include <QPainter>
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

        //booleans for all the widget and box in the window
        bool talk; //if the main character speak
        bool menu; //if the main character open the menu
        bool combat; //if there is a combat !!
        bool dragon; //if open dragon menu

        int arrowMenu;
        int arrowDragonInfo;
        int arrowAttackCombat;

        /****** UI : worldmap *****/
        //Dialog
        QTextBrowser* dialogBox; //box when MC talk to other

        //Menu
        QWidget* menuBox; //box for the menu
        QTextBrowser* nameMenuBox; //box for the main character Name in the menu
        QTextBrowser* dragonMenuBox; //box for dragon in the menu
        QTextBrowser* statMenuBox; //box for statistique in the menu
        QTextBrowser arrowMenuBox[2];

        //DragonBox
        QWidget* dragonBox; //box for Dragon name and lvl
        QTextBrowser dragonTextTab[5];
        QTextBrowser arrowDragBox[5];

        //DragonInfoBox
        QTextBrowser* dragonInfoBox; //box for dragon infos : stat, attack, etc


        //UI : combat
        QTextBrowser* dragonAttackBox; // box for dragon's attack in combat
        QTextBrowser* ennemyDragonBox; // box for dragon's ennemy in cobat

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    //create the menu box in the constructor
    void createMenuBox();

    //create the menu box in the constructor
    void createDragonBox();

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
    void setMenuBox(bool m);

    /******* Set the dragon box attribute to db if the main character open menu of his dragon*/
    void setDragonBox(bool db);

    /******* Set UI for combat */
    void setCombatUI(bool c);

    /******* place an arrow for selection before the words */
    void placeArrowInMenu();

    /******* place an arrow for selection before the words */
    void placeArrowDragBox();

    /******* place an arrow for selection before the words */
    QString placeArrowCombatBox(QString text);

    /******* check if the move of the arrow is valid */
    bool validMoveArrow(int mv, int arrow);

    /******* Move the arrow in the menu up or down if possible */
    void moveArrow(int mv);

    /******* Get the position of the arrow in the menu*/
    int getArrowDragonInfo();

    /******* Get the position of the arrow in the menu*/
    int getArrowMenu();

    /******* Set the position of the arrow in the menu*/
    void setArrowMenu(int placeArrow);

    /******* Set the position of the arrow in the menu*/
    void setArrowDragInfo(int placeArrow);

    /******* open the right rubrik in the menu, according to the value of arrowMenu */
    void openRubrikMenu();

    /****** set the text of the Dragon box (main character's dragon)
    * var 'i' is the i-th dragon*/
    QString textDragonMC(int i);

    /****** set the text of the Dragon info box (main character's dragon info) */
    QString textDragonInfoMC();

    /****** set the text of the main character dragon while in combat*/
    QString textCombatMC();

    /******* Draw Orientation of Character ******
     * this method draw a line which symbolise the orientation of a character
     * x,y is the position of the tile in the window, pos is the position of the character*/
    void drawOrientation(int x, int y, vec2 pos, QPainter& painter);

    /******* Draw ground ******
     * this method color the tile by a color depends on the type of ground
     * x,y is the position of the tile in the window, pos is the position of the tile*/
    void drawGround(int x, int y, int posTileX, int posTileY, QPainter& painter);

    void paintEvent(QPaintEvent *event);
};

#endif // GAMEWINDOW_HPP

/* *********** FOOTER ************
** Version : 1.04
** Last update : 7 July 2016
** Changes : -Creation of the class, but I take the function PaintEvent from Mainwindow
**           -add orientation move and talking to character
**           -add method to draw the ground, but too processor killer (laaaag)
**           -add combat UI + modify the way to show the widget for menu etc...
**           -improve Dragon info box
** ******************************/
