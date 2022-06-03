#include "proxy.h"
#include <QDebug>

Proxy::Proxy(QObject *parent)
    : QObject{parent}
{

}

void Proxy::setPlayer(const QString &p)
{
    qDebug() << "setPlayer called";
    m_player = p;
}

const QString &Proxy::getPlayer() const
{
    qDebug() << "getPlayer called";
    return m_player;
}

void Proxy::on_new_game()
{
    qDebug() << "on new game";
    emit new_game_requested(m_player);
}
