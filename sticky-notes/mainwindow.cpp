#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notewidget.h"
#include "listnoteitem.h"
#include "fixedheightdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listNotes->setItemDelegate(new FixedHeightDelegate(70, ui->listNotes));
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
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


void MainWindow::on_btnNewNote_clicked()
{
    // create a new note window
    NoteWidget* note = new NoteWidget();
    note->show();

    // add the corresponding item to the list widget
    ListNoteItem* listNoteItem = new ListNoteItem(this);
    QListWidgetItem* item = new QListWidgetItem;
    ui->listNotes->addItem(item);
    ui->listNotes->setItemWidget(item, listNoteItem);
}

