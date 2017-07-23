#include "box.h"
#include <QtGui>
#include <iostream>
#include "utils.h"

Box::Box(const QString & text,bool bomb, QWidget * parent) : QPushButton(text, parent)
{ 
    bombCount=0;
    boxState=BoxState::unclicked;
    setBomb(bomb);
    //connect(this,SIGNAL(clicked()),this,SLOT(boxClicked()));
    update();
}


void Box::setBombCount(int c){

}
bool Box::isBomb(){

    return bomb;
}
void Box::setBomb(bool b){
    bomb=b;
}
void Box::flag(){

}
bool Box::boxClicked(){

    boxState=isBomb()?BoxState::exploded:BoxState::clicked;
    update();
    return isBomb();
}
void Box::update(){
    QString style="";
    if(boxState==BoxState::unclicked){
        if(isBomb()){
            style+="QPushButton {background-color: rgb(255, 180, 180);border-style: inset;border:1px solid #666;}";
        }else{
            style+="QPushButton {background-color: rgb(255, 255, 255);border-style: inset;border:1px solid #666;}";
        }
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

