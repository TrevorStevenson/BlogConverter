#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_templateButton_clicked()
{
    QString post = ui->plainTextEdit->toPlainText();
    std::cout << post.toStdString() << std::endl;
}
