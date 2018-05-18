#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QRegExp>

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
    QString post = ui->blog->toPlainText();
    QString templateName = ui->fileNameInput->text();

    QFile file(templateName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << post;
        file.close();
    }
}

void MainWindow::on_convertButton_clicked()
{
    QString post = ui->blog->toPlainText();
    post.replace("\n", "</p>\n\t\t\t<p>");
    QString blogPost = "<p>" + post +"</p>";
    QString templateName = ui->fileNameInput->text();
    QString date = ui->dataInput->text();
    QString title = ui->titleInput->text();
    QString preview = ui->preview->toPlainText();
    QString htmlTitle = ui->htmlTitle->text();

    QFile file(templateName);

    if (file.open(QIODevice::ReadOnly)) {
        QFile outFile("out.txt");
        if (outFile.open(QIODevice::WriteOnly)) {
            QTextStream outStream(&outFile);
            QTextStream stream(&file);
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                if (line.contains("*1*")) {
                   line.replace("*1*", title);
                }
                else if (line.contains("*2*")) {
                    line.replace("*2*", preview);
                }
                else if (line.contains("*3*")) {
                    line.replace("*3*", date);
                }
                else if (line.contains("*4*")) {
                    line.replace("*4*", blogPost);
                }
                else if (line.contains("*5*")) {
                    line.replace("*5*", htmlTitle);
                }
                outStream << line << "\n";
            }
            outFile.close();
        }
        file.close();
    }
}
