#ifndef PROXY_H
#define PROXY_H

#include <QObject>
#include <QString>

class Proxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString player READ getPlayer WRITE setPlayer)
public:
    explicit Proxy(QObject *parent = nullptr);
    void setPlayer(const QString& p);
    const QString& getPlayer() const;

public slots:
    void on_new_game();

signals:
    void new_game_requested(QString who_is_starting);

private:
    QString m_player{"x"};

};

#endif // PROXY_H
