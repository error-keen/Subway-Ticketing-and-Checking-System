#include "chepiaoxinxijihe.h"

ChePiaoXinXiJiHe::ChePiaoXinXiJiHe()
{

}
QList<ChePiaoXinXi> ChePiaoXinXiJiHe::list_set={};
int ChePiaoXinXiJiHe::add_list(int id1,QString start_name1,QString end_name1,int money1,int chepiaozhuangtai1){
    if(list_set.count()==0){//当前集合中所有元素的个数
        id1 = 0;
        ChePiaoXinXi cp(id1,start_name1,end_name1,money1,chepiaozhuangtai1);

        list_set.append(cp);//向数组中添加新的元素
        return cp.id;
    }
    else{
        ChePiaoXinXi cp = list_set.last();
        id1 = cp.id+1;
        ChePiaoXinXi cp1(id1,start_name1,end_name1,money1,chepiaozhuangtai1);

        list_set.append(cp1);//向数组中添加新的元素
        return cp1.id;
    }
}

