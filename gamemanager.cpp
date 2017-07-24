#include<QtGui>
#include "mainwindow.h"
#include "gamemanager.h"

GameManager::GameManager(QWidget *parent){
    gameCounter=0;
    parent=parent;
    setupNewGame();
}
void GameManager::setupNewGame(){

    if(gameCounter>0)game->deleteLater();
    game=new MainWindow();
    connect(game,SIGNAL(newGame()),this,SLOT(setupNewGame()));
    game->show();
    printf("New game created!\n");
    gameCounter++;
}










