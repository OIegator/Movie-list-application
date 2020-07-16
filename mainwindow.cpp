#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include "film.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QList<Film> list;
    Film f("Dunkirk","Nolan","40");
    Film f2("Momento","Nolan","40");
    Film f3("Dark knight","Nolan","40");
    Film f4("Prestige","Nolan","40");
    films.append(f);
    films.append(f2);
    films.append(f3);
    films.append(f4);


    myTableModel *myModel = new myTableModel();
    myModel->populateData(films);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(ab_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(del_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(fb_pressed()));
    ui->tableView->setModel(myModel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ab_pressed() {
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "") {
        ui->statusbar->showMessage("Ошибка. Все поля должны быть заполнены.");
    } else { Film f(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit->text());
    films.append(f);
    myTableModel *myModel = new myTableModel();
    myModel->populateData(films);
    ui->tableView->setModel(myModel);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->statusbar->showMessage("Запись добавлена.");
    }
}
void MainWindow::del_pressed() {
    QItemSelectionModel *selectModel = ui->tableView->selectionModel();
    QModelIndexList indexes = selectModel->selectedRows();
    if (indexes.isEmpty()) {
        ui->statusbar->showMessage("Выберите строки для их удаления!");
        return;
    }

    films.removeAt(selectModel->currentIndex().row());
    myTableModel *myModel = new myTableModel();
    myModel->populateData(films);
    ui->tableView->setModel(myModel);
}
void MainWindow::fb_pressed() {
    QFile fileIn;
    QString input = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Select the file to open:"));

    fileIn.setFileName(input);
    if (!fileIn.open(QIODevice::ReadOnly)) {
      qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
    }
    ui->statusbar->showMessage("Нажата");
}

