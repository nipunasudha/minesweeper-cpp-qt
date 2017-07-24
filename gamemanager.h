#ifndef GAME
#define GAME
#include<QtGui>
#include "mainwindow.h"

class GameManager: public QObject
{
    Q_OBJECT
    public:
        GameManager(QWidget *parent=0);
        public slots:
            void setupNewGame();
    private:
        int gameCounter;
        MainWindow *game;
        void makeConnections();

};
#endif
