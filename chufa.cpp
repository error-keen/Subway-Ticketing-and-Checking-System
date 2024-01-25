#include "chufa.h"
#include <QFont>
ChuFa::ChuFa(QWidget *parent) : QWidget(parent)
{
    label.setParent(this);//设置标签的父窗口
    label.setText("您确定从此站出发?");//设置标签的文本
    QFont ft;//定义字体对象
    ft.setPointSize(20);//设置字体大小为20号
    label.setFont(ft);//设置标签的字体为ft
    label.move(80,80);//设置标签的位置
    label.resize(380,60);

    button_ok.setParent(this);//设置确定按钮父窗口
    button_ok.setText("确定");//设置确定按钮文本
    button_ok.move(80,200);//设置确定按钮位置
    button_can.setParent(this);
    button_can.setText("取消");
    button_can.move(280,200);
    connect(&button_can,&QPushButton::clicked,this,&ChuFa::button_can_clicked);
    connect(&button_ok,&QPushButton::clicked,this,&ChuFa::button_ok_clicked);

}
void ChuFa::button_can_clicked(){
    KaiGuan::cf=0;
    KaiGuan::dd=0;
    this->close();

}
void ChuFa::button_ok_clicked(){
    KaiGuan::cf=1;
    KaiGuan::dd=0;
    this->close();
}
