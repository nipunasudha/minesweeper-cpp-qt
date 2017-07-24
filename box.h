#ifndef BOX
#define BOX
#include<QtGui>
#include "utils.h"
//#define DEBUG
class Box: public QPushButton
{
    Q_OBJECT
    private:
        int bombCount;
        bool bomb;
        bool flagged;
        BoxState boxState;
    public:
        Box(const QString & text,bool bomb, QWidget * parent = 0);
        void setBombCount(int c);
        bool isBomb();
        bool isFlagged();
        void update();
        void flag();
        void setBomb(bool b);
        bool boxClicked();
        bool boxRightClicked();
        bool isClicked();
public slots:
        void mousePressEvent(QMouseEvent *e);
signals:
		void rightClicked();

};
#endif
