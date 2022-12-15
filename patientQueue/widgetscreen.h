#ifndef WIDGETSCREEN_H
#define WIDGETSCREEN_H
#include <QWidget>
#include "showqueue.h"

namespace Ui {
class WidgetScreen;
}

class WidgetScreen : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetScreen(QWidget *parent = nullptr);
    int winNum[3]{0,0,0};
    void closeEvent(QCloseEvent *e)override;
    ~WidgetScreen();

private:
    ShowQueue *mainQueue;
    Ui::WidgetScreen *ui;

public slots:
    void openWin(int num);
    void next(int numWin, int numQueue);
    void closeWin(int num);
signals:
    void closeScreen();
};
#endif
