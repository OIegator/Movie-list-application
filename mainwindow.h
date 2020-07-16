#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytablemodel.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ab_pressed();
    void fb_pressed();
    void del_pressed();

private:
    Ui::MainWindow *ui;
    QPushButton app_button;
    QPushButton fil_button;
    QPushButton del_button;
    QList<Film> films;
    myTableModel model;
};
#endif // MAINWINDOW_H
