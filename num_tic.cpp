#include "num_tic.h"
#include <QTimer>
Num_Tic::Num_Tic(QWidget *parent) : QWidget(parent)
{
//    label.setParent(this);//设置标签的父窗口
//    label.setText("车票数:");//设置标签的文本
//    QFont ft;//定义字体对象
//    ft.setPointSize(16);//设置字体大小为20号
//    label.setFont(ft);//设置标签的字体为ft
//    label.move(80,80);//设置标签的位置
//    label.resize(480,60);


    label.setParent(this);//设置标签的父窗口
    label.setText("车票数:");//设置标签的文本
    QFont ft;//定义字体对象
    ft.setPointSize(16);//设置字体大小为20号
    label.setFont(ft);//设置标签的字体为ft
    label.move(80,80);//设置标签的位置
    label.resize(380,60);

    num.setParent(this);
    num.move(180,80);
    num.resize(70,60);
    num.setFont(ft);

    button_ok.setParent(this);//设置确定按钮父窗口
    button_ok.setText("确定");//设置确定按钮文本
    button_ok.move(80,200);//设置确定按钮位置
    button_can.setParent(this);
    button_can.setText("取消");
    button_can.move(240,200);
    connect(&button_can,&QPushButton::clicked,this,&Num_Tic::button_can_clicked);
    connect(&button_ok,&QPushButton::clicked,this,&Num_Tic::button_ok_clicked);
}

void Num_Tic::button_can_clicked(){
    KaiGuan::cf=0;
    KaiGuan::dd=0;
    KaiGuan::chioce = 0;

    this->close();
}

