#include "aboutclass.h"
#include "ui_aboutclass.h"

AboutClass::AboutClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutClass)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushOkButton()));
}

AboutClass::~AboutClass()
{
    delete ui;
}

void AboutClass::pushOkButton()
{
    close();
}
