#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    double energy=50;
    double calories=50;
    double fun=50;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_baw_sie_clicked();

    void on_spij_clicked();

    void on_jedz_clicked();

    void postawaPieska();

    void on_reset_clicked();

    void obrazZabawa();
    void obrazSpi();
    void obrazJe();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