void Num_Tic::button_ok_clicked(){
    QString s = num.text();
    int n = s.toInt();

    int i = 0;
    for(i = 0;i < n;i++){
        int id1=0;
        QString start_name1=KaiGuan::name[KaiGuan::start];
        QString end_name1=KaiGuan::name[KaiGuan::end];
        int moeny1 = 2;
        int chepiaozhuangtai1 = 0;
        KaiGuan::new_id= ChePiaoXinXiJiHe::add_list(id1,start_name1,end_name1,moeny1,chepiaozhuangtai1);
        ChePiaoXinXi cp = ChePiaoXinXiJiHe::list_set.last();
        QString str = QString("车票id:%1 出发站:%2 -> 到达站:%3").arg(cp.id).arg(cp.start_name).arg(cp.end_name);
        tic_info.imformation.setText(str);
        tic_info.setFixedSize(960,300);
        tic_info.show();


        QDate date=QDate::currentDate();
        QString str2=date.toString("yyyy-MM-dd");
        QTime time=QTime::currentTime();
        QString str1=time.toString("hh:mm:ss");
        qDebug()<<QSqlDatabase::drivers();
        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");//数据库主机ip
        db.setUserName("root");//数据库用户名
        db.setPassword("duanyuhang518.");//数据库密码
        db.setDatabaseName("ditie");//数据库名字
        if(db.open()==false){
            QMessageBox::warning(this,"waring",db.lastError().text());
        }
        QSqlQuery query;
        query.prepare("insert into chepiao (id,date,time,start_name,end_name,money,zhuangtai) values (:id,:date,:time,:start_name,:end_name,:money,:zhuangtai)");
        QVariantList idList;
        idList << ChePiaoXinXiJiHe::list_set.last().id;
        query.bindValue(":id",idList);
        //日期
        QVariantList dateList;
        dateList << str2;
        query.bindValue(":date",dateList);
        //时间
        QVariantList timeList;
        timeList << str1;
        query.bindValue(":time",timeList);
        //出发地
        QVariantList start_name;
        start_name << ChePiaoXinXiJiHe::list_set.last().start_name;
        query.bindValue(":start_name",start_name);
        //到达地
        QVariantList end_name;
        end_name << ChePiaoXinXiJiHe::list_set.last().end_name;
        query.bindValue(":end_name",end_name);
        //票价
        QVariantList money;
        money << ChePiaoXinXiJiHe::list_set.last().money;
        query.bindValue(":money",money);
        //状态
        QVariantList zhuangtai;
        zhuangtai << ChePiaoXinXiJiHe::list_set.last().chepiaozhuangtai;
        query.bindValue(":zhuangtai",zhuangtai);
        query.execBatch();
        this->close();

//        int id1 = 0;
//        KaiGuan::new_id= ChePiaoXinXiJiHe::add_list(id1,start_name1,end_name1,moeny1,chepiaozhuangtai1);
//        ChePiaoXinXi cp = ChePiaoXinXiJiHe::list_set.last();
//        QString str = QString("车票id:%1 出发站:%2 -> 到达站:%3").arg(cp.id).arg(cp.start_name).arg(cp.end_name);
//        tic_info.imformation.setText(str);
//        tic_info.setFixedSize(700,200);
//        QTimer* timer = new QTimer(this);
//        timer->start(15000);//时间1.5秒
//        timer->setSingleShot(true);
//        tic_info.setFixedSize(700,200);
//        tic_info.show();
    }

//        int id1=0;
//        QString start_name1=KaiGuan::name[KaiGuan::start];
//        QString end_name1=KaiGuan::name[KaiGuan::end];
//        int moeny1 = 2;
//        int chepiaozhuangtai1 = 0;
//        KaiGuan::new_id= ChePiaoXinXiJiHe::add_list(id1,start_name1,end_name1,moeny1,chepiaozhuangtai1);
//        ChePiaoXinXi cp = ChePiaoXinXiJiHe::list_set.last();
//        QString str = QString("车票id:%1 出发站:%2 -> 到达站:%3").arg(cp.id).arg(cp.start_name).arg(cp.end_name);
//        tic_info.imformation.setText(str);
//        tic_info.setFixedSize(700,200);
//        tic_info.show();


//        QDate date=QDate::currentDate();
//        QString str2=date.toString("yyyy-MM-dd");
//        QTime time=QTime::currentTime();
//        QString str1=time.toString("hh:mm:ss");
//        qDebug()<<QSqlDatabase::drivers();
//        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
//        db.setHostName("127.0.0.1");//数据库主机ip
//        db.setUserName("root");//数据库用户名
//        db.setPassword("duanyuhang518.");//数据库密码
//        db.setDatabaseName("ditie");//数据库名字
//        if(db.open()==false){
//            QMessageBox::warning(this,"waring",db.lastError().text());
//        }
//        QSqlQuery query;
//        query.prepare("insert into chepiao (id,date,time,start_name,end_name,money,zhuangtai) values (:id,:date,:time,:start_name,:end_name,:money,:zhuangtai)");
//        QVariantList idList;
//        idList << ChePiaoXinXiJiHe::list_set.last().id;
//        query.bindValue(":id",idList);
//        //日期
//        QVariantList dateList;
//        dateList << str2;
//        query.bindValue(":date",dateList);
//        //时间
//        QVariantList timeList;
//        timeList << str1;
//        query.bindValue(":time",timeList);
//        //出发地
//        QVariantList start_name;
//        start_name << ChePiaoXinXiJiHe::list_set.last().start_name;
//        query.bindValue(":start_name",start_name);
//        //到达地
//        QVariantList end_name;
//        end_name << ChePiaoXinXiJiHe::list_set.last().end_name;
//        query.bindValue(":end_name",end_name);
//        //票价
//        QVariantList money;
//        money << ChePiaoXinXiJiHe::list_set.last().money;
//        query.bindValue(":money",money);
//        //状态
//        QVariantList zhuangtai;
//        zhuangtai << ChePiaoXinXiJiHe::list_set.last().chepiaozhuangtai;
//        query.bindValue(":zhuangtai",zhuangtai);
//        query.execBatch();


}
