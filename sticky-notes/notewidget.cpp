#include "notewidget.h"
#include "ui_notewidget.h"
#include "mainwindow.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
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
    this->deleteLater();
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

void NoteWidget::set_list_item(ListNoteItem *listItem)
{
    this->listItem = listItem;
}

void NoteWidget::on_deleteConfirmed(ListNoteItem *listItem)
{
    Q_UNUSED(listItem);
    this->close();
    this->deleteLater();
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


void NoteWidget::on_btnDelete_clicked()
{
    auto decision = QMessageBox::question(this, "", "Delete this note?");
    if (decision == QMessageBox::Yes)
    {
        emit delete_confirmed(listItem);
        this->close();
        this->deleteLater();
    }
}


void NoteWidget::on_btnBold_clicked(bool checked)
{
    // set the selected text to bold
    QTextCursor cursor = ui->textEditContent->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontWeight(checked ? QFont::Bold : QFont::Normal);
    cursor.mergeCharFormat(format);
    ui->textEditContent->setTextCursor(cursor);
}


void NoteWidget::on_btnItalic_clicked(bool checked)
{
        // set the selected text to italic
    QTextCursor cursor = ui->textEditContent->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontItalic(checked);
    cursor.mergeCharFormat(format);
    ui->textEditContent->setTextCursor(cursor);
}


void NoteWidget::on_btnUnderline_clicked(bool checked)
{
        // set the selected text to underline
    QTextCursor cursor = ui->textEditContent->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontUnderline(checked);
    cursor.mergeCharFormat(format);
    ui->textEditContent->setTextCursor(cursor);
}

