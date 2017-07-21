#ifndef ADBOOK
#define ADBOOK
#include<QtGui>
#include "box.h"

namespace Ui
{
    class MainWindow;
}



class MainWindow: public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent=0);
        ~MainWindow();
        public slots:
    private:
            Box* grid[10][10];
            Ui::MainWindow *ui;
            void setupGrid();
            int findBombCount(int x,int y);

};
#endif
