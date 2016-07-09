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

//Constructor Game Window
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent), talk(false), menu(false), combat(false), dragon(false),
    arrowMenu(0), arrowDragonInfo(0), arrowAttackCombat(0)
{
    //creation of the map
    map = new Map();

    //creation of the box which show the dialog between the main charac and other
    dialogBox = new QTextBrowser(this);
    dialogBox->setGeometry(0, 555, 1300, 121);
    dialogBox->hide();
    dialogBox->setFont(QFont("Aria", 16));

    createMenuBox();
    createDragonBox();

    //creation of the box which show the main character's dragons info
    dragonInfoBox = new QTextBrowser(this);
    dragonInfoBox->setGeometry(0, 1, 1301, 500);
    dragonInfoBox->hide();
    dragonInfoBox->setFont(QFont("Aria", 18));

    //creation of the box which show the main character's dragons attacks
    dragonAttackBox = new QTextBrowser(this);
    dragonAttackBox->setGeometry(500, 555, 800, 128);
    dragonAttackBox->hide();
    dragonAttackBox->setFont(QFont("Aria", 16));

    //creation of the box which show the ennemy dragons info
    ennemyDragonBox = new QTextBrowser(this);
    ennemyDragonBox->setGeometry(0, 0, 800, 128);
    ennemyDragonBox->hide();
    ennemyDragonBox->setFont(QFont("Aria", 16));
}

//Destructor
GameWindow::~GameWindow()
{}

void GameWindow::createMenuBox()
{
    //creation of the box which show the menu
    menuBox = new QWidget(this);
    menuBox->setFont(QFont("Aria", 20));
    menuBox->setGeometry(1061, 0, 240, 666);
    menuBox->setAutoFillBackground(true);
    menuBox->setPalette(QColor(255, 255, 255));
    menuBox->hide();

    nameMenuBox = new QTextBrowser(menuBox); //box for the main character Name in the menu
    nameMenuBox->setGeometry(0, 0, 240, 42);
    nameMenuBox->setText( map->getMainCharacName());
    nameMenuBox->setFrameShape(QFrame::NoFrame);

    dragonMenuBox = new QTextBrowser(menuBox); //box for dragon in the menu
    dragonMenuBox->setGeometry(32, 42, 208, 42);
    dragonMenuBox->setText("Dragon");
    dragonMenuBox->setFrameShape(QFrame::NoFrame);

    statMenuBox = new QTextBrowser(menuBox); //box for statistique in the menu
    statMenuBox->setGeometry(32, 84, 208, 42);
    statMenuBox->setText("Stat");
    statMenuBox->setFrameShape(QFrame::NoFrame);

    arrowMenuBox[0].setGeometry(0, 42, 32, 42);
    arrowMenuBox[0].setParent(menuBox);
    arrowMenuBox[0].setFrameShape(QFrame::NoFrame);
    arrowMenuBox[1].setGeometry(0, 84, 32, 42);
    arrowMenuBox[1].setParent(menuBox);
    arrowMenuBox[1].setFrameShape(QFrame::NoFrame);
}

void GameWindow::createDragonBox()
{
    //creation of the box which show the main character's dragons
    dragonBox = new QWidget(this);
    dragonBox->setAutoFillBackground(true);
    dragonBox->setPalette(QColor(255, 255, 255));
    dragonBox->setGeometry(0, 500, 1301, 171);
    dragonBox->setFont(QFont("Aria", 15));
    dragonBox->hide();

    int i=0;
    for(i=0; i<5; i++)
    {
        //box for the arrow
        arrowDragBox[i].setParent(dragonBox);
        placeArrowDragBox();
        arrowDragBox[i].setGeometry(0, 32*i, 32, 32);
        arrowDragBox[i].setFrameShape(QFrame::NoFrame);

        //box for the dragon surname and level
        dragonTextTab[i].setParent(dragonBox);
        dragonTextTab[i].setGeometry(32, 32*i, 1000, 32);
        QString text = textDragonMC(i);
        dragonTextTab[i].setText(text);
        dragonTextTab[i].setFrameShape(QFrame::NoFrame);
    }
}

