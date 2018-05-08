#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <phonon>
#include <QDebug>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << Phonon::BackendCapabilities::availableMimeTypes();
    Phonon::MediaObject *music = Phonon::createPlayer(Phonon::MusicCategory,
                            Phonon::MediaSource("../myPhonon1/mysong.mp3"));
    music->setParent(this);
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
