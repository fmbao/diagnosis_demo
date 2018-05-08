#include <QApplication>
#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <QFinalState>
#include <QHistoryState>
#include <QMessageBox>

int main(int argc, char* argv[ ])
{
    QApplication app(argc, argv);

    QPushButton button("State Machine");
    QPushButton quitButton("Quit");
    QPushButton interruptButton("interrupt");

    QStateMachine machine;
    QState *s1 = new QState(&machine);
    QState *s11 = new QState(s1);
    QState *s12 = new QState(s1);
    QState *s13 = new QState(s1);
    s1->setInitialState(s11);

    s11->assignProperty(&button, "geometry", QRect(100, 100, 100, 50));
    s12->assignProperty(&button, "geometry", QRect(300, 100, 100, 50));
    s13->assignProperty(&button, "geometry", QRect(200, 200, 100, 50));

    QSignalTransition *transition1 = s11->addTransition(&button,
                                                       SIGNAL(clicked()), s12);
    QSignalTransition *transition2 = s12->addTransition(&button,
                                                       SIGNAL(clicked()), s13);
    QSignalTransition *transition3 = s13->addTransition(&button,
                                                       SIGNAL(clicked()), s11);

    QPropertyAnimation *animation = new QPropertyAnimation(&button, "geometry");
    transition1->addAnimation(animation);
    transition2->addAnimation(animation);
    transition3->addAnimation(animation);

    QObject::connect(s13, SIGNAL(entered()), &button, SLOT(showMinimized()));

    QFinalState *s2 = new QFinalState(&machine);
    s1->addTransition(&quitButton, SIGNAL(clicked()), s2);
    QObject::connect(&machine, SIGNAL(finished()), qApp, SLOT(quit()));

    QHistoryState *s1h = new QHistoryState(s1);

    QState *s3 = new QState(&machine);
    QMessageBox mbox;
    mbox.addButton(QMessageBox::Ok);
    mbox.setText("Interrupted!");
    mbox.setIcon(QMessageBox::Information);
    QObject::connect(s3, SIGNAL(entered()), &mbox, SLOT(exec()));
    s3->addTransition(s1h);

    s1->addTransition(&interruptButton, SIGNAL(clicked()), s3);

    machine.setInitialState(s1);
    machine.start();

    button.show();
    quitButton.move(300, 300);
    quitButton.show();
    interruptButton.show();

    return app.exec();
}


