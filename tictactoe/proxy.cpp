#include "proxy.h"
#include <QDebug>

Proxy::Proxy(QObject *parent)
    : QObject{parent}
{

}

void Proxy::on_new_game()
{
    qDebug() << "on new game";
    emit new_game_requested("x");
}
