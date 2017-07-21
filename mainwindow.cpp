#include<QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "box.h"
#include "utils.h"
#include <cstdlib>
#include <ctime>
MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    srand(time(NULL));
	ui->setupUi(this);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
            bool bomb=(utils::randbool(5));
			Box *b=new Box("Yeah sure",bomb);
			b->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
			b->setFocusPolicy(Qt::NoFocus);
		ui->mineField->addWidget(b,i,j);
		}
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

