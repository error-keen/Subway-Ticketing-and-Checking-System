#include "showtic.h"

ShowTic::ShowTic(QWidget *parent) : QWidget(parent)
{
//    imformation.setParent(this);//设置标签的父窗口
//    QFont ft;//定义字体对象
//    ft.setPointSize(16);//设置字体大小为20号
//    imformation.setFont(ft);//设置标签的字体为ft
//    imformation.move(20,80);//设置标签的位置
//    imformation.resize(700,60);

    imformation.setParent(this);//设置标签的父窗口
    QFont ft;//定义字体对象
    ft.setPointSize(20);//设置字体大小为20号
    imformation.setFont(ft);//设置标签的字体为ft
    imformation.move(80,80);//设置标签的位置
    imformation.resize(760,60);
}
