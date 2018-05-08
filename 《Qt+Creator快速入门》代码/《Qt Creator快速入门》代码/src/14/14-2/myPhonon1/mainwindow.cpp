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
    Phonon::MediaObject *mediaObject = new Phonon::MediaObject(this);
    mediaObject->setCurrentSource(Phonon::MediaSource("../myPhonon1/mysong.mp3"));
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::Path path = Phonon::createPath(mediaObject, audioOutput);
    mediaObject->play();

    // 获取可用的音频效果的描述
    QList<Phonon::EffectDescription> effectDescriptions =
                Phonon::BackendCapabilities::availableAudioEffects();
    qDebug() << effectDescriptions;
    Phonon::EffectDescription effectDescription = effectDescriptions.at(5);
    // 使用指定的音频效果的描述来创建音频效果
    Phonon::Effect *effect = new Phonon::Effect(effectDescription);
    // 在路径中插入音频效果
    path.insertEffect(effect);
    // 创建效果部件，它可以用来更改效果中的参数
    Phonon::EffectWidget *effectWidget = new Phonon::EffectWidget(effect);
    effectWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
