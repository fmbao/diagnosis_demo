#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <phonon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Phonon::MediaObject *mediaObject = new Phonon::MediaObject(this);
    Phonon::VideoWidget *videoWidget = new Phonon::VideoWidget(this);
    Phonon::createPath(mediaObject, videoWidget);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory,
                                                               this);
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->setCurrentSource(Phonon::MediaSource("../myPhonon2/myVideo.WMV"));
    videoWidget->resize(400, 300);
    mediaObject->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
