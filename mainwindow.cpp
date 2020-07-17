#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include "film.h"
#include <string>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    myTableModel *myModel = new myTableModel();
    myModel->populateData(model.films);
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
    } else {
        Film f(ui->lineEdit_2->text(), ui->lineEdit_3->text(), "$" + ui->lineEdit->text());
        model.appendRow(f);
        myTableModel *myModel = new myTableModel();
        myModel->populateData(model.films);
        ui->tableView->setModel(myModel);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->statusbar->showMessage("Запись добавлена.");
    }
}

void MainWindow::del_pressed()
{
    QItemSelectionModel *selectModel = ui->tableView->selectionModel();
    QModelIndexList indexes = selectModel->selectedRows();
    if (indexes.isEmpty()) {
        ui->statusbar->showMessage("Выберите строки для их удаления!");
        return;
    }

    model.removeRow(selectModel->currentIndex().row());
    myTableModel *myModel = new myTableModel();
    myModel->populateData(model.films);
    ui->tableView->setModel(myModel);
    ui->statusbar->showMessage("Запись удалена.");
}

void MainWindow::fb_pressed()
{
    QFile fileIn;
    QString title;
    QString bud;
    QString dir;
    QString input = QFileDialog::getOpenFileName(
                QApplication::activeWindow(),
                QObject::tr("Выбирите файл:"));

    fileIn.setFileName(input);
    if (fileIn.open(QIODevice::ReadOnly)) {
        QDataStream stream(&fileIn); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        while (!stream.atEnd()) {
           stream >> title >> bud >> dir;
           Film f(title, dir, bud);
           model.films.append(f);
        }
        if(stream.status() != QDataStream::Ok)
        {
            qDebug("Ошибка чтения файла");
        }
    fileIn.close();
    }
    myTableModel *myModel = new myTableModel();
    myModel->populateData(model.films);
    ui->tableView->setModel(myModel);
    ui->statusbar->showMessage("Файл считан.");
}


