#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
#include <QPixmap>
#include <windows.h>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->humor->setText(QString::number(fun));
    ui->kalorie->setText(QString::number(calories));
    ui->energia->setText(QString::number(energy));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()  //zamknij
{
    qApp->exit();
}
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
void MainWindow::on_baw_sie_clicked()
{
        obrazZabawa();

        fun=fun+10;
        calories=calories-5;
        energy=energy-5;

        if (calories>100) calories=100;
        if(fun>100) fun=100;
        if(energy>100) energy=100;

        if (calories<0) calories=0;
        if(fun<0) fun=0;
        if(energy<0) energy=0;

        ui->humor->setText(QString::number(fun));
        ui->kalorie->setText(QString::number(calories));
        ui->energia->setText(QString::number(energy));

       postawaPieska();
}


void MainWindow::on_spij_clicked()
{
    obrazSpi();

    energy=energy+10;
    calories=calories-5;



    if (calories>100) calories=100;
    if(fun>100) fun=100;
    if(energy>100) energy=100;

    if (calories<0) calories=0;
    if(fun<0) fun=0;
    if(energy<0) energy=0;

    ui->kalorie->setText(QString::number(calories));
    ui->energia->setText(QString::number(energy));
    ui->humor->setText(QString::number(fun));

    postawaPieska();
}

void MainWindow::on_jedz_clicked()
{

    obrazJe();
    calories=calories+10;
    fun=fun-10;

    if (calories>100) calories=100;
    if(fun>100) fun=100;
    if(energy>100) energy=100;

    if (calories<0) calories=0;
    if(fun<0) fun=0;
    if(energy<0) energy=0;

    ui->kalorie->setText(QString::number(calories));
    ui->energia->setText(QString::number(energy));
    ui->humor->setText(QString::number(fun));

    postawaPieska();
}



void MainWindow::postawaPieska()
{
      if( energy > 69 && calories > 69 && fun > 69 )
      {
          //wyswietlenie szczesliwy.png + komunikat udalo sie
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/szczesliwy.png"));
          ui->wynik->setText(QString("Brawo! Nowa gra za 5sek."));
          delay(5000);
          ui->wynik->setText(QString(" "));
          fun=50;
          calories=50;
          energy=50;
          ui->kalorie->setText(QString::number(calories));
          ui->energia->setText(QString::number(energy));
          ui->humor->setText(QString::number(fun));

          postawaPieska();

      }
      else if( fun > 29 && fun < 45 && calories >= 45 && calories < 70 && energy >= 45 && energy< 70 )
      {
          //wyswietlenie tako.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/tako.png"));
      }
      else if( fun >= 45 && fun < 70 && calories > 29 && calories < 45 && energy >= 45 && energy < 70 )
      {
          //wyswietlenie tako.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/tako.png"));
      }
      else if( fun >= 45 && fun < 70 && calories >= 45 && calories < 70 && energy > 29 && energy < 45 )
      {
          //wyswietlenie tako.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/tako.png"));
      }
      else if( fun >= 45 && fun < 70 && calories >= 45 && calories < 70 && energy >= 45 && energy < 70 )
      {
          //wyswietlenie tako.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/tako.png"));
      }
      else if( fun > 29 && fun < 45 && calories > 29 && calories < 45 && energy > 29 && energy < 45 )
      {
          //wyswietlenie smutny.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/smutny.png"));
      }
      else if( fun > 29 && fun < 45 && calories > 29 && calories < 45 && energy >= 45 && energy< 70 )
      {
          //wyswietlenie smutny.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/smutny.png"));
      }
      else if( fun > 29 && fun < 45 && calories >= 45 && calories < 70 && energy > 29 && energy < 45 )
      {
          //wyswietlenie smutny.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/smutny.png"));
      }
      else if(fun >= 45 && fun < 70 && calories > 29 && calories < 45 && energy > 29 && energy < 45 )
      {
          //wyswietlenie smutny.png
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/smutny.png"));
      }
      else if( energy < 30 && energy > 2|| calories < 30 && calories > 2 || fun < 30 && fun > 2)
      {
          //wyswietenie chory.png + komunikat cos poszlo nie tak
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/chory.png"));
      }
      else if(energy <1 || calories <1 || fun <1)
      {
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/padl.png"));
          ui->wynik->setText(QString("Zabiłes go! Nowa gra za 5sek."));
          delay(5000);
          ui->wynik->setText(QString(" "));
          fun=50;
          calories=50;
          energy=50;
          ui->kalorie->setText(QString::number(calories));
          ui->energia->setText(QString::number(energy));
          ui->humor->setText(QString::number(fun));

          postawaPieska();
      }
      else
      {
          ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/tako.png"));
      }

}

void MainWindow::on_reset_clicked()
{
    fun=50;
    calories=50;
    energy=50;
    ui->kalorie->setText(QString::number(calories));
    ui->energia->setText(QString::number(energy));
    ui->humor->setText(QString::number(fun));

    postawaPieska();
}

void MainWindow::obrazZabawa()
{
    ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/z.png"));
    delay(1000);
}
void MainWindow::obrazJe()
{
    ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/j.png"));
    delay(1000);
}
void MainWindow::obrazSpi()
{
    ui->obraz->setPixmap(QPixmap(":/new/prefix1/img/s.png"));
    delay(1000);
}
