#ifndef CHEPIAOXINXIJIHE_H
#define CHEPIAOXINXIJIHE_H
#include <QList>
#include <QString>
#include "chepiaoxinxi.h"

class ChePiaoXinXiJiHe
{
public:
    static QList<ChePiaoXinXi> list_set;
    ChePiaoXinXiJiHe();

    static int add_list(int id1,QString start_name1,QString end_name1,int money1,int chepiaozhuangtai1);
};

#endif // CHEPIAOXINXIJIHE_H
