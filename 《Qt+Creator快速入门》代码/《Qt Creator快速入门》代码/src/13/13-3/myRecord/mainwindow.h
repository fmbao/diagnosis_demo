#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QAudio>
class QAudioInput;
class QAudioOutput;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void stopRecording();
    void finishedPlaying(QAudio::State state);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QFile file;
    QAudioInput* audioInput;
    QAudioOutput* audioOutput;

};

#endif // MAINWINDOW_H
