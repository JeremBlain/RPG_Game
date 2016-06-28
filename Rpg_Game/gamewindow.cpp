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
    QWidget(parent), talk(false), menu(false)
{
    //creation of the map
    map = new Map();

    dialogBox = new QTextBrowser(this);
    dialogBox->setGeometry(0, 0, 1, 1);
    dialogBox->setFont(QFont("Aria", 16));

    menuBox = new QTextBrowser(this);
    menuBox->setFont(QFont("Aria", 22, QFont::Bold));
    menuBox->setGeometry(0, 0, 1, 1);
    menuBox->setText("\tTest\n\tStats");
}

//Destructor
GameWindow::~GameWindow()
{}

void GameWindow::movement(int mv)
{
    if(talk == true || menu == true)
        return;

    //get the position of the main character
    vec2 pos = map->getMainCharacPosition();
    int posx = pos.getx();
    int posy = pos.gety();

    if(validMove(posx, posy, mv))
    {
        map->moveCharacter(posx, posy, mv);

    }
    map->setMainCharacOrientation(mv);
    repaint();
}

bool GameWindow::validMove(int posx, int posy, int mv)
{
    if(map->getMainCharacOrientation() != mv)
        return false;

    if(mv == left)
    {
        if(posx < 16 || !(map->isType(posx-1, posy, ground)) )
            return false;
    }

    if(mv == up)
    {
        if(posy < 10 || (!map->isType(posx, posy-1, ground)) )
            return false;
    }

    if(mv == right)
    {
        if(posx >= NbTile-16 || !(map->isType(posx+1, posy, ground)) )
            return false;
    }

    if(mv == bottom)
    {
        if(posy >= NbTile-10 || !(map->isType(posx, posy+1, ground)) )
            return false;
    }

    return true;
}

void GameWindow::Talk()
{
    if(menu == true) return; //if the menu is open, can't talk

    int orien = map->getMainCharacOrientation();
    vec2 pos = map->getMainCharacPosition();

    if(orien == up)
    {
        if(map->isType(pos.getx(), pos.gety()-1, charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx(), pos.gety()-1, bottom);
                this->drawDialog(pos.getx(), pos.gety()-1);
        }
    }

    if(orien == right)
    {
        if(map->isType(pos.getx()+1, pos.gety(), charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx()+1, pos.gety(), left);
                this->drawDialog(pos.getx()+1, pos.gety());
        }
    }

    if(orien == bottom)
    {
        if(map->isType(pos.getx(), pos.gety()+1, charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx(), pos.gety()+1, up);
                this->drawDialog(pos.getx(), pos.gety()+1);
        }
    }

    if(orien == left)
    {
        if(map->isType(pos.getx()-1, pos.gety(), charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx()-1, pos.gety(), right);
                this->drawDialog(pos.getx()-1, pos.gety());
        }
    }
    repaint();
}

void GameWindow::drawDialog(int posx, int posy)
{
    int id = map->getEntityID(posx, posy);
    QString name = map->getCharacName(posx, posy);

    QString text = get_dialog_charac(id);
    text.prepend(" : </b>").prepend(name).prepend("<b>");

    dialogBox->setText(text);
}

void GameWindow::setTalk(bool t)
{
    talk = t;
    repaint();
}

void GameWindow::openMenu(bool m)
{
    if(talk == true) return; //can't open menu if talking

    menu = m;
    repaint();
}

void GameWindow::drawOrientation(int x, int y, vec2 pos, QPainter& painter)
{
    int orien = map->getCharacOrientation(pos.getx(), pos.gety());

    if(orien == bottom)
    {
        QPoint line1(x+sizeTile/2, y+sizeTile/2);
        QPoint line2(x+sizeTile/2, y+sizeTile);
        painter.drawLine(line1, line2);
    }

    if(orien == left)
    {
        QPoint line1(x+sizeTile/2, y+sizeTile/2);
        QPoint line2(x, y+sizeTile/2);
        painter.drawLine(line1, line2);
    }

    if(orien == up)
    {
        QPoint line1(x+sizeTile/2, y+sizeTile/2);
        QPoint line2(x+sizeTile/2, y);
        painter.drawLine(line1, line2);
    }

    if(orien == right)
    {
        QPoint line1(x+sizeTile/2, y+sizeTile/2);
        QPoint line2(x+sizeTile, y+sizeTile/2);
        painter.drawLine(line1, line2);
    }
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
    int posTileX = 0, posTileY = 0;

    int y=0, x=0, posx=pos.getx(), posy=pos.gety();
    for(y = 0; y <= 19; ++y) //19 is the number of Tile you can get with the actual window's size
    {    
        posTileY = posy+y-9;
        for(x = 0; x <= 30; ++x) //30 is the number of Tile you can get with the actual window's size
        {
            posTileX = posx+x-15;
            painter.setBrush(QColor(posTileX*3, 0, posTileY*3)); //set the color in a red color gradient
            rect.setCoords(x*sizeTile, y*sizeTile, x*sizeTile+sizeTile, y*sizeTile+sizeTile);
            painter.drawRect(rect);

            if(map->getEntityType(posTileX, posTileY) == charac)
            {
                painter.setBrush(QColor(0, 222, 0)); //set the color in a red color gradient
                painter.drawEllipse(rect);
                this->drawOrientation(x*sizeTile, y*sizeTile, vec2(posTileX,posTileY), painter);
            }
            if(map->getEntityType(posTileX, posTileY) == building)
            {
                painter.setBrush(QColor(222, 222, 0)); //set the color in a red color gradient
                painter.drawEllipse(rect);
            }
        }
    }

    //calculate the rect of the main character
    x = (this->geometry().width()-sizeTile)/2; // divide by 2 to be in the middle of the window
    y = (this->geometry().height()-sizeTile)/2;

    topL.setX(x); topL.setY(y);
    bottomR = topL+QPoint(sizeTile, sizeTile);
    rect.setTopLeft(topL);
    rect.setBottomRight(bottomR);

    //set the brush in blue for the character
    painter.setBrush(QColor(0,0,255));
    painter.drawEllipse(rect);

    this->drawOrientation(x, y, pos, painter);

    if(talk == false)
        dialogBox->setGeometry(0, 0, 1, 1);
    else
        dialogBox->setGeometry(0, 555, 1300, 121);

    if(menu == false)
        menuBox->setGeometry(0, 0, 1, 1);
    else
        menuBox->setGeometry(1000, 0, 300, 666);

}


