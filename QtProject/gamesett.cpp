#include "gamesett.h"
#include "ui_gamesett.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include "playingclass.h"

GameSett::GameSett(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSett)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushOpenButton()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushStartButton()));
}

GameSett::~GameSett()
{
    delete ui;
}

void GameSett::pushOpenButton()
{
    QString name = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/",
                                                    tr("(*.neuro)"));
    neuroData = name.toStdString();
    std::fstream inData(neuroData, std::ios_base::in);
    if(inData.is_open())
    {
        inData.close();
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
        QMessageBox::critical(this, "File not open", "File not open. Check file name or path");
    }
}

void GameSett::pushStartButton()
{
    PlayingClass *p = new PlayingClass(neuroData, ui->radioButton->isChecked() ? false : true, parentWidget());
    p->show();
    close();
}
