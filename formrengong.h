#ifndef FORMRENGONG_H
#define FORMRENGONG_H

#include <QWidget>
#include <QSqlTableModel>
//数据模型
//<QSqlTableModel>数据模型里面放数据
namespace Ui {
class FormRenGong;
}

class FormRenGong : public QWidget
{
    Q_OBJECT

public:
    explicit FormRenGong(QWidget *parent = 0);
    ~FormRenGong();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormRenGong *ui;
    QSqlTableModel *model;
};

#endif // FORMRENGONG_H
