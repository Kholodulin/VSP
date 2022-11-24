#ifndef SHOWQUEUE_H
#define SHOWQUEUE_H

#include <QWidget>
#include <queue>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class ShowQueue;
}

class ShowQueue : public QWidget
{
    Q_OBJECT

public:
    explicit ShowQueue(QWidget *parent = nullptr);
    int getID();
    int getFirst();
    int getwinNum();
    void addPatient();
    void closeEvent(QCloseEvent *e)override;
    ~ShowQueue();

private:
    static int patID;
    int winNum=0;
    static std::queue<int> patientQueue;
    Ui::ShowQueue *ui;

private slots:
    void on_enter_clicked();
    void on_next_clicked();

signals:
    void openWinToMain(int num);
    void openWinToScreen(int num);
    void next(int numWin, int numQueue);
    void closeWinToMain(int num);
    void closeNULLToMain();
};
#endif