void GameWindow::movement(int mv)
{
    if(talk == true || menu == true || combat == true || dragon == true)
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
    if(talk == true || dragon == true) return; //can't open menu if talking or if the dragon info is open

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

void GameWindow::placeArrowInMenu()
{
    //number of section is 2, maybe create a var to count the number of section and use it here
    //(in case, in the future, if I increase the number of section...)
    int i=0;
    for(i=0; i < 2; i++)
        arrowMenuBox[i].setText("");

    arrowMenuBox[arrowMenu].setText(">");
}

void GameWindow::placeArrowDragBox()
{
    int i=0;
    for(i=0; i < 2; i++)
        arrowDragBox[i].setText("");

    arrowDragBox[arrowDragonInfo].setText(">");
}

QString GameWindow::placeArrowCombatBox(QString text)
{
    int nbrAtk = map->getMainCharacDragonAttackNB(0);


}

bool GameWindow::validMoveArrow(int mv, int arrow)
{
    if(arrow == 0)
    {
        if(mv == up && arrowMenu > 0) return true;

        if(mv == bottom && arrowMenu < 1) return true;
    }

    if(arrow == 1)
    {
        if(mv == up && arrowDragonInfo > 0) return true;

        if(mv == bottom && arrowDragonInfo < map->getMainCharacterNBDragon() ) return true;
    }

    return false;
}

void GameWindow::moveArrow(int mv)
{
    if(menu == true)
    {
        if( validMoveArrow(mv, 0))
        {
            if(mv == up) setArrowMenu(getArrowMenu()-1);

            if(mv == bottom) setArrowMenu(getArrowMenu()+1);
        }
    }

    if(dragon == true)
    {
        if( validMoveArrow(mv, 1))
        {
            if(mv == up) setArrowDragInfo(getArrowDragonInfo()-1);

            if(mv == bottom) setArrowDragInfo(getArrowDragonInfo()+1);
        }
    }
}

int GameWindow::getArrowDragonInfo()
{
    return arrowDragonInfo;
}

int GameWindow::getArrowMenu()
{
    return arrowMenu;
}

void GameWindow::setArrowMenu(int placeArrow)
{
    arrowMenu = placeArrow;
    repaint();
}

void GameWindow::setArrowDragInfo(int placeArrow)
{
    arrowDragonInfo = placeArrow;
    repaint();
}

void GameWindow::openRubrikMenu()
{
    if(menu == 1)
    {
        if(arrowMenu == 0)
        {
            menu = 0;
            setDragonBox(true);
        }
    }
}

QString GameWindow::textDragonMC(int i)
{
    QString text="";

    QString dragonSurname = map->getMainCharacterDragonSurname(i);
    int dragonLvl = map->getMainCharacterDragonLevel(i);
    QString STR_Lvl=""; STR_Lvl.setNum(dragonLvl);

    text.append(dragonSurname + " lvl: " + STR_Lvl);

    return text;
}

QString GameWindow::textDragonInfoMC()
{
    QString text = "";

    QString dragonName = map->getMainCharacterDragonName(arrowDragonInfo);
    QString dragonSurname = map->getMainCharacterDragonSurname(arrowDragonInfo);
    int dragonLvl = map->getMainCharacterDragonLevel(arrowDragonInfo);
    QString dragonLvlSTR =""; dragonLvlSTR.setNum(dragonLvl);
    int dragonType = map->getMainCharacterDragonType(arrowDragonInfo);
    QString dragonTypeSTR = convert_Type2Str(dragonType);

    text.append(dragonName + '\n' +
                dragonSurname + '\n' +
                "Level : " + dragonLvlSTR + '\n' +
                "Type : " + dragonTypeSTR + "\nAttack :\n");

    Attack* atk = map->getMainCharacDragonAttack(arrowDragonInfo);
    int nbAtk = map->getMainCharacDragonAttackNB(arrowDragonInfo);

    int i=0;
    for(i=0; i < nbAtk; i++)
    {
        QString nameAtk = atk[i].getNameAttack();
        QString typeAtk = convert_Type2Str(atk[i].getTypeAttack());
        int sghAtk = atk[i].getStrengthAttack();
        QString sghAtkSTR = ""; sghAtkSTR.setNum(sghAtk);
        text.append("  " + nameAtk + "  " + typeAtk + "  " + sghAtkSTR +'\n');
    }

    return text;
}

QString GameWindow::textCombatMC()
{
    QString text = "";

    QString surnameDragon = map->getMainCharacterDragonSurname(0);
    text.append(surnameDragon + " :\n");

    Attack* atk = map->getMainCharacDragonAttack(0);
    int nbAtk = map->getMainCharacDragonAttackNB(arrowDragonInfo);

    int i = 0;
    for(i=0; i < nbAtk; i++)
    {
        QString nameAtk = atk[i].getNameAttack();
        QString typeAtk = convert_Type2Str(atk[i].getTypeAttack());
        int sghAtk = atk[i].getStrengthAttack();
        QString sghAtkSTR = ""; sghAtkSTR.setNum(sghAtk);
        text.append("     " + nameAtk + "  " + typeAtk + "  " + sghAtkSTR + "\t\t");

        if(i == 1)
            text.append("\n");
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
            dialogBox->hide();
        else
            dialogBox->show();

        //the widget for the menu
        if(menu == false)
            menuBox->hide();
        else
        {
            placeArrowInMenu();
            menuBox->show();            
        }

        //the widget for the dragon menu
        if(dragon == false)
        {
            dragonBox->hide();
            dragonInfoBox->hide();
        }
        else
        {
            placeArrowDragBox();
            dragonBox->show();

            QString text = textDragonInfoMC();
            dragonInfoBox->setText(text);
            dragonInfoBox->show();
        }

        dragonAttackBox->hide();

        ennemyDragonBox->hide();
    }

    else
    {
        QString text = textCombatMC();
        dragonAttackBox->setText(text);
        dragonAttackBox->show();

        ennemyDragonBox->show();
    }
}


