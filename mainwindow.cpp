#include<QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "box.h"

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			Box *b=new Box("Yeah sure",false);
			b->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
			b->setFocusPolicy(Qt::NoFocus);
			b->setStyleSheet("QPushButton:pressed { \
					background-color: rgb(224, 0, 0);        \
					border-style: inset;                     \
					}");
		ui->mineField->addWidget(b,i,j);
		}
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

