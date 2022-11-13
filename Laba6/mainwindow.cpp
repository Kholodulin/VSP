#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::critical(this,"Error","Something was wrong!");
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::warning(this,"Warning","System error");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"information","qwertyuiop asdfghjkl zxcvbnm");
}

