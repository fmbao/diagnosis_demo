#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QLineEdit>

#include <QListWidget>
#include <QWebHistory>

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
    // 添加历史动作
    ui->mainToolBar->addAction(tr("历史"), this, SLOT(showHistory()));
    // 添加查找动作
    ui->mainToolBar->addAction(tr("查找"), this, SLOT(findText()));
    ui->mainToolBar->addWidget(locationEdit);

    // 设置并加载初始网页地址
    locationEdit->setText("http://www.baidu.com");
    view->load(QUrl("http://www.baidu.com"));

    // 必须先设置图标数据库路径
    view->settings()->setIconDatabasePath("./");
    connect(view, SIGNAL(iconChanged()), this, SLOT(changeIcon()));

    historyList = new QListWidget;
    historyList->setWindowTitle(tr("历史记录"));
    historyList->setMinimumWidth(300);
    connect(historyList, SIGNAL(clicked(QModelIndex)),
            this, SLOT(gotoHistory(QModelIndex)));

    view->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(view->page(), SIGNAL(linkClicked(QUrl)),
            this, SLOT(urlChanged(QUrl)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete historyList;
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

// 更改网站图标
void MainWindow::changeIcon()
{
    setWindowIcon(view->icon());
}

// 显示历史记录
void MainWindow::showHistory()
{
    QList<QWebHistoryItem> list;
    list = view->history()->items();

    historyList->clear();
    foreach (QWebHistoryItem item, list) {
        QListWidgetItem *history = new QListWidgetItem(item.icon(), item.title());
        historyList->addItem(history);
    }
    historyList->show();
}

// 转到历史记录
void MainWindow::gotoHistory(QModelIndex index)
{
    QUrl url = view->history()->itemAt(index.row()).url();
    view->load(url);
}

// 点击超链接时进行跳转
void MainWindow::urlChanged(QUrl url)
{
    view->load(url);
}

// 查找字符串
void MainWindow::findText()
{
    view->page()->findText("yafeilinux", QWebPage::HighlightAllOccurrences);
}
