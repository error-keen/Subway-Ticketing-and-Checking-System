#include "widget.h"
#include "ui_widget.h"
#include "chupiao.h"
#include "xuanze.h"
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
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::find(int id1, QString station,int action){
    int i = 0;
    for(i = 0;i < ChePiaoXinXiJiHe::list_set.count();i++)
    {
        ChePiaoXinXi cp = ChePiaoXinXiJiHe::list_set[i];
        if(id1 == cp.id){
            if(action == 2){//说明是进站
                if(cp.chepiaozhuangtai==0&&cp.start_name==station){
                    ChePiaoXinXiJiHe::list_set[i].chepiaozhuangtai = 1;
                    return 1;
                }
                else return 2;
            }
            else if(action == 3)//说明是出站
            {
                if(cp.chepiaozhuangtai==1&&cp.end_name==station){
                    ChePiaoXinXiJiHe::list_set[i].chepiaozhuangtai = 2;
                    return 1;
                }
                else return 2;
            }
        }
    }
    return 0;
}

void Widget::on_pushButton_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=0;
            start.setFixedSize(480,300);//出发窗口
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=0;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}



void Widget::on_pushButton_2_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_2->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=1;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=1;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_3_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_3->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=2;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=2;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_4_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_4->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=3;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=3;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_5_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_5->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=4;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=4;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_6_clicked()//按钮信息
{
    KaiGuan::chioce = 1;
    choose.setFixedSize(480,300);
    choose.label.setText("请选择你的出发站");
    choose.show();
}



void Widget::on_pushButton_7_clicked()//按钮信息
{
    KaiGuan::chioce = 2;
    if(ui->lineEdit->text().isEmpty()){
        choose.setFixedSize(480,300);
        choose.label.setText("请先输入你的车票信息");
        choose.show();
    }
    else{
        choose.setFixedSize(480,300);
        choose.label.setText("请选择你的进入站");
        choose.show();
    }

}

void Widget::on_pushButton_8_clicked()//按钮信息
{
    KaiGuan::chioce = 3;
    if(ui->lineEdit->text().isEmpty()){
            choose.setFixedSize(480,300);
            choose.label.setText("请先输入你的车票信息");
            choose.show();
        }
        else{
            choose.setFixedSize(480,300);
            choose.label.setText("请选择你的到达站");
            choose.show();
        }
}

void Widget::on_pushButton_9_clicked()
{
    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=5;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=5;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        int id1 = ui ->lineEdit->text().toInt();
        QString str=ui->pushButton_9->text();
        int action = KaiGuan::chioce;
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int id1 = ui ->lineEdit->text().toInt();
        QString str=ui->pushButton_9->text();
        int action = KaiGuan::chioce;

        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_10_clicked()
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_10->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=6;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=6;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_11_clicked()//16
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_11->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=16;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=16;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_12_clicked()//7
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_12->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=7;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=7;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_13_clicked() //11
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_13->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=11;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=11;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_14_clicked()//8
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_14->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=8;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=8;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_15_clicked()//12
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_15->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=12;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=12;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_16_clicked()//10
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_16->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=10;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=10;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_17_clicked()//13
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_17->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=13;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=13;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}


void Widget::on_pushButton_18_clicked()//9
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_18->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=9;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=9;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_19_clicked()//18
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_19->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=18;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=18){
            KaiGuan::end=6;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_20_clicked()//14
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_20->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=14;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=14;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_21_clicked()//15
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_21->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=15;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=15;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_22_clicked()//17
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_22->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=17;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=17;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_25_clicked()//19
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_25->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=19;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=19;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_23_clicked()//20
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_23->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=20;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=20;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_26_clicked()//21
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_26->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=21;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=21;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_24_clicked()//22
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_24->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=22;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=22;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}

void Widget::on_pushButton_27_clicked()//23
{
    int id1 = ui ->lineEdit->text().toInt();
    QString str=ui->pushButton_27->text();
    int action = KaiGuan::chioce;

    if(KaiGuan::chioce == 1){
        if(KaiGuan::cf==0)
        {
            KaiGuan::start=23;
            start.setFixedSize(480,300);
            start.show();
        }
        else if(KaiGuan::cf!=0){
            KaiGuan::end=23;
            end.setFixedSize(480,300);
            end.show();
        }
    }
    else if(KaiGuan::chioce == 2){
        mass.setFixedSize(480,300);
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请进站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 1;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法进站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else if(KaiGuan::chioce == 3){
        int f = find(id1,str,action);
        if(f == 1){
            QString str = "请出站";
            QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");//数据库主机ip
            db.setUserName("root");//数据库用户名
            db.setPassword("duanyuhang518.");//数据库密码
            db.setDatabaseName("ditie");//数据库名字
            if(db.open()==false){
                QMessageBox::warning(this,"waring",db.lastError().text());
            }
            QSqlQuery query;//定义对象
            query.prepare("update chepiao set zhuangtai=:zhuangtai where id=:id");

            QVariantList idList;//生成id对象
            idList << id1;//赋值
            query.bindValue(":id",idList);

            QVariantList zhuangtaiList;
            zhuangtaiList << 2;
            query.bindValue(":zhuangtai",zhuangtaiList);

            query.execBatch();
            mass.label.setText(str);
            mass.show();
        }
        else if(f==2){
            QString str = "无法出站，请到售票处处理";
            mass.label.setText(str);
            mass.show();
        }
        else
        {
            QString str = "没有这张车票";
            mass.label.setText(str);
            mass.show();
        }
    }
    else{
        choose.label.setText("请先进行你的选择");
        choose.setFixedSize(480,300);
        choose.show();
    }
}
