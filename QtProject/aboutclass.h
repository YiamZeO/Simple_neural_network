#ifndef ABOUTCLASS_H
#define ABOUTCLASS_H

#include <QMainWindow>

namespace Ui {
class AboutClass;
}

class AboutClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutClass(QWidget *parent = nullptr);
    ~AboutClass();

public slots:
    void pushOkButton();

private:
    Ui::AboutClass *ui;
};

#endif // ABOUTCLASS_H
