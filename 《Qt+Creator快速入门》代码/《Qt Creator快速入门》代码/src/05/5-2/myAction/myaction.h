#ifndef MYACTION_H
#define MYACTION_H

#include <QWidgetAction>
class QLineEdit; //前置声明
class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyAction(QObject *parent = 0);
protected:
    QWidget* createWidget(QWidget *parent);
    //声明函数，该函数是QWidgetAction类中的虚函数

signals:
    void getText(const QString &string);
    //新建信号，用于在按下回车键时，将行编辑器中的内容发射出去
private slots:
    void sendText(); //新建槽，它用来与行编辑器的按下回车键信号关联
private:
    QLineEdit *lineEdit; //定义行编辑器对象的指针

};

#endif // MYACTION_H
