#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change(int n){
    money += n;
    ui->lcdNumber->display(money);

    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    if(money >= 100){
        ui->pushButton_5->setEnabled(true);
        if(money >= 150){
            ui->pushButton_6->setEnabled(true);
            if(money >= 200){
                ui->pushButton_7->setEnabled(true);
            }
        }
    }
}

void Widget::on_pushButton_clicked()
{
    change(10);
}


void Widget::on_pushButton_2_clicked()
{
    change(50);
}


void Widget::on_pushButton_3_clicked()
{
    change(100);
}


void Widget::on_pushButton_4_clicked()
{
    change(500);
}


void Widget::on_pushButton_5_clicked()
{
    change(-100);
}


void Widget::on_pushButton_6_clicked()
{
    change(-150);
}


void Widget::on_pushButton_7_clicked()
{
    change(-200);
}


void Widget::on_pushButton_8_clicked()
{
    QMessageBox m;
    char text[100] = {0, };
    sprintf(text, "500 : %d, 100 : %d, 50 : %d, 10 : %d", money/500, (money%500)/100,(money%100)/50, (money%50)/10);
    m.setText(text);
    m.exec();
    change(-money);
}

