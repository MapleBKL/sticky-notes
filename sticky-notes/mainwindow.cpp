#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMinimize_clicked()
{
    this->showMinimized();
}


void MainWindow::on_btnClose_clicked()
{
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    dragPos = event->globalPosition().toPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(pos() + event->globalPosition().toPoint() - dragPos);
    dragPos = event->globalPosition().toPoint();
    event->accept();
}

