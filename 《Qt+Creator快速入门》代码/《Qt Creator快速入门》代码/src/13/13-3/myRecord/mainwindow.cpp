#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QAudioOutput>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 开始录制按钮,将音频录制到指定的文件中
void MainWindow::on_pushButton_clicked()
{
    file.setFileName("test.raw");
    file.open( QIODevice::WriteOnly | QIODevice::Truncate );

    //设置音频格式，包括采样率、声道数量、样本大小、编码、字节顺序和样本类型等
    QAudioFormat format;
    format.setFrequency(8000);
    format.setChannels(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    //获取默认的音频输入设备，判断是否支持指定的格式，如果不支持则使用一个邻近的格式
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        format = info.nearestFormat(format);
    }

    //设置定时器实现录制10秒后自动停止
    QTimer::singleShot(10000, this, SLOT(stopRecording()));
    audioInput = new QAudioInput(format, this);
    audioInput->start(&file);
    ui->label->setText(tr("正在录制……"));
}

// 停止录制
void MainWindow::stopRecording()
{
    audioInput->stop();
    ui->label->setText(tr("停止录制！"));
    file.close();
    delete audioInput;
}

// 开始播放按钮，播放指定的文件
void MainWindow::on_pushButton_2_clicked()
{
    file.setFileName("test.raw");
    file.open(QIODevice::ReadOnly);

    QAudioFormat format;
    format.setFrequency(8000);
    format.setChannels(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        return;
    }

    audioOutput = new QAudioOutput(format, this);
    connect(audioOutput, SIGNAL(stateChanged(QAudio::State)), SLOT(finishedPlaying(QAudio::State)));
    audioOutput->start(&file);
    ui->label->setText(tr("正在播放……"));
}

//停止播放
void MainWindow::finishedPlaying(QAudio::State state)
{
    if (state == QAudio::IdleState) {
        audioOutput->stop();
        ui->label->setText(tr("停止播放"));
        file.close();
        delete audioOutput;
    }
}
