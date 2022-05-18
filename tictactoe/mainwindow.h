#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Ritorna lo stato della cella: "" (vuota), "O", "X"
    QString stato(int riga, int colonna);
    // Ritorna vero se le condizioni di vittoria sono soddisfatte
    bool vittoria();
    // Array con puntatori ai widget dell'interfaccia grafica
    QPushButton* m_celle[3][3];

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
