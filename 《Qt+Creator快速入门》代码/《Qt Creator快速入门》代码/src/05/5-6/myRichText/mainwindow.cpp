#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include "mysyntaxhighlighter.h"
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
    // 设置边框样式
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    // 获取光标
    QTextCursor cursor = ui->textEdit->textCursor();
    // 在光标处插入框架
    cursor.insertFrame(frameFormat);

    // 以下是5.2.2节内容
    QAction *action_textFrame = new QAction(tr("框架"),this);
    connect(action_textFrame,SIGNAL(triggered()),this,SLOT(showTextFrame()));
    ui->mainToolBar->addAction(action_textFrame); //在工具栏添加动作

    QAction *action_textBlock = new QAction(tr("文本块"),this);
    connect(action_textBlock,SIGNAL(triggered()),this,SLOT(showTextBlock()));
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("字体"),this);
    action_font->setCheckable(true); //设置动作可以被选中
    connect(action_font,SIGNAL(toggled(bool)),this,SLOT(setTextFont(bool)));
    ui->mainToolBar->addAction(action_font);

    // 以下是5.2.3节内容
    QAction *action_textTable = new QAction(tr("表格"),this);
    QAction *action_textList = new QAction(tr("列表"),this);
    QAction *action_textImage = new QAction(tr("图片"),this);
    connect(action_textTable,SIGNAL(triggered()),this,SLOT(insertTable()));
    connect(action_textList,SIGNAL(triggered()),this,SLOT(insertList()));
    connect(action_textImage,SIGNAL(triggered()),this,SLOT(insertImage()));
    ui->mainToolBar->addAction(action_textTable);
    ui->mainToolBar->addAction(action_textList);
    ui->mainToolBar->addAction(action_textImage);

    // 以下是5.2.4节内容
    QAction *action_textFind = new QAction(tr("查找"),this);
    connect(action_textFind,SIGNAL(triggered()),this,SLOT(textFind()));
    ui->mainToolBar->addAction(action_textFind);

    // 以下是5.2.5节内容
    highlighter = new MySyntaxHighlighter(ui->textEdit->document());

    // 在编辑器中添加文本并且使用html标签
    ui->textEdit->append(tr("<h1><font color=red>使用HTML</font></h1>"));
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

// 插入表格
void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    // 表格格式
    QTextTableFormat format;
    // 表格外边白
    format.setCellSpacing(2);
    // 表格内边白
    format.setCellPadding(10);
    // 插入2行2列表格
    cursor.insertTable(2,2,format);
}

// 插入列表
void MainWindow::insertList()
{
    // 列表格式
    QTextListFormat format;
    // 数字编号
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

// 插入图片
void MainWindow::insertImage()
{
    // 图片格式
    QTextImageFormat format;
    // 图片路径
    format.setName("logo.png");
    ui->textEdit->textCursor().insertImage(format);
}

// 查找文本
void MainWindow::textFind()
{
    // 创建对话框
    QDialog *dlg = new QDialog(this);
    // 创建行编辑器
    lineEdit = new QLineEdit(dlg);
    // 创建按钮
    QPushButton *btn = new QPushButton(dlg);
    btn->setText(tr("查找下一个"));
    // 关联信号与槽
    connect(btn,SIGNAL(clicked()),this,SLOT(findNext()));
    // 创建垂直布局管理器
    QVBoxLayout *layout = new QVBoxLayout;
    // 添加部件
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    // 在对话框中使用布局管理器
    dlg->setLayout(layout);
    dlg->show();
}

// 查找下一个
void MainWindow::findNext()
{
    // 使用查找函数查找指定字符串，查找方式为向后查找
    QString string = lineEdit->text();
    bool isfind = ui->textEdit->find(string,QTextDocument::FindBackward);

    // 如果查找成功，输出字符串所在行和列的编号
    if(isfind){
        qDebug() << tr("行号:%1 列号:%2")
                    .arg(ui->textEdit->textCursor().blockNumber())
                    .arg(ui->textEdit->textCursor().columnNumber());
    }
}


