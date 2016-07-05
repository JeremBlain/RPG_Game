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
    QWidget(parent), talk(false), menu(false), combat(false), dragon(false), arrowMenu(0)
{
    //creation of the map
    map = new Map();

    //creation of the box which show the dialog between the main charac and other
    dialogBox = new QTextBrowser(this);
    dialogBox->setGeometry(0, 0, 1, 1);
    dialogBox->setFont(QFont("Aria", 16));

    //creation of the box which show the menu
    menuBox = new QTextBrowser(this);
    menuBox->setFont(QFont("Aria", 21));
    menuBox->setGeometry(0, 0, 1, 1);
    QString textMenu = map->getMainCharacName();
    textMenu.append(" :\n     Dragon\n     Stats"); //if add rubrik, don't forget to increase the number of

    textMenu = this->placeArrowInMenu(textMenu);

    menuBox->setText(textMenu);

    //creation of the box which show the main character's dragons
    dragonBox = new QTextBrowser(this);
    dragonBox->setGeometry(0, 0, 1, 1);
    dragonBox->setFont(QFont("Aria", 16));

    //creation of the box which show the main character's dragons attacks
    dragonAttackBox = new QTextBrowser(this);
    dragonAttackBox->setGeometry(0, 0, 1, 1);
    dragonAttackBox->setFont(QFont("Aria", 16));

    //creation of the box which show the ennemy dragons info
    ennemyDragonBox = new QTextBrowser(this);
    ennemyDragonBox->setGeometry(0, 0, 1, 1);
    ennemyDragonBox->setFont(QFont("Aria", 16));

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

    if(mv == mv_left)
    {
        if(posx < 16 || !(map->isType(posx-1, posy, ground)) )
            return false;
    }

    if(mv == up)
    {
        if(posy < 10 || (!map->isType(posx, posy-1, ground)) )
            return false;
    }

    if(mv == mv_right)
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

    if(orien == mv_right)
    {
        if(map->isType(pos.getx()+1, pos.gety(), charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx()+1, pos.gety(), mv_left);
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

    if(orien == mv_left)
    {
        if(map->isType(pos.getx()-1, pos.gety(), charac))
        {
                setTalk(true);
                map->setCharacOrientation(pos.getx()-1, pos.gety(), mv_right);
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

void GameWindow::setMenuBox(bool m)
{
    if(talk == true) return; //can't open menu if talking

    menu = m;
    repaint();
}

void GameWindow::setDragonBox(bool db)
{
    dragon = db;
    repaint();
}

void GameWindow::setCombatUI(bool c)
{
    combat = c;
    repaint();
}

QString GameWindow::placeArrowInMenu(QString text)
{
    int nbrReturn = text.count('\n');
    std::vector<QString> tabText;
    tabText.resize(nbrReturn);

    int i = 0;
    for(i=0; i < nbrReturn; i++)
    {
        tabText[i] = text.section('\n', i+1, i+1);
        tabText[i].replace(2, 1, ' ');
    }

    tabText[arrowMenu].replace(2, 1, '>');

    text = map->getMainCharacName() + " :\n";
    for(i=0; i < nbrReturn; i++)
    {
        //don't want \n at the end, for the last line
        if(i != nbrReturn-1)
            text.append(tabText[i] + '\n');
        else
            text.append(tabText[i]);
    }

    return text;
}

bool GameWindow::validMoveArrow(int mv)
{
    if(mv == up && arrowMenu > 0) return true;

    if(mv == bottom && arrowMenu < 1) return true;

    return false;
}

void GameWindow::moveArrow(int mv)
{
    if( validMoveArrow(mv))
    {
        if(mv == up) setArrowMenu(getArrowMenu()-1);

        if(mv == bottom) setArrowMenu(getArrowMenu()+1);
    }
}

int GameWindow::getArrowMenu()
{
    return arrowMenu;
}

void GameWindow::setArrowMenu(int arrow)
{
    arrowMenu = arrow;
    repaint();
}

void GameWindow::openRubrikMenu()
{
    if(menu == 1)
    {
        if(arrowMenu == 0)
            setDragonBox(true);

        menu = 0;
    }
}

QString GameWindow::textDragonMC()
{
    QString text="";

    int i=0;

    while(i < 5 && map->getMainCharacterDragonName(i) != "")
    {
        QString dragonSurname = map->getMainCharacterDragonSurname(i);
        int dragonLvl = map->getMainCharacterDragonLevel(i);
        QString STR_Lvl=""; STR_Lvl.setNum(dragonLvl);

        text.append(dragonSurname + ' ' + STR_Lvl + '\n');
        i++;
    }

    return text;
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

    if(orien == mv_left)
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

    if(orien == mv_right)
    {
        QPoint line1(x+sizeTile/2, y+sizeTile/2);
        QPoint line2(x+sizeTile, y+sizeTile/2);
        painter.drawLine(line1, line2);
    }
}

void GameWindow::drawGround(int x, int y, int posTileX, int posTileY, QPainter &painter)
{
    int gr = map->getGroundType(posTileX, posTileY);

    if(gr == dirt)
        painter.setBrush(QColor(222, 67, 67));

    if(gr == grass)
        painter.setBrush(QColor(10, 50, 222));

    if(gr == path)
        painter.setBrush(QColor(22, 22, 22));

    if(gr == water)
        painter.setBrush(QColor(10, 50, 111));

    if(gr == sea)
        painter.setBrush(QColor(10, 50, 222));

    painter.drawRect(x, y, x+sizeTile, y+sizeTile);
}

void GameWindow::paintEvent(QPaintEvent*)
{
    //Painter/Brush style
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush = painter.brush();
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    if(combat == false)
    {
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
                //drawGround(x*sizeTile, y*sizeTile, posTileX, posTileY, painter);
                painter.setBrush(QColor(3*posTileX, 0, 3*posTileY));

                rect.setCoords(x*sizeTile, y*sizeTile, x*sizeTile+sizeTile, y*sizeTile+sizeTile);
                painter.drawRect(rect);

                if(map->getEntityType(posTileX, posTileY) == charac) //if there is a character on the tile
                {
                    painter.setBrush(QColor(0, 222, 0)); // set green color for other character
                    painter.drawEllipse(rect);
                    this->drawOrientation(x*sizeTile, y*sizeTile, vec2(posTileX,posTileY), painter);
                }
                if(map->getEntityType(posTileX, posTileY) == building) //if there is a building on the tile
                {
                    painter.setBrush(QColor(222, 222, 0)); //set the color yellow for building
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

        //draw the orientation line for the main character
        this->drawOrientation(x, y, pos, painter);

        //the widget for the dialog
        if(talk == false)
            dialogBox->setGeometry(0, 0, 1, 1);
        else
            dialogBox->setGeometry(0, 555, 1300, 121);

        //the widget for the menu
        if(menu == false)
            menuBox->setGeometry(0, 0, 1, 1);
        else
        {
            menuBox->setGeometry(1061, 0, 240, 666);
            QString textMenu = menuBox->toPlainText();
            textMenu = this->placeArrowInMenu(textMenu);
            menuBox->setText(textMenu);
        }

        //the widget for the dragon menu
        if(dragon == false)
            dragonBox->setGeometry(0, 0, 1, 1);
        else
        {
            dragonBox->setGeometry(0, 555, 1300, 121);
            QString textMenu = textDragonMC();
            dragonBox->setText(textMenu);
        }

        dragonAttackBox->setGeometry(0, 0, 1, 1);

        ennemyDragonBox->setGeometry(0, 0, 1, 1);
    }

    else
    {
        dragonAttackBox->setGeometry(300, 555, 1000, 128);

        ennemyDragonBox->setGeometry(0, 0, 1000, 128);
    }
}


