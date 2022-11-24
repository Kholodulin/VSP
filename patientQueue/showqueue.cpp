#include "showqueue.h"
#include "ui_showqueue.h"
ShowQueue::ShowQueue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowQueue)
{
    ui->setupUi(this);
}
int ShowQueue::patID=0;
std::queue<int> ShowQueue::patientQueue;

void ShowQueue::addPatient(){
    ++patID;
    patientQueue.push(patID);
}

int ShowQueue::getID(){
    return patID;
}
int ShowQueue::getFirst(){
    return  patientQueue.front();
}
int ShowQueue::getwinNum(){
    return winNum;
}

void ShowQueue::closeEvent(QCloseEvent *e){
    if(winNum==0){
        emit closeNULLToMain();
    }else{
        emit closeWinToMain(winNum);
    }
}
void ShowQueue::on_enter_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    winNum = ui->winNum->value();

    if(login=="l" && pass=="p"){
        ui->groupBox->hide();
        emit openWinToMain(winNum);
        emit openWinToScreen(winNum);
        ui->label_2->setText(("Окно " + QString::number(winNum)));
    }
    else{
        QMessageBox::warning(this,"Error","\nwrong login or password");
    }
}
void ShowQueue::on_next_clicked()
{
    if(!patientQueue.empty()){
        emit next(getwinNum(),patientQueue.front());
        patientQueue.pop();
    }
    else QMessageBox::information(this,"Коцец очереди","Нет ожидающих пациентов");
}

ShowQueue::~ShowQueue()
{
    delete ui;
}

