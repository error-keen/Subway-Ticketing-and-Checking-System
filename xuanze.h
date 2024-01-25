#ifndef XUANZE_H
#define XUANZE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class XuanZe : public QWidget
{
    Q_OBJECT
public:
    explicit XuanZe(QWidget *parent = nullptr);
    QLabel label;
    QPushButton button_ok;

    void button_ok_clicked();//button_ok按钮的槽函数
signals:

public slots:
};

#endif // XUANZE_H
