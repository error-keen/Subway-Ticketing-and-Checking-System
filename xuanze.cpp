#include "xuanze.h"

XuanZe::XuanZe(QWidget *parent) : QWidget(parent)
{
//    label.setParent(this);//设置标签的父窗口
//    QFont ft;//定义字体对象
//    ft.setPointSize(16);//设置字体大小为20号
//    label.setFont(ft);//设置标签的字体为ft
//    label.move(70,30);//设置标签的位置

    label.setParent(this);//设置标签的父窗口
    QFont ft;//定义字体对象
    ft.setPointSize(20);//设置字体大小为20号
    label.setFont(ft);//设置标签的字体为ft
    label.move(100,80);//设置标签的位置
    label.resize(380,60);


    button_ok.setParent(this);//设置确定按钮父窗口
    button_ok.setText("确定");//设置确定按钮文本
    button_ok.move(170,200);//设置确定按钮位置

    connect(&button_ok,&QPushButton::clicked,this,&XuanZe::button_ok_clicked);
}
void XuanZe::button_ok_clicked(){
     this->close();
}
