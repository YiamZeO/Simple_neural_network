#ifndef GAMESETT_H
#define GAMESETT_H

#include <QMainWindow>
#include <string>

namespace Ui {
class GameSett;
}

class GameSett : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSett(QWidget *parent = nullptr);
    ~GameSett();

private slots:
    void pushOpenButton();
    void pushStartButton();

private:
    Ui::GameSett *ui;
    std::string neuroData;
};

#endif // GAMESETT_H
