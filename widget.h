#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "chufa.h"
#include "daoda.h"
#include "showtic.h"
#include "xuanze.h"
#include "massage.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    ChuFa start;//出发窗口，显示的就是你确定从次站进入吗
    DaoDa end;//到达窗口，显示的就是 你确定到达次站吗？

    XuanZe choose;
    Massage mass;

    int find(int id1,QString station,int action);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();



    void on_pushButton_25_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_27_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
