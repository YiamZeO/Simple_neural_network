#include "trainclass.h"
#include "ui_trainclass.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>

TrainClass::TrainClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrainClass)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushCreateButton()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushChooseButton1()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(pushStartButton()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(pushChooseButton2()));
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(upTime()));
    upTimer.start(10);
}

TrainClass::~TrainClass()
{
    delete ui;
}

void TrainClass::pushCreateButton()
{
    neuroData.clear();
    neuroData.push_back(ui->lineEdit->text().toStdString());
    if(neuroData[0].size())
    {
        neuroData[0].append(".neuro");
        std::fstream inData(neuroData[0], std::ios_base::out);
        inData << "InputParameters" << std::endl << std::to_string(20) << std::endl;
        inData << "Neurons" << std::endl << std::to_string(2) << std::endl;
        inData << "Weights" << std::endl;
        for(int i = 0; i < 2; i++)
        {
            inData << std::to_string(0.5);
            for(int j = 1; j < 20; j++)
            {
                inData << " " << std::to_string(0.5);
            }
            inData << std::endl;
        }
        inData.close();
        ui->pushButton_4->setEnabled(true);
    }
    else
    {
        ui->pushButton_4->setEnabled(false);
        QMessageBox::critical(this, "File not created", "File not created. Check file name or path");
        neuroData.pop_back();
    }
}

void TrainClass::pushChooseButton2()
{
    QString name = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/",
                                                    tr("(*.neuro)"));
    neuroData.push_back(name.toStdString());
    std::fstream inData(neuroData[1], std::ios_base::in);
    if(inData.is_open())
    {
        inData.close();
        ui->pushButton_3->setEnabled(true);
        training.loadData(neuroData);
    }
    else
    {
        ui->pushButton_3->setEnabled(false);
        QMessageBox::critical(this, "File not open", "File not open. Check file name or path");
        neuroData.pop_back();
    }
}

void TrainClass::pushChooseButton1()
{
    neuroData.clear();
    QString name = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/",
                                                    tr("(*.neuro)"));
    neuroData.push_back(name.toStdString());
    std::fstream inData(neuroData[0], std::ios_base::in);
    if(inData.is_open())
    {
        inData.close();
        ui->pushButton_4->setEnabled(true);
    }
    else
    {
        ui->pushButton_4->setEnabled(false);
        QMessageBox::critical(this, "File not open", "File not open. Check file name or path");
        neuroData.pop_back();
    }
}

void TrainClass::pushStartButton()
{
    if(ui->pushButton_3->text() == "Start")
    {
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        isTraining = true;
        trainingTh = QThread::create(std::bind(&NetworkTraining::training, &training, &isTraining));
        trainingTh->start();
        ui->pushButton_3->setText("Stop");
    }
    else
    {
        isTraining = false;
        trainingTh->wait();
        trainingTh->deleteLater();
        trainingTh = nullptr;
        training.unloadData();
        ui->lineEdit->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setText("Start");
        ui->pushButton_3->setEnabled(false);
    }
}

void TrainClass::upTime()
{
    std::vector<int> stat = training.getStats();
    ui->progressBar->setValue((int)((double)stat[0]/(double)stat[1]*100));
    ui->label_10->setText(QString::number(stat[1]));
    ui->label_11->setText(QString::number(stat[0]));
    update();
}
