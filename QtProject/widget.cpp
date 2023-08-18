#include "widget.h"
#include "ui_widget.h"
#include "trainclass.h"
#include "gamesett.h"
#include "aboutclass.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushTrainButton()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(pushPlayButton()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushAboutButton()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushTrainButton()
{
    TrainClass* t = new TrainClass(this);
    t->show();
}

void Widget::pushPlayButton()
{
    GameSett* g = new GameSett(this);
    g->show();
}

void Widget::pushAboutButton()
{
    AboutClass* a = new AboutClass(this);
    a->show();
}

