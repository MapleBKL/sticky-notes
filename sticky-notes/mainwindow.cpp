#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listnoteitem.h"
#include "fixedheightdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listNotes->setItemDelegate(new FixedHeightDelegate(70, ui->listNotes));
    setWindowFlags(Qt::FramelessWindowHint);
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

void MainWindow::add_item_to_list(NoteWidget *note)
{
    ListNoteItem* listNoteItem = new ListNoteItem(this);
    connect(note, &NoteWidget::content_changed, listNoteItem, &ListNoteItem::on_contentChanged);
    QListWidgetItem* item = new QListWidgetItem;
    ui->listNotes->addItem(item);
    ui->listNotes->setItemWidget(item, listNoteItem);
}


void MainWindow::on_btnNewNote_clicked()
{
    // create a new note window
    NoteWidget* note = new NoteWidget();
    note->show();
    note->initialize_connection(this);

    // add the corresponding item to the list widget
    add_item_to_list(note);
}

void MainWindow::on_newNoteCreated(NoteWidget* note)
{
    note->initialize_connection(this);
    add_item_to_list(note);
}

