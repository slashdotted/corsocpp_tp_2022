#ifndef PROXY_H
#define PROXY_H

#include <QObject>

class Proxy : public QObject
{
    Q_OBJECT
public:
    explicit Proxy(QObject *parent = nullptr);

public slots:
    void on_new_game();

signals:
    void new_game_requested(QString who_is_starting);

};

#endif // PROXY_H
