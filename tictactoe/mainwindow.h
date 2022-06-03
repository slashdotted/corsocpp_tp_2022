#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "proxy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cell_clicked();
    void on_new_game(const QString& who_is_starting);

private:
    void update_player();
    // Ritorna lo stato della cella: "" (vuota), "O", "X"
    QString get_cell_state(int riga, int colonna);
    // Ritorna vero se le condizioni di vittoria sono soddisfatte
    bool check_victory();
    // Array con puntatori ai widget dell'interfaccia grafica
    QPushButton* m_celle[3][3];
    bool is_x_playing{true};
    Ui::MainWindow *ui;
    Proxy *m_proxy;
    QLabel *m_label;

};
#endif // MAINWINDOW_H
