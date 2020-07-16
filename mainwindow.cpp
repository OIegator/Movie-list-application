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

    Film f("Dunkirk","Nolan","40");
    Film f2("Momento","Nolan","40");
    Film f3("Dark knight","Nolan","40");
    Film f4("Prestige","Nolan","40");
    films.append(f);
    films.append(f2);
    films.append(f3);
    films.append(f4);

    QFile fileIn;
    QString name;
    QString bud;
    QString dir;
    QString input = QFileDialog::getOpenFileName(
                this,
                QObject::tr("Select the file to open:"));


    fileIn.setFileName(input);
    if (fileIn.open(QIODevice::ReadOnly)) {
        QDataStream stream(&fileIn); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        while (!stream.atEnd()) {
           stream >> name >> bud >> dir;
           Film f(name, dir, bud);
           model.films.append(f);
        }
        if(stream.status() != QDataStream::Ok)
        {
            qDebug("Ошибка чтения файла");
        }
    fileIn.close();
    }
    QList<Film> list;

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
    } else { Film f(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit->text());
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
void MainWindow::del_pressed() {
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
}
void MainWindow::fb_pressed() {
    QFile fileIn;
    QString input = QFileDialog::getOpenFileName(
                QApplication::activeWindow(),
                QObject::tr("Select the file to open:"));

    fileIn.setFileName(input);

    if (!fileIn.open(QIODevice::ReadOnly)) {
      ui->statusbar->showMessage("dwdwdwdwd");

    if (fileIn.open(QIODevice::ReadWrite)) {
      QDataStream stream(&fileIn); // если файл не найден, то выводим предупреждение и завершаем выполнение программы


    }


    QTextStream fin(&fileIn);


    // Вначале посчитаем сколько чисел в файле
    int count = 0; // число чисел в файле
    int temp; // Временная переменная
     QString symbol;

    while (!fin.atEnd()) {
        // в пустоту считываем из файла числа
        symbol = fin.read(1);

        if (symbol == '\n')
            count++; // увеличиваем счетчик строк
    }


    fileIn.close(); // Закрываем файл для повторного чтения

    QTextStream finSec(&fileIn);
    for (int i=0;i<count;i++){
        QString s,s1,s2;
        symbol = finSec.read(1);
        while(symbol != ' '){
            s=s+symbol;
            symbol = finSec.read(1);
        }
        symbol = finSec.read(1);
        while(symbol != ' '){
            s1=s1+symbol;
            symbol = finSec.read(1);
        }
        symbol = finSec.read(1);
        while(symbol != '\n'){
            s2=s2+symbol;
            symbol = finSec.read(1);
        }
        Film f(s,s1,s2);
        films.append(f);
    }
    Film f("dwd","wdwdw","dwdw");
    films.append(f);
    myTableModel *myModel = new myTableModel();
    myModel->populateData(films);
    ui->tableView->setModel(myModel);
    QTextStream finThd(&fileIn); // Сформировали последний поток по файли

}

}

