#ifndef KAIGUAN_H
#define KAIGUAN_H
#include <QString>

class KaiGuan
{
public:
    KaiGuan();
    static int cf;//记录出发状态,cf=0表示没有出发，cf=1表示已经出发
    static int dd;//记录到达状态,dd=0表示没有到达，dd=1表示已经到达
    static int start;//记录出发站的下标
    static int end;//记录到达站下标
    static QString name[24];
    static int new_id;

    static int chioce;
};

#endif // KAIGUAN_H
