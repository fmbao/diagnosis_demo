#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 获取文档对象
    QTextDocument *document = ui->textEdit->document();

    // 获取根框架
    QTextFrame *rootFrame = document->rootFrame();

    // 创建框架格式
    QTextFrameFormat format;
    // 边界颜色
    format.setBorderBrush(Qt::red);
    // 边界宽度
    format.setBorder(3);
    // 框架使用格式
    rootFrame->setFrameFormat(format);

    QTextFrameFormat frameFormat;
    // 设置背景颜色
    frameFormat.setBackground(Qt::lightGray);
    // 设置边距
    frameFormat.setMargin(10);
    // 设置填衬
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted); //设置边框样式

    // 获取光标
    QTextCursor cursor = ui->textEdit->textCursor();
    // 在光标处插入框架
    cursor.insertFrame(frameFormat);

   //以下是5.2.2节内容
    QAction *action_textFrame = new QAction(tr("框架"),this);
    connect(action_textFrame,SIGNAL(triggered()),this,SLOT(showTextFrame()));
    // 在工具栏添加动作
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction(tr("文本块"),this);
    connect(action_textBlock,SIGNAL(triggered()),this,SLOT(showTextBlock()));
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("字体"),this);
    // 设置动作可以被选中
    action_font->setCheckable(true);
    connect(action_font,SIGNAL(toggled(bool)),this,SLOT(setTextFont(bool)));
    ui->mainToolBar->addAction(action_font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 遍历框架
void MainWindow::showTextFrame()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    // 建立QTextFrame类的迭代器
    QTextFrame::iterator it;
    for (it = frame->begin(); !(it.atEnd()); ++it) {
         // 获取当前框架的指针
         QTextFrame *childFrame = it.currentFrame();
         // 获取当前文本块
         QTextBlock childBlock = it.currentBlock();
         if (childFrame)
             qDebug() << "frame";
         else if (childBlock.isValid())
             qDebug() << "block:" << childBlock.text();
    }
}

// 遍历文本块
void MainWindow::showTextBlock()
{
    QTextDocument *document = ui->textEdit->document();
    // 获取文档的第一个文本块
    QTextBlock block = document->firstBlock();
    for(int i=0; i<document->blockCount(); i++){
        qDebug() << tr("文本块%1，文本块首行行号为:%2，长度为:%3,内容为：")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();
        // 获取下一个文本块
        block = block.next();
    }
}

// 设置字体格式
void MainWindow::setTextFont(bool checked)
{
    // 如果处于选中状态
    if(checked){
        QTextCursor cursor = ui->textEdit->textCursor();

        // 文本块格式
        QTextBlockFormat blockFormat;
        // 水平居中
        blockFormat.setAlignment(Qt::AlignCenter);
        // 使用文本块格式
        cursor.insertBlock(blockFormat);

        // 字符格式
        QTextCharFormat charFormat;
        // 背景色
        charFormat.setBackground(Qt::lightGray);
        // 字体颜色
        charFormat.setForeground(Qt::blue);
        // 使用宋体，12号，加粗，倾斜
        charFormat.setFont(QFont(tr("宋体"),12,QFont::Bold,true));

        // 使用下划线
        charFormat.setFontUnderline(true);
        // 使用字符格式
        cursor.setCharFormat(charFormat);
        // 插入文本
        cursor.insertText(tr("测试字体"));
    }
    // 如果处于非选中状态，可以进行其他操作
    else{/*恢复默认的字体格式*/}
}


