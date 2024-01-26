## 1.项目介绍

该系统包括购票，检票，查询车票信息，修改购票信息四大基础功能。

- 该系统使用彩色线条展现地铁的5条线路；

- 实现“购检“一体化窗口；

- 一人购买多张票，实现购票便捷化设计；

- 设置窗口可查询、修改车票起始信息，大大方便乘客出行。

  ![image-20240125214618866](https://github.com/error-keen/data-structure/blob/main/img/subway_1.png)

## 2.项目环境配置

此项目需要安装MySQL及QT连接MySQL驱动编译，具体操作参考一下链接：[【QTMysql】MySQL安装及QT连接MySQL驱动编译操作步骤 - CoutCodes - 博客园 (cnblogs.com)](https://www.cnblogs.com/CoutCodes/p/13204023.html)

## 3.运行测试

### 3.1 点击购票，会弹出一个窗口，请选择出发站。

![subway_3](https://github.com/error-keen/data-structure/blob/main/img/subway_3.png)

### 3.2 在地铁的地图上选择一个出发站和目的站。

![subway_4](https://github.com/error-keen/data-structure/blob/main/img/subway_4.png)

### 3.3 输入购买车票数

![subway_5](https://github.com/error-keen/data-structure/blob/main/img/subway_5.png)

### 3.4 生成购票信息，并自动传到MySQL上，刷新表即可查看购票信息

![subway_6](https://github.com/error-keen/data-structure/blob/main/img/subway_6.png)

![subway_7](https://github.com/error-keen/data-structure/blob/main/img/subway_7.png)

### 3.5 然后就可以选择进站和出站，MySQL上车票的状态会跟着变化。

### 3.6 最后便是查表，可以在此表进行增删改查，并自动同步数据库。

![subway_2](https://github.com/error-keen/data-structure/blob/main/img/subway_2.png)

## 4.总结

通过这个项目，让我更加熟悉了QT的使用，最重要的是连接和t同步数据库，进行增删改查，通过这些功能的实现，让我对数据库的实际运行也更加了解和熟练。
