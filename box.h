#ifndef BOX
#define BOX
#include<QtGui>
#include "utils.h"

class Box: public QPushButton
{
    Q_OBJECT
    private:
        int bombCount;
        bool bomb;
        BoxState boxState;
    public:
        Box(const QString & text,bool bomb, QWidget * parent = 0);
        void setBombCount(int c);
        bool isBomb();
        void update();
        void flag();
        public slots:
        void setBomb(bool b);
        bool boxClicked();

};
#endif
