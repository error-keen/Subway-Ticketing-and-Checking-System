#ifndef MASSAGE_H
#define MASSAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
class Massage : public QWidget
{
    Q_OBJECT
public:
    explicit Massage(QWidget *parent = nullptr);
    QLabel label;
    QPushButton button_ok;

    void button_ok_clicked();//button_ok按钮的槽函数
signals:

public slots:
};

#endif // MASSAGE_H
