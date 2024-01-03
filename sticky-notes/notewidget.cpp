#include "notewidget.h"
#include "ui_notewidget.h"
#include "mainwindow.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

void NoteWidget::initialize_connection(MainWindow *mainWindow)
{
    connect(this, &NoteWidget::new_note_created, mainWindow, &MainWindow::on_newNoteCreated);
    connect(ui->textEditContent, &QTextEdit::textChanged, this, &NoteWidget::content_changed);
}

QTextEdit *NoteWidget::get_content()
{
    return ui->textEditContent;
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


void NoteWidget::on_btnPin_clicked()
{
    Qt::WindowFlags flags = this->windowFlags();
    if (flags & Qt::WindowStaysOnTopHint)
    {
        // clear the flag and set checked to false
        flags &= ~Qt::WindowStaysOnTopHint;
        ui->btnPin->setChecked(false);
    }
    else
    {
        // set the flag and set checked to true
        flags |= Qt::WindowStaysOnTopHint;
        ui->btnPin->setChecked(true);
    }

    // update window flags
    this->setWindowFlags(flags);
    this->show();
}

