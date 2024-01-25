#ifndef SHOWTIC_H
#define SHOWTIC_H

#include <QWidget>
#include <QLabel>
#include <QString>

class ShowTic : public QWidget
{
    Q_OBJECT
public:
    explicit ShowTic(QWidget *parent = nullptr);
    QLabel imformation;

signals:

public slots:
};

#endif // SHOWTIC_H
