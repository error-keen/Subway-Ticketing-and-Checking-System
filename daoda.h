#ifndef DAODA_H
#define DAODA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "kaiguan.h"
#include "chupiao.h"
class DaoDa : public QWidget
{
    Q_OBJECT
public:
    explicit DaoDa(QWidget *parent = nullptr);
    QLabel label;
    QPushButton button_ok;
    QPushButton button_can;
    void button_can_clicked();//button_can按钮的槽函数
    void button_ok_clicked();//button_ok按钮的槽函数
    ChuPiao chupiao;
signals:

public slots:
};

#endif // DAODA_H
