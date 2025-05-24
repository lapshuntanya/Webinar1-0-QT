#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    randNumbers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randNumbers()
{
    number1 = rand()%9 + 1;
    number2 = rand()%9 + 1;
    ui->labelRand->setText(QString().setNum(number1) + " x " + QString().setNum(number2) +
                           " = ");
}

void MainWindow::on_pushButton_clicked()
{
    float user = ui->doubleSpinBoxUser->value();

    if(user == number1 * number2){
        QMessageBox::about(this, "Перевірка", "МОЛОДЕЦЬ!!! Все вірно!!!");
    }else{
        QMessageBox::critical(this, "Перевірка", "Не вірно =( Спробуй ще раз!");
    }

    randNumbers();
}

