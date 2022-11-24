#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "showqueue.h"
#include "widgetscreen.h"
#include <vector>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    ShowQueue mainQueue;
    class Screen{
    public:
        int winNum;
        int queueNum;
        ShowQueue* window3;
        Screen(ShowQueue *win = nullptr);
        ShowQueue * getWin();
        void setWinNum(int num);
        int getWinNum();
    };

private:
    static int winCount;
    Ui::MainWidget *ui;
    MainWidget *window1=nullptr;;
    WidgetScreen *window2=nullptr;
    std::vector<Screen>screens;

private slots:
    void on_queuing_clicked();
    void on_showQueue_clicked();
    void on_login_clicked();
    void on_pushButton_clicked();

signals:
    void closeWinToScreen(int num);

public slots:
    void openWinInfo(int num);
    void closeWinFind(int num);
    void closeNULL();
};

#endif // MAINWIDGET_H
