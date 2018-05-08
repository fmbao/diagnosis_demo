#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <phonon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Phonon::VideoPlayer *player =
             new Phonon::VideoPlayer(Phonon::VideoCategory, this);
    player->resize(400, 300);
    player->play(Phonon::MediaSource("../myPhonon2/myVideo.WMV"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
