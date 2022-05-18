#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ritorna vero se le condizioni di vittoria sono soddisfatte
bool MainWindow::vittoria()
{
return (stato(0,0) == stato(0,1) && stato(0,1) == stato(0,2) &&
stato(0,2) != ""
|| stato(1,0) == stato(1,1) && stato(1,1) == stato(1,2) &&
stato(1,2) != ""
|| stato(2,0) == stato(2,1) && stato(2,1) == stato(2,2) &&
stato(2,2) != ""
|| stato(0,0) == stato(1,0) && stato(1,0) == stato(2,0) &&
stato(2,0) != ""
|| stato(0,1) == stato(1,1) && stato(1,1) == stato(2,1) &&
stato(2,1) != ""
|| stato(0,2) == stato(1,2) && stato(1,2) == stato(2,2) &&
stato(2,2) != ""
|| stato(0,0) == stato(1,1) && stato(1,1) == stato(2,2) &&
stato(2,2) != ""
|| stato(2,0) == stato(1,1) && stato(1,1) == stato(0,2) &&
stato(0,2) != "");
}
// Ritorna lo stato della cella: "" (vuota), "O", "X"
QString MainWindow::stato(int riga, int colonna)
{
return m_celle[riga][colonna]->text();
}

