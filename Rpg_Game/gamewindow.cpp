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
    QWidget(parent), w(1302), h(798), talk(false), dragon(false), menu(false), combat(false), combatAttack(false), combatDragon(false),
    arrowMenu(0), arrowDragonInfo(0), arrowAttackCombat(0), nDragon(0)
{
    //creation of the map
    map = new Map();

    //creation of the box which show the dialog between the main charac and other
    dialogBox = new QTextBrowser(this);
    dialogBox->setGeometry(0, h-121, w, 121);
    dialogBox->hide();
    dialogBox->setFont(QFont("Aria", 16));

    createMenuBox();
    createDragonBox();
    createDragonInfoBox();
    createDragonMCCombatBox();
    createEnemyCombatBox();
}

//Destructor
GameWindow::~GameWindow()
{}

void GameWindow::setSizeGameWindow(int width, int height)
{
    w = width; h = height;
}

void GameWindow::createMenuBox()
{
    //creation of the box which show the menu
    menuBox = new QWidget(this);
    menuBox->setFont(QFont("Aria", 20));
    menuBox->setGeometry(w-240, 0, 240, 666);
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
    dragonBox->setGeometry(0, h-171, w, 171);
    dragonBox->setFont(QFont("Aria", 15));
    dragonBox->hide();

    int i=0, nbDrag = map->getMainCharacNBDragon();
    for(i=0; i<nbDrag; i++)
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

void GameWindow::createDragonInfoBox()
{
    //creation of the box which show the main character's dragons info
    dragonInfoBox = new QWidget(this);
    dragonInfoBox->setGeometry(0, 0, w, 444);
    dragonInfoBox->setFont(QFont("Aria", 21));
    dragonInfoBox->setAutoFillBackground(true);
    dragonInfoBox->setPalette(Qt::white);
    dragonInfoBox->hide();

    dragonNameBox = new QTextBrowser(dragonInfoBox);
    dragonNameBox->setGeometry(0, 0, 300, 42);
    dragonNameBox->setFrameShape(QFrame::NoFrame);

    dragonSurnameBox = new QTextBrowser(dragonInfoBox);
    dragonSurnameBox->setGeometry(0, 42, 300, 42);
    dragonSurnameBox->setFrameShape(QFrame::NoFrame);

    dragonTypeBox = new QTextBrowser(dragonInfoBox);
    dragonTypeBox->setGeometry(0, 84, 300, 42);
    dragonTypeBox->setFrameShape(QFrame::NoFrame);

    dragonLvlBox = new QTextBrowser(dragonInfoBox);
    dragonLvlBox->setGeometry(0, 126, 300, 42);
    QString lvl =""; lvl.setNum(map->getMainCharacDragonLevel(arrowDragonInfo));
    dragonLvlBox->setFrameShape(QFrame::NoFrame);

    dragonAttackTextBox = new QTextBrowser(dragonInfoBox);
    dragonAttackTextBox->setGeometry(0, 168, 300, 42);
    dragonAttackTextBox->setText("Attack :");
    dragonAttackTextBox->setFrameShape(QFrame::NoFrame);

    dragonAttackInfoBox = new QWidget(dragonInfoBox);
    dragonAttackInfoBox->setGeometry(0, 210, 750, 168);

    int i = 0;
    for(i=0; i<4; i++)
    {
        dragonAttackNameInfoBox[i].setParent(dragonAttackInfoBox);
        dragonAttackNameInfoBox[i].setGeometry(0, i*42, 220, 42);
        dragonAttackNameInfoBox[i].setFrameShape(QFrame::NoFrame);

        dragonAttackTypeInfoBox[i].setParent(dragonAttackInfoBox);
        dragonAttackTypeInfoBox[i].setGeometry(220, i*42, 200, 42);
        dragonAttackTypeInfoBox[i].setFrameShape(QFrame::NoFrame);

        dragonAttackStrengthInfoBox[i].setParent(dragonAttackInfoBox);
        dragonAttackStrengthInfoBox[i].setGeometry(420, i*42, 200, 42);
        dragonAttackStrengthInfoBox[i].setFrameShape(QFrame::NoFrame);
    }

    textDragonInfoMC();
}

void GameWindow::createDragonMCCombatBox()
{
    //creation of the box which show the main character's dragons attacks
    dragonMCBox= new QWidget(this);
    dragonMCBox->setGeometry(w-864, h-128, 864, 128);
    dragonMCBox->hide();
    dragonMCBox->setFont(QFont("Aria", 20));
    dragonMCBox->setPalette(Qt::white);
    dragonMCBox->setAutoFillBackground(true);

    dragonMCLifeBar = new QProgressBar(dragonMCBox);
    dragonMCLifeBar->setGeometry(464, 0, 400, 64);

    dragonMCSurnameBox = new QLabel(dragonMCBox);
    dragonMCSurnameBox->setGeometry(464, 64, 200, 64);
    dragonMCSurnameBox->setAlignment(Qt::AlignCenter);
    dragonMCSurnameBox->setAutoFillBackground(true);

    dragonMCLifeBox = new QLabel(dragonMCBox);
    dragonMCLifeBox->setGeometry(664, 64, 200, 64);
    dragonMCLifeBox->setAlignment(Qt::AlignCenter);
    dragonMCLifeBox->setAutoFillBackground(true);

    int i = 0;
    for(i=0; i<4; i++)
    {
        dragonMCArrowBox[i].setParent(dragonMCBox);
        dragonMCArrowBox[i].setGeometry( (i%2)*232, (i/2)*64, 32, 64);
        dragonMCArrowBox[i].setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        dragonMCArrowBox[i].setAutoFillBackground(true);

        dragonMCActionBox[i].setParent(dragonMCBox);
        dragonMCActionBox[i].setGeometry( 32+(i%2)*232, (i/2)*64, 200, 64);
        dragonMCActionBox[i].setAlignment(Qt::AlignCenter);
        dragonMCActionBox[i].setAutoFillBackground(true);
    }
}

void GameWindow::createEnemyCombatBox()
{
    //creation of the box which show the ennemy dragons info
    ennemyDragonBox = new QWidget(this);
    ennemyDragonBox->setGeometry(0, 0, 764, 128);
    ennemyDragonBox->hide();
    ennemyDragonBox->setFont(QFont("Aria", 21));
    ennemyDragonBox->setPalette(Qt::white);
    ennemyDragonBox->setAutoFillBackground(true);

    ennemyDragonNameBox = new QLabel(ennemyDragonBox);
    ennemyDragonNameBox->setGeometry(0, 0, 150, 64);
    ennemyDragonNameBox->setAlignment(Qt::AlignCenter);
    ennemyDragonNameBox->setAutoFillBackground(true);
    ennemyDragonNameBox->setText("Drako");

    ennemyDragonLvlBox = new QLabel(ennemyDragonBox);
    ennemyDragonLvlBox->setGeometry(150, 0, 100, 64);
    ennemyDragonLvlBox->setAlignment(Qt::AlignCenter);
    ennemyDragonLvlBox->setAutoFillBackground(true);
    ennemyDragonLvlBox->setText("Lvl : 2 !");

    ennemydragonHPBar = new QProgressBar(ennemyDragonBox);
    ennemydragonHPBar->setGeometry(364, 64, 400, 64);
    ennemydragonHPBar->setValue(67);
}

void GameWindow::majBox()
{
    dialogBox->setGeometry(0, h-121, w, 121);

    menuBox->setGeometry(w-240, 0, 240, 666);

    dragonBox->setGeometry(0, h-171, w, 171);

    dragonInfoBox->setGeometry(0, 0, w, 444);

    dragonAttackInfoBox->setGeometry(0, 210, 750, 168);

    dragonMCBox->setGeometry(w-864, h-128, 864, 128);

    ennemyDragonBox->setGeometry(0, 0, 764, 128);
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
    if(talk == true || dragon == true || combat == true) return; //can't open menu if talking or if the dragon info is open

    menu = m;
    repaint();
}

void GameWindow::setDragonBox(bool db)
{
    if(talk == true || combat == true) return; //can't open menu if talking or if the dragon info is open

    dragon = db;
    repaint();
}

void GameWindow::setCombatUI(bool c)
{
    if(talk == true || menu == true || dragon == true) return; //can't open combat when talking or open the menun... Should never happend !

    combat = c;
    repaint();
}

void GameWindow::setCombatUIAttack(bool cA)
{
    if(combat == true)
        combatAttack = cA;

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

void GameWindow::placeArrowCombatBox()
{
    int i=0;
    for(i=0; i<4; i++)
        dragonMCArrowBox[i].setText("");

    dragonMCArrowBox[arrowAttackCombat].setText(">");
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

        if(mv == bottom && arrowDragonInfo < map->getMainCharacNBDragon()-1 ) return true;
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

    if(combat == true)
    {
        moveArrowCombat(mv);
    }
}

void GameWindow::moveArrowCombat(int mv)
{
    /*if(mv == up)
    {
        if(arrowAttackCombat == 3 || arrowAttackCombat == 2)
            arrowAttackCombat -= 2;
    }*/

    if(mv == mv_right)
    {
        if(arrowAttackCombat == 0 || arrowAttackCombat == 2)
            arrowAttackCombat += 1;
    }
    /*
    if(mv == bottom)
    {
        if(arrowAttackCombat == 0 || arrowAttackCombat == 1)
            arrowAttackCombat += 2;
    }*/

    if(mv == mv_left)
    {
        if(arrowAttackCombat == 1 || arrowAttackCombat == 3)
            arrowAttackCombat -= 1;
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

    QString dragonSurname = map->getMainCharacDragonSurname(i);
    int dragonLvl = map->getMainCharacDragonLevel(i);
    QString STR_Lvl=""; STR_Lvl.setNum(dragonLvl);

    text.append(dragonSurname + " lvl: " + STR_Lvl);

    return text;
}

void GameWindow::textDragonInfoMC()
{
    dragonNameBox->setText("Name : " + map->getMainCharacDragonName(arrowDragonInfo));

    dragonSurnameBox->setText("Surname : " + map->getMainCharacDragonSurname(arrowDragonInfo));

    QString type = convert_Type2Str(map->getMainCharacDragonType(arrowDragonInfo));
    dragonTypeBox->setText("Type : " + type);

    QString lvl =""; lvl.setNum(map->getMainCharacDragonLevel(arrowDragonInfo));
    dragonLvlBox->setText("Level : " + lvl);

    Attack* atk = map->getMainCharacDragonAttack(arrowDragonInfo);
    int nbAtk = map->getMainCharacDragonAttackNB(arrowDragonInfo);

    int i=0;
    for(i=0; i < 4; i++)
    {
        QString nameAtk ="", typeAtk="", sghAtkSTR ="";

        if(i<nbAtk) //if i>nbAtk, then there is no longer attack and the text must be empty !
        {
            nameAtk = "  " + atk[i].getNameAttack();
            typeAtk = "Type: " +convert_Type2Str(atk[i].getTypeAttack());
            int sghAtk = atk[i].getStrengthAttack();
            sghAtkSTR.setNum(sghAtk);
            sghAtkSTR.prepend("Strength: ");
        }

        dragonAttackNameInfoBox[i].setText(nameAtk);
        dragonAttackTypeInfoBox[i].setText(typeAtk);
        dragonAttackStrengthInfoBox[i].setText(sghAtkSTR);
    }
}

void GameWindow::textCombatMC()
{
    dragonMCSurnameBox->setText(map->getMainCharacDragonSurname(nDragon));
    int crHP = map->getMainCharacDragonHP(nDragon).getx(), maxHP =  map->getMainCharacDragonHP(nDragon).gety();
    QString crHP_str = "", maxHP_str ="";
    crHP_str.setNum(crHP); maxHP_str.setNum(maxHP);
    dragonMCLifeBox->setText("HP : " + crHP_str +'/' +maxHP_str);
    dragonMCLifeBar->setValue((crHP*100)/maxHP);

    if(combatAttack == false)
    {
        dragonMCActionBox[0].setText("Attack");
        dragonMCActionBox[1].setText("Dragon");
    }
    else
        textCombatMCAttack();
}

void GameWindow::textCombatMCAttack()
{
    Attack* atk = map->getMainCharacDragonAttack(0);
    int nbAtk = map->getMainCharacDragonAttackNB(arrowDragonInfo);

    int i = 0;
    for(i=0; i < nbAtk; i++)
    {
        QString text ="";
        QString nameAtk = atk[i].getNameAttack();
        QString typeAtk = convert_Type2Str(atk[i].getTypeAttack());
        int sghAtk = atk[i].getStrengthAttack();
        QString sghAtkSTR = ""; sghAtkSTR.setNum(sghAtk);
        text.append(nameAtk + "  " + typeAtk + "  " + sghAtkSTR);

        dragonMCActionBox[i].setText(text);
    }
}

void GameWindow::textCombatMCDragon()
{
    int nbDrag = map->getMainCharacNBDragon(); //number of MC dragons

    int i=0, numBox=0; //i for the dragon, numbox for the num of box (5 drag but 4 box !!)
    for(i=0; i < nbDrag; i++)
    {
        if(nDragon != i)
        {
            QString surnameDrag = map->getMainCharacDragonSurname(i);
            dragonMCActionBox[numBox].setText(surnameDrag);
            numBox++;
        }
    }
}

void GameWindow::keySpaceAction()
{
    //Menu open and open dragon info
    if(talk == false && dragon == false && menu == true && combat == false)
    {
        setDragonBox(true);
    }

    //In combat, want to open attack action
    if(talk == false && dragon == false && menu == false && combat == true && combatAttack == false)
    {
        setCombatUIAttack(true);
    }
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
        int nbTileX = w/sizeTile, nbTileY = h/sizeTile;

        int y=0, x=0, posx=pos.getx(), posy=pos.gety();
        for(y = 0; y < nbTileY; ++y) //19 is the number of Tile you can get with the actual window's size
        {
            posTileY = posy+y-(nbTileY-1)/2;
            for(x = 0; x < nbTileX; ++x) //30 is the number of Tile you can get with the actual window's size
            {
                posTileX = posx+x-(nbTileX-1)/2;
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

            textDragonInfoMC();
            dragonInfoBox->show();
        }

        dragonMCBox->hide();

        ennemyDragonBox->hide();
    }

    else
    {
        textCombatMC();
        placeArrowCombatBox();
        dragonMCBox->show();

        ennemyDragonBox->show();
    }
}


