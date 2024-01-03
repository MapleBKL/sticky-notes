#include "notewidget.h"
#include "ui_notewidget.h"
#include "mainwindow.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

void NoteWidget::initialize_connection(MainWindow *mainWindow)
{
    connect(this, &NoteWidget::new_note_created, mainWindow, &MainWindow::on_newNoteCreated);
}

void NoteWidget::on_btnClose_clicked()
{
    this->close();
}

void NoteWidget::mousePressEvent(QMouseEvent *event)
{
    dragPos = event->globalPosition().toPoint();
}

void NoteWidget::mouseMoveEvent(QMouseEvent *event)
{
    move(pos() + event->globalPosition().toPoint() - dragPos);
    dragPos = event->globalPosition().toPoint();
    event->accept();
}

// void Note::paintEvent(QPaintEvent *event)
// {
//     Q_UNUSED(event);

//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing, true);
//     painter.setBrush(QColor(255, 255, 255, 0));
//     painter.drawRoundedRect(rect(), 10, 10);
// }

void NoteWidget::on_btnNewNote_clicked()
{
    // create a new note window
    NoteWidget* note = new NoteWidget();
    note->show();

    // send a signal to notify main window
    emit new_note_created(note);
}

