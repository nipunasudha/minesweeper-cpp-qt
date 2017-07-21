#include<QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "box.h"
#include "utils.h"
#include <cstdlib>
#include <ctime>
#define SIZE 10
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    setupGrid();
    printf("count - %d\n",findBombCount(9,9));
}
//TODO connect clicked of box only to parent! ;)
void MainWindow::setupGrid(){

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            bool bomb=(utils::randbool(5));
            Box *b=new Box("Yeah sure",bomb);
            grid[i][j]=b;
            b->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
            b->setFocusPolicy(Qt::NoFocus);
            ui->mineField->addWidget(b,i,j);
        }
    }
}
int MainWindow::findBombCount(int x,int y){
    int count;
    for(int i=-1;i<=1;i++){
        if(x+i<0 || x+i>SIZE-1)continue;
        for(int j=-1;j<=1;j++){
            if(y+j<0 || y+j>SIZE-1 || (i==0 && j==0))continue;
            printf("x=%d y=%d\n",x+i,y+j);
            Box* box=grid[x+i][y+j];
            if(box->isBomb())count++; 
        }
    }
    return count;
}
MainWindow::~MainWindow()
{
    delete ui;
}

