#include "playingclass.h"
#include "ui_playingclass.h"
#include <QMessageBox>

PlayingClass::PlayingClass(std::string fName, bool pF, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayingClass)
{
    ui->setupUi(this);
    neuroData = fName;
    whoFirst = pF;
    whoPlay = whoFirst;
    net = new NetworkPlaying(neuroData);
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(upTime()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushOneButton()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushTwoButton()));
    upTimer.start(10);
    if(whoFirst)
        gameStep();
}

PlayingClass::~PlayingClass()
{
    delete net;
    delete ui;
}

void PlayingClass::gameStep()
{
    if(sticks > 1)
    {
        int step = net->netChose(sticks);
        sticks -= step;
        if(step == 1)
            ui->label_5->setText(ui->label_5->text()+" |");
        else if(step == 2)
            ui->label_5->setText(ui->label_5->text()+" ||");
        whoPlay = !whoPlay;
    }
    else if(sticks == 1)
    {
        sticks--;
        ui->label_5->setText(ui->label_5->text()+" |");
        whoPlay = !whoPlay;
        gameStep();
    }
    else if(sticks == 0)
    {
        if(whoPlay)
            QMessageBox::information(this, "You win!", "Сongratulations you won AI!");
        else
            QMessageBox::information(this, "You lose!", "Sorry but you lose, try more!");
        sticks = 20;
        ui->label_4->setText("");
        ui->label_5->setText("");
        ui->pushButton_2->setEnabled(true);
        whoPlay = whoFirst;
        if(whoFirst)
            gameStep();
    }
    if(sticks == 1)
        ui->pushButton_2->setEnabled(false);
    else if(sticks == 0)
        gameStep();
}

void PlayingClass::upTime()
{
    ui->label->setText("Count of sticks: "+QString::number(sticks));
    update();
}

void PlayingClass::pushOneButton()
{
    sticks--;
    ui->label_4->setText(ui->label_4->text()+" |");
    whoPlay = !whoPlay;
    gameStep();
}

void PlayingClass::pushTwoButton()
{
    sticks -= 2;
    ui->label_4->setText(ui->label_4->text()+" ||");
    whoPlay = !whoPlay;
    gameStep();
}
