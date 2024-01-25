#include "formrengong.h"
#include "ui_formrengong.h"
#include "chepiaoxinxijihe.h"
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
FormRenGong::FormRenGong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRenGong)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("duanyuhang518.");
    db.setDatabaseName("ditie");
    if(db.open()==false){
        QMessageBox::warning(this,"waring",db.lastError().text());
    }
    //1. 实例化model
    model = new QSqlTableModel(this);
    //2. 将模型设置到视图
    ui->tableView->setModel(model);
    //3. 给model设置数据表，前提条件:数据库已经打开
    model->setTable("chepiao");
    //4. 查询表中所有数据
    model->select();
    //5. 设置表头
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"日期");
    model->setHeaderData(2,Qt::Horizontal,"时间");
    model->setHeaderData(3,Qt::Horizontal,"出发站");
    model->setHeaderData(4,Qt::Horizontal,"到达站");
    model->setHeaderData(5,Qt::Horizontal,"票价");
    model->setHeaderData(6,Qt::Horizontal,"车票状态");
    //6. 设置提交模式 QSqlTableModel::OnManualSubmit 手动提交模式
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

}

FormRenGong::~FormRenGong()
{
    delete ui;
}

void FormRenGong::on_pushButton_clicked()
{
    //表格的改动提交生效，数据库改变
    model->submitAll();
    //改变集合里数据

}

void FormRenGong::on_pushButton_2_clicked()
{
    //表格的改动作废，数据库不变
    model->revertAll();//撤销操作
    model->submitAll();//提交操作 更新数据库
}

void FormRenGong::on_pushButton_3_clicked()
{
    //按照id查找
    //设置过滤条件
    int id= ui->lineEdit->text().toInt();
    QString sql=QString("id=%1").arg(id);
    //设置过滤条件
    model->setFilter(sql);
    //重新查询
    model->select();
}
