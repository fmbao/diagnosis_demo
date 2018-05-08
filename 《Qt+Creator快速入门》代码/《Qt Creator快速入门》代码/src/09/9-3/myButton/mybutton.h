#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    QString getName(){return "My Button!";}

signals:

public slots:

};

#endif // MYBUTTON_H
