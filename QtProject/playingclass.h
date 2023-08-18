#ifndef PLAYINGCLASS_H
#define PLAYINGCLASS_H

#include <QMainWindow>
#include <string>
#include "networkplaying.h"
#include <QTimer>

namespace Ui {
class PlayingClass;
}

class PlayingClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayingClass(std::string fName, bool pF, QWidget *parent = nullptr);
    ~PlayingClass();
    void gameStep();

public slots:
    void upTime();
    void pushOneButton();
    void pushTwoButton();

private:
    Ui::PlayingClass *ui;
    std::string neuroData;
    int sticks = 20;
    NetworkPlaying *net;
    QTimer upTimer;
    bool whoPlay, whoFirst;
};

#endif // PLAYINGCLASS_H
