#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    connect(this->ui->btn_0, SIGNAL(clicked(bool)), this,  SLOT(getBtn0()));
    connect(this->ui->btn_1, SIGNAL(clicked(bool)), this,  SLOT(getBtn1()));
    connect(this->ui->btn_2, SIGNAL(clicked(bool)), this,  SLOT(getBtn2()));
    this->mode = new model;
    this->tmp = "";
}

calculator::~calculator()
{
    delete ui;
}

void calculator::getBtn0() {
    if (this->tmp != "") {
        this->tmp += this->ui->btn_0->text();
        this->ui->label->setText(this->tmp);
    }
}

void calculator::getBtn1() {
    this->tmp += this->ui->btn_1->text();
    this->ui->label->setText(this->tmp);
}

void calculator::getBtn2() {
    this->tmp += this->ui->btn_2->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_3_clicked()
{
    this->tmp += this->ui->btn_3->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_4_clicked()
{
    this->tmp += this->ui->btn_4->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_5_clicked()
{
    this->tmp += this->ui->btn_5->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_6_clicked()
{
    this->tmp += this->ui->btn_6->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_7_clicked()
{
    this->tmp += this->ui->btn_7->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_8_clicked()
{
    this->tmp += this->ui->btn_8->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_9_clicked()
{
    this->tmp += this->ui->btn_9->text();
    this->ui->label->setText(this->tmp);
}

void calculator::on_btn_add_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setNum1(num);
    this->tmp = "";
    QString opt = this->ui->btn_add->text();
    this->mode->setFlag(opt);
}

void calculator::on_btn_sub_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setNum1(num);
    this->tmp = "";
    QString opt = this->ui->btn_sub->text();
    this->mode->setFlag(opt);
}

void calculator::on_btn_mul_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setNum1(num);
    this->tmp = "";
    QString opt = this->ui->btn_mul->text();
    this->mode->setFlag(opt);
}

void calculator::on_btn_div_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setNum1(num);
    this->tmp = "";
    QString opt = this->ui->btn_div->text();
    this->mode->setFlag(opt);
}

void calculator::on_btn_eql_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setNum2(num);
    QString res = this->mode->doResult();
    this->ui->label->setText(res);
    this->tmp = "";
}


void calculator::on_btn_ac_clicked()
{
    this->tmp = "";
    this->mode->setFlag("");
    this->ui->label->setText("0");
}
