#include "box.h"
#include <QtGui>
#include <iostream>
#include "utils.h"

Box::Box(const QString & text,bool bomb, QWidget * parent) : QPushButton(text, parent)
{ 
    bombCount=0;
    flagged=false;
    boxState=BoxState::unclicked;
    setBomb(bomb);
    update();
}


void Box::setBombCount(int c){
    if(c!=0)setText(QString::number(c));
}
bool Box::isBomb(){

    return bomb;
}
bool Box::isFlagged(){

    return flagged;
}
void Box::setBomb(bool b){
    bomb=b;
}
void Box::flag(){
    if(boxState==BoxState::unclicked){
        flagged=!flagged;
        setText(flagged?"X":"");
    }
}
bool Box::isClicked(){
    return (boxState==BoxState::clicked);
}
bool Box::boxClicked(){

    boxState=isBomb()?BoxState::exploded:BoxState::clicked;
    update();
    return isBomb();
}
void Box::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton && !isFlagged())
        emit clicked();
}
bool Box::boxRightClicked(){
    printf("Box:: I was rigtclicked.\n");
    flag();
    return isBomb();
}
void Box::update(){
    QString style="";
    if(boxState==BoxState::unclicked){
#ifdef DEBUG
        if(isBomb()){
            style+="QPushButton {background-color: rgb(255, 180, 180);border-style: inset;border:1px solid #666;}";
        }else{
#endif
            style+="QPushButton {background-color: rgb(255, 255, 255);border-style: inset;border:1px solid #666;}";
#ifdef DEBUG
        }
#endif
        style+="QPushButton:hover {background-color: rgb(255, 250, 214);border-style: inset;}";
        setText(""); 
    }else if(boxState==BoxState::clicked){
        style+="QPushButton {background-color: rgb(220,220,220);border-style: inset;}";
        setEnabled(false);
    }else if(boxState==BoxState::exploded){
        style+="QPushButton {background-color: rgb(255, 0, 0);border-style: inset;}";
        setEnabled(false);
    }
    setStyleSheet(style);

}

