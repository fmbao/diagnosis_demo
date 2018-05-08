#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    progress = 0;
    view = new QWebView(this);
    setCentralWidget(view);
    resize(800, 600);

    // 关联信号和槽
    connect(view, SIGNAL(loadProgress(int)), this, SLOT(setProgress(int)));
    connect(view, SIGNAL(titleChanged(QString)), this, SLOT(adjustTitle()));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(finishLoading(bool)));

    locationEdit = new QLineEdit(this);
    connect(locationEdit, SIGNAL(returnPressed()), this, SLOT(changeLocation()));

    // 向工具栏添加动作和部件
    ui->mainToolBar->addAction(view->pageAction(QWebPage::Back));
    ui->mainToolBar->addAction(view->pageAction(QWebPage::Forward));
    ui->mainToolBar->addAction(view->pageAction(QWebPage::Reload));
    ui->mainToolBar->addAction(view->pageAction(QWebPage::Stop));
    ui->mainToolBar->addWidget(locationEdit);

    // 设置并加载初始网页地址
    locationEdit->setText("http://www.baidu.com");
    view->load(QUrl("http://www.baidu.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 改变路径
void MainWindow::changeLocation()
{
    QUrl url = QUrl(locationEdit->text());
    view->load(url);
    view->setFocus();
}

// 更新进度
void MainWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
}

// 更新标题显示
void MainWindow::adjustTitle()
{
    if ( progress <= 0 || progress >= 100) {
        setWindowTitle(view->title());
    } else {
        setWindowTitle(QString("%1 (%2%)").arg(view->title()).arg(progress));
    }
}

// 加载完成后进行处理
void MainWindow::finishLoading(bool finished)
{
    if (finished) {
        progress = 100;
        setWindowTitle(view->title());
    } else {
        setWindowTitle("web page loading error!");
    }
}
