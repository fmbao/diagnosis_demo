#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QToolBar>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建媒体图
    Phonon::MediaObject *mediaObject = new Phonon::MediaObject(this);
    videoWidget = new Phonon::VideoWidget(this);
    Phonon::createPath(mediaObject, videoWidget);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory,
                                                               this);
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->setCurrentSource(Phonon::MediaSource("../myPhonon3/myVideo.WMV"));

    // 创建播放进度滑块
    Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider(mediaObject, this);

    // 创建工具栏，包含了播放、暂停和停止动作，以及控制音量滑块
    QToolBar *toolBar = new QToolBar(this);
    QAction *playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("播放"), this);
    connect(playAction, SIGNAL(triggered()), mediaObject, SLOT(play()));
    QAction *pauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPause), tr("暂停"), this);
    connect(pauseAction, SIGNAL(triggered()), mediaObject, SLOT(pause()));
    QAction *stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("停止"), this);
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
    Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider(audioOutput, this);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    toolBar->addAction(playAction);
    toolBar->addAction(pauseAction);
    toolBar->addAction(stopAction);
    toolBar->addWidget(volumeSlider);

    // 创建布局管理器，将各个部件都添加到布局管理器中
    QVBoxLayout *mainLayout = new QVBoxLayout;
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(videoWidget);
    mainLayout->addWidget(seekSlider);
    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(ui->frame);
    setLayout(mainLayout);

    // 设置Widget和VideoWidget都使用自定义上下文菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    videoWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(videoWidget, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(showContextMenu(const QPoint &)));
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(showContextMenu(const QPoint &)));
    // 创建上下文菜单
    createContextMenu();
}

Widget::~Widget()
{
    delete ui;
}

// 更改亮度
void Widget::on_horizontalSlider_valueChanged(int value)
{
    videoWidget->setBrightness(value / 10.0);
}

// 更改色调
void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    videoWidget->setHue(value / 10.0);
}

// 更改饱和度
void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    videoWidget->setSaturation(value / 10.0);
}

// 更改对比度
void Widget::on_horizontalSlider_4_valueChanged(int value)
{
    videoWidget->setContrast(value / 10.0);
}

void Widget::createContextMenu()
{
    mainMenu = new QMenu(this);
    // 创建“宽高比”子菜单
    QMenu *aspectMenu = mainMenu->addMenu(tr("宽高比"));
    QActionGroup *aspectGroup = new QActionGroup(aspectMenu);
    connect(aspectGroup, SIGNAL(triggered(QAction*)), this, SLOT(aspectChanged(QAction*)));
    aspectGroup->setExclusive(true);
    QAction *aspectActionAuto = aspectMenu->addAction(tr("自动"));
    aspectActionAuto->setCheckable(true);
    aspectActionAuto->setChecked(true);
    aspectGroup->addAction(aspectActionAuto);
    QAction *aspectActionScale = aspectMenu->addAction(tr("缩放"));
    aspectActionScale->setCheckable(true);
    aspectGroup->addAction(aspectActionScale);
    QAction *aspectAction16_9 = aspectMenu->addAction(tr("16:9"));
    aspectAction16_9->setCheckable(true);
    aspectGroup->addAction(aspectAction16_9);
    QAction *aspectAction4_3 = aspectMenu->addAction(tr("4:3"));
    aspectAction4_3->setCheckable(true);
    aspectGroup->addAction(aspectAction4_3);
    // 创建“缩放模式”子菜单
    QMenu *scaleMenu = mainMenu->addMenu(tr("缩放模式"));
    QActionGroup *scaleGroup = new QActionGroup(scaleMenu);
    connect(scaleGroup, SIGNAL(triggered(QAction*)), this, SLOT(scaleChanged(QAction*)));
    scaleGroup->setExclusive(true);
    QAction *scaleActionFit = scaleMenu->addAction(tr("保持宽高比"));
    scaleActionFit->setCheckable(true);
    scaleActionFit->setChecked(true);
    scaleGroup->addAction(scaleActionFit);
    QAction *scaleActionCrop = scaleMenu->addAction(tr("缩放和裁剪"));
    scaleActionCrop->setCheckable(true);
    scaleGroup->addAction(scaleActionCrop);
    // 创建“全屏”动作
    QAction *fullScreenAction = mainMenu->addAction(tr("全屏"));
    fullScreenAction->setCheckable(true);
    connect(fullScreenAction, SIGNAL(toggled(bool)), videoWidget, SLOT(setFullScreen(bool)));
}

// 显示上下文菜单
void Widget::showContextMenu(const QPoint &pos)
{
    mainMenu->popup(videoWidget->isFullScreen() ? pos : mapToGlobal(pos));
}

// 设置宽高比
void Widget::aspectChanged(QAction *action)
{
    if (action->text() == tr("16:9"))
        videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatio16_9);
    else if (action->text() == tr("缩放"))
        videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioWidget);
    else if (action->text() == tr("4:3"))
        videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatio4_3);
    else
        videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
}

// 设置缩放模式
void Widget::scaleChanged(QAction *action)
{
    if (action->text() == tr("缩放和裁剪"))
        videoWidget->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
    else
        videoWidget->setScaleMode(Phonon::VideoWidget::FitInView);
}
