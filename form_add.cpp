#include "form_add.h"
#include "ui_form_add.h"

Form_Add::Form_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Add)
{
    ui->setupUi(this);
}

Form_Add::~Form_Add()
{
    delete ui;
}

void Form_Add::on_pushButton_2_clicked()
{
    emit Hide_Add();
}

void Form_Add::on_pushButton_clicked()
{
    Roster Data;
    Data.getU(ui->lineEdit->text());
    Data.getN(ui->lineEdit_2->text());
    Data.getA(ui->lineEdit_3->text());
    Data.getT(ui->lineEdit_4->text().toInt());
    emit Add(Data);
    emit Hide_Add();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}
