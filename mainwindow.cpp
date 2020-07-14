#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include "film.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<Film> list;
    Film f("Dunkirk","Nolan",40);
    Film f2("Momento","Nolan",40);
    Film f3("Dark knight","Nolan",40);
    Film f4("Prestige","Nolan",40);
    list.append(f);
    list.append(f2);
    list.append(f3);
    list.append(f4);

    myTableModel *myModel = new myTableModel();
    myModel->populateData(list);
    ui->tableView->setModel(myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

