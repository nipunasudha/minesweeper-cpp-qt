#include "box.h"
#include <QtGui>
#include <iostream>
#include "utils.h"

Box::Box(const QString & text,bool bomb, QWidget * parent) : QPushButton(text, parent)
{ 
    bombCount=0;
    boxState=BoxState::unclicked;
    setBomb(bomb);
    connect(this,SIGNAL(clicked()),this,SLOT(boxClicked()));
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
    if(boxState==BoxState::unclicked){
        setText(""); 
    }else if(boxState==BoxState::clicked){
        setText("O"); 
        setEnabled(false);
    }else if(boxState==BoxState::exploded){
        setText("X"); 
        setEnabled(false);
    }

}

