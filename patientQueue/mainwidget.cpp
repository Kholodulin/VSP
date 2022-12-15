#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    this->setMaximumHeight(85);
    this->setMaximumWidth(380);
    ui->label_2->setText("<img src=\":/icon/icon/hospital.png\">");
}
int MainWidget::winCount=0;

MainWidget::Screen::Screen(ShowQueue *win)
{
    window3 = win;
    window3->show();
}

ShowQueue *MainWidget::Screen::getWin()
{
    return window3;
}

void MainWidget::Screen::setWinNum(int num)
{
    winNum=num;
}

int MainWidget::Screen::getWinNum()
{
    return winNum;
}

void MainWidget::on_queuing_clicked()
{
    window1 = new MainWidget();
    window1->show();
    window1->ui->groupBox->show();
    window1->ui->groupBox_2->hide();
    window1->setMinimumHeight(370);
    window1->setMinimumWidth(500);
    window1->setMaximumHeight(1000000);
    window1->setMaximumWidth(1000000);
}
void MainWidget::closeEvent(QCloseEvent *e){
    delete window1;
}

void MainWidget::on_showQueue_clicked()
{
    ui->showQueue->setDisabled(true);
    window2 = new WidgetScreen;
    window2->show();
}

void MainWidget::on_login_clicked()
{
    if(window2!=nullptr){

        for(int i=0;i< 3; ++i){
            if(i+1>(screens.size())){

                Screen screen(new ShowQueue);
                screens.push_back(screen);
                connect(screens[i].getWin(),&ShowQueue::openWinToMain,this,&MainWidget::openWinInfo);
                connect(screens[i].getWin(),&ShowQueue::openWinToScreen,window2,&WidgetScreen::openWin);
                connect(screens[i].getWin(),&ShowQueue::next,window2,&WidgetScreen::next);
                connect(screens[i].getWin(),&ShowQueue::closeWinToMain,this,&MainWidget::closeWinFind);
                connect(this,&MainWidget::closeWinToScreen,window2,&WidgetScreen::closeWin);
                connect(screens[i].getWin(),&ShowQueue::closeNULLToMain,this,&MainWidget::closeNULL);
                connect(window2,&WidgetScreen::closeScreen,this,&MainWidget::closeScr);
                break;
            }else
                if(i==2){QMessageBox::information(this,"Меного включеных окон","Разрешено не больше 3-х работающих окон");}
        }
    }
    else {
        QMessageBox::warning(this,"ошибка","Необходимо сначало\nвключить экран");
    }
}

void MainWidget::closeScr(){
    delete window2;
}

void MainWidget::on_pushButton_clicked()
{
    mainQueue.addPatient();
    ui->queueNum->setText("Общее число пациентов сегодня: " + QString::number(mainQueue.getID()));
}

void MainWidget::openWinInfo(int num)
{
    if(winCount<3){
        screens[winCount].winNum=num;
        ++winCount;
    }
}

void MainWidget::closeWinFind(int num)
{
    std::vector<Screen>::iterator it = screens.begin();
    for(int i=0; i<screens.size();i++){
        if(screens[i].winNum==num){
            emit closeWinToScreen(i);
            delete screens[i].window3;
            screens.erase(it);
            break;
        }
        it++;
    }
    --winCount;
}

void MainWidget::closeNULL(){
    std::vector<Screen>::iterator it = screens.begin();
    for(int i=0; i<screens.size();i++){
        if(screens[i].winNum<0){
            screens.erase(it);
            break;
        }
        it++;
    }
}
MainWidget::~MainWidget()
{
    delete ui;
}


