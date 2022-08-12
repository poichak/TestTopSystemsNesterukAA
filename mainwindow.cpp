#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()                    // метод кнопки Старт
{
    if (idtimer!=0){                                             // Если таймер запущен
    killTimer(idtimer);                                          // Отменить таймер
    idtimer=0;                                                   // Указать что таймер остановлен
    }
    win=-1;                                                 // random=clk=0
    lose=0;
    random=0;
    ui->label_lose->setText("0");
    ui->label_win->setText("0");
    idtimer=startTimer(2000);
    ui->label->setText("Игра началась!");
}

void MainWindow::on_pushButton_2_clicked()                  // метод кнопки Стоп
{
    if (idtimer!=0){                                             // killTimer только если он запущен
    killTimer(idtimer);
    idtimer=0;
    }
    ui->label->setText("Игра остановлена");
}

void MainWindow::timerEvent(QTimerEvent *event)             // событие - "2 секунды прошло"
{
    if (event->timerId()==idtimer){                                  // Проверяем идентификатор таймера

        if (random==clk){                                            // Это Победа
            win=win+1;
            ui->label_win->setText(QString::number(win));
        }

        else {                                                      // Это Поражение
        lose=lose+1;
        ui->label_lose->setText(QString::number(lose));}
                                                                    // Отображение сгенерированного числа
    checkpovtor=random;
    random = 3+rand() % static_cast<int>(3);
    if(checkpovtor==random)                                         //Сгенерированое число повторилось
    {ui->label->setText(ui->label->text() + "!");}
    else                                                            //Сгенерировано отличное от предыдущего число
    {ui->label->setText(QString::number(random));}
    clk=0;                                                          //начинаем слушать мышь
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)        // обработка клика мыши
{
        if(event->buttons() & Qt::LeftButton){
        clk=clk+1;}
}

void MainWindow::closeEvent(QCloseEvent *event)             // обработка закрытия программы
{
    QMessageBox message;
    message.setWindowTitle("Конец игры");
    message.setText("Возвращайтесь еще!");
    message.setButtonText(QMessageBox::Ok, ("Обязательно"));

    if(message.exec() == QMessageBox::Ok)
        event->accept();
}
