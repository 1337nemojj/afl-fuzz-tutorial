#include "mainwindow.h"
#include "build/ui_mainwindow.h"
#include <iostream>
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
	    QString text = ui->lineEdit->text();
	    if (text == "100"){int* ptr =nullptr;int value = *ptr; std::cout << *ptr << std::endl;}
	        ui->label->setText(text);
}
