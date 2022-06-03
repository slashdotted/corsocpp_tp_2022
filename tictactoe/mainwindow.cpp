#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QIcon>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_proxy{new Proxy{this}}
{
    ui->setupUi(this);
    m_label = new QLabel{ui->statusbar};
    // Fill m_celle[3][3];
    m_celle[0][0] = ui->cella_00;
    m_celle[0][1] = ui->cella_01;
    m_celle[0][2] = ui->cella_02;
    m_celle[1][0] = ui->cella_10;
    m_celle[1][1] = ui->cella_11;
    m_celle[1][2] = ui->cella_12;
    m_celle[2][0] = ui->cella_20;
    m_celle[2][1] = ui->cella_21;
    m_celle[2][2] = ui->cella_22;

    // Connect the clicked signal to the slot
    for(int i{0}; i<3; ++i) {
        for(int j{0}; j<3; ++j) {
            connect(m_celle[i][j], SIGNAL(clicked(bool)), this, SLOT(on_cell_clicked()));
        }
    }

   connect(ui->actionNuova, /* Source of the signal (pointer!!!!)*/
           SIGNAL(triggered(bool)), /* Signal emitted */
           m_proxy, /* Receiver */
           SLOT(on_new_game())); /* Slot signature */

   connect(m_proxy, SIGNAL(new_game_requested(QString)),
           this, SLOT(on_new_game(QString)));

   update_player();

}

void MainWindow::on_cell_clicked()
{
    auto cell = static_cast<QPushButton*>(sender());
    if (cell->text().isEmpty()) {
        if (is_x_playing) {
            //cell->setText("X");
            cell->setProperty("player", "x");
            QIcon x{":/icons/x.png"};
            cell->setIcon(x);
        } else {
            //cell->setText("O");
            cell->setProperty("player", "o");
            QIcon o{":/icons/o.png"};
            cell->setIcon(o);
        }
        if (check_victory()) {
            // Prevent further play
            for(int i{0}; i<3; ++i) {
                for(int j{0}; j<3; ++j) {
                    m_celle[i][j]->setEnabled(false);
                }
            }
            // Show the victory dialog
            if (is_x_playing) {
                Dialog victory_dialog{"X has won", this};
                victory_dialog.exec();
            } else {
                Dialog victory_dialog{"O has won", this};
                victory_dialog.exec();
            }
        }
        is_x_playing = !is_x_playing;
        update_player();
    }

}

void MainWindow::on_new_game(const QString &who_is_starting)
{
    is_x_playing = (who_is_starting == "x");
    for(int i{0}; i<3; ++i) {
        for(int j{0}; j<3; ++j) {
            m_celle[i][j]->setEnabled(true);
            m_celle[i][j]->setProperty("player", "");
            m_celle[i][j]->setIcon(QIcon{});
        }
    }
    update_player();
}

void MainWindow::update_player()
{
    m_label->setText(is_x_playing ? "X turn" : "O turn");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void foo(MainWindow v) {

}

void bar(QString s) {


}

// Ritorna vero se le condizioni di vittoria sono soddisfatte
bool MainWindow::check_victory()
{
    //foo(*this);
    bar("hello");
    return (get_cell_state(0,0) == get_cell_state(0,1) && get_cell_state(0,1) == get_cell_state(0,2) &&
            get_cell_state(0,2) != ""
            || get_cell_state(1,0) == get_cell_state(1,1) && get_cell_state(1,1) == get_cell_state(1,2) &&
            get_cell_state(1,2) != ""
            || get_cell_state(2,0) == get_cell_state(2,1) && get_cell_state(2,1) == get_cell_state(2,2) &&
            get_cell_state(2,2) != ""
            || get_cell_state(0,0) == get_cell_state(1,0) && get_cell_state(1,0) == get_cell_state(2,0) &&
            get_cell_state(2,0) != ""
            || get_cell_state(0,1) == get_cell_state(1,1) && get_cell_state(1,1) == get_cell_state(2,1) &&
            get_cell_state(2,1) != ""
            || get_cell_state(0,2) == get_cell_state(1,2) && get_cell_state(1,2) == get_cell_state(2,2) &&
            get_cell_state(2,2) != ""
            || get_cell_state(0,0) == get_cell_state(1,1) && get_cell_state(1,1) == get_cell_state(2,2) &&
            get_cell_state(2,2) != ""
            || get_cell_state(2,0) == get_cell_state(1,1) && get_cell_state(1,1) == get_cell_state(0,2) &&
            get_cell_state(0,2) != "");
}
// Ritorna lo stato della cella: "" (vuota), "O", "X"
QString MainWindow::get_cell_state(int riga, int colonna)
{
    //return m_celle[riga][colonna]->text();
    return m_celle[riga][colonna]->property("player").toString();
}

