#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->etichetta->setText("Hello");
    ui->rotella->setValue(50);
    connect(ui->bottone,SIGNAL(clicked(bool)),this,SLOT(onButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    ui->bottone->setText("Ok");
    ui->rotella->setValue(0);
    Dialog d{this};
    d.exec();

}


void MainWindow::on_miobottone_clicked()
{
    ui->bottone->setText("Ok");
    ui->rotella->setValue(0);
}

