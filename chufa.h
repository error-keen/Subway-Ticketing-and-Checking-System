#ifndef CHUFA_H
#define CHUFA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "kaiguan.h"
class ChuFa : public QWidget
{
    Q_OBJECT
public:
    explicit ChuFa(QWidget *parent = nullptr);
    QLabel label;
    QPushButton button_ok;
    QPushButton button_can;
    void button_can_clicked();//button_can按钮的槽函数
    void button_ok_clicked();//button_ok按钮的槽函数

signals:

public slots:
};

#endif // CHUFA_H
