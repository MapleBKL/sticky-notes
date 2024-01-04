#include "notewidget.h"
#include "ui_notewidget.h"
#include "mainwindow.h"
#include "colorpicker.h"
#include <QHBoxLayout>
#include <QApplication>

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Tool);
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

void NoteWidget::initialize_connection(MainWindow *mainWindow)
{
    connect(this, &NoteWidget::new_note_created, mainWindow, &MainWindow::on_newNoteCreated);
    connect(ui->textEditContent, &QTextEdit::textChanged, this, &NoteWidget::content_changed);
    connect(qApp, &QGuiApplication::focusWindowChanged, this, &NoteWidget::toggleButtonsVisibility);
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

void NoteWidget::setColor(QString newColor)
{
    // retrieve the current style sheet and split into lines
    QStringList currentStyleSheet = this->styleSheet().split('\n');
    // remove the first line (old background color)
    currentStyleSheet.removeFirst();
    currentStyleSheet.prepend(QString("QWidget { background-color: %1 }").arg(newColor));
    QString newStyleSheet = currentStyleSheet.join('\n');
    this->setStyleSheet(newStyleSheet);
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
    // create a new note widget
    NoteWidget* note = new NoteWidget();
    // position the new note widget right next to the current note widget
    int x = this->geometry().x() + 20;
    int y = this->geometry().y() + 20;
    note->move(x, y);
    note->show();

    // send a signal to notify main window
    emit new_note_created(note);
}


void NoteWidget::on_btnPin_clicked()
{
    // pin the note widget to the top level, above all other windows
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

void NoteWidget::on_btnColor_clicked()
{
    // create a colorpicker window
    // no need to close and delete the colorpicker window here!!
    // it closes itself after a color is chosen
    ColorPicker* colorPicker = new ColorPicker(this);

    // move the colorpicker window to the appropriate position
    // center the colorpicker
    int x = this->geometry().x() + 70;
    int y = this->geometry().y() + 110;
    colorPicker->move(x, y);
    colorPicker->show();
    connect(colorPicker, &ColorPicker::new_color_picked, this, &NoteWidget::setColor);
}

void NoteWidget::toggleButtonsVisibility(QWindow *currWindow)
{
    if (currWindow == this->windowHandle())
    {
        ui->btnClose->show();
        ui->btnPin->show();
        ui->btnColor->show();
        ui->btnNewNote->show();
        ui->btnDelete->show();
        ui->btnBold->show();
        ui->btnItalic->show();
        ui->btnUnderline->show();
    }
    else
    {
        ui->btnClose->hide();
        ui->btnPin->hide();
        ui->btnColor->hide();
        ui->btnNewNote->hide();
        ui->btnDelete->hide();
        ui->btnBold->hide();
        ui->btnItalic->hide();
        ui->btnUnderline->hide();
    }
}

