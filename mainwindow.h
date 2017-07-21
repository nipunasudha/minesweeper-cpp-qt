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
        Ui::MainWindow *ui;

};
#endif
