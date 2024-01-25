#ifndef CHEPIAOXINXI_H
#define CHEPIAOXINXI_H
#include <QString>

class ChePiaoXinXi
{
public:
    int id;//车票id
    QString start_name;//车票出发站名称
    QString end_name;//车票到达站名称
    int money;//车票价格
    int chepiaozhuangtai;//车票状态，0表示新购的车票，1表示已经进站，2表示已经出站
    ChePiaoXinXi();
    ChePiaoXinXi(int id1,QString start_name1,QString end_name1,int money1,int chepiaozhuangtai1);
};

#endif // CHEPIAOXINXI_H
