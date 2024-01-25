#ifndef CHUPIAO_H
#define CHUPIAO_H
#include <QList>
//数组 字节数组头文件
#include <QByteArray>
#include <QString>
#include <QDebug>
//时间头文件  小时  分  秒
#include <QTime>
//日期头文件   年  月  日
#include <QDate>
//数据库头文件
#include <QSqlDatabase>
//弹出消息框头文件
#include <QMessageBox>
//数据库错误处理头文件
#include <QSqlError>
//数据库查询头文件
#include <QSqlQuery>
//数据的参数绑定头文件
#include <QVariantList>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "kaiguan.h"
#include "chepiaoxinxi.h"
#include "chepiaoxinxijihe.h"
#include <QString>
#include "num_tic.h"
class ChuPiao : public QWidget
{
    Q_OBJECT
public:
    explicit ChuPiao(QWidget *parent = nullptr);
    QLabel label;
    QPushButton button_ok;
    QPushButton button_can;
    void button_can_clicked();//button_can按钮的槽函数
    void button_ok_clicked();//button_ok按钮的槽函数

    Num_Tic number;
signals:

public slots:
};

#endif // CHUPIAO_H
