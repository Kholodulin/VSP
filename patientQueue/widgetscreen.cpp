#include "widgetscreen.h"
#include "ui_widgetscreen.h"

WidgetScreen::WidgetScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetScreen)
{
    ui->setupUi(this);
    ui->win1->hide();
    ui->talon1->hide();
    ui->win2->hide();
    ui->talon2->hide();
    ui->win3->hide();
    ui->talon3->hide();
}

void WidgetScreen::openWin(int num)
{
    for(int i=0;i<3;i++){
        if(winNum[i] == 0){
            switch(i){
            case 0:
                ui->win1->show();
                ui->talon1->show();
                ui->win1->setText("Окно № " + QString::number(num));
                winNum[i]=num;
                break;
            case 1:
                ui->win2->show();
                ui->talon2->show();
                ui->win2->setText("Окно № " + QString::number(num));
                winNum[i]=num;
                break;
            case 2:
                ui->win3->show();
                ui->talon3->show();
                ui->win3->setText("Окно № " + QString::number(num));
                winNum[i]=num;
                break;

            }
            break;
        }
    }
}

void WidgetScreen::next(int numWin, int numQueue)
{
    for(int i=0;i<3;i++){
        if(winNum[i] == numWin){
            switch(i){
            case 0:
                ui->talon1->setText("Талон\n\n" + QString::number(numQueue));
                break;
            case 1:
               ui->talon2->setText("Талон\n\n" + QString::number(numQueue));
                break;
            case 2:
                ui->talon3->setText("Талон\n\n" + QString::number(numQueue));
                break;
            }
            break;
        }
    }
}
void WidgetScreen::closeWin(int num)
{
    winNum[num]=0;
    switch(num){
    case 0:
        ui->win1->hide();
        ui->talon1->hide();
        ui->talon1->setText("");
        break;
    case 1:
        ui->win2->hide();
        ui->talon2->hide();
        ui->talon2->setText("");
        break;
    case 2:
        ui->win3->hide();
        ui->talon3->hide();
        ui->talon3->setText("");
        break;
    }
}
WidgetScreen::~WidgetScreen()
{

    delete ui;
}


