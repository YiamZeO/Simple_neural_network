#ifndef TRAINCLASS_H
#define TRAINCLASS_H

#include <QMainWindow>
#include "networktraining.h"
#include <QThread>
#include <QTimer>

namespace Ui {
class TrainClass;
}

class TrainClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrainClass(QWidget *parent = nullptr);
    ~TrainClass();

private slots:
    void pushCreateButton();
    void pushChooseButton1();
    void pushChooseButton2();
    void pushStartButton();
    void upTime();

private:
    Ui::TrainClass *ui;
    std::vector<std::string> neuroData;
    NetworkTraining training;
    bool isTraining = false;
    QThread *trainingTh = nullptr;
    QTimer upTimer;
};

#endif // TRAINCLASS_H
