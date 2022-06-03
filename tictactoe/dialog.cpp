#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(const QString &message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(message);
}

Dialog::~Dialog()
{
    delete ui;
}
