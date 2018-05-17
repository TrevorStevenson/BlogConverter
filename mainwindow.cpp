#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTextStream>
#include <QFile>

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
    QString templateName = ui->lineEdit->text();

    QFile file(templateName.toStdString());
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << post.toStdString() << "\n";
        file.close();
    }
}
