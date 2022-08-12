#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int idtimer=0;                                  // Идентификатор таймера
    int clk=0;                                      // Счетчик кликов мыши
    int win=0;                                      // Счетчик побед
    int lose=0;                                     // Счетчик поражений
    int random=0;                                   // Случайное число
    int checkpovtor=0;                              // Проверочное на равенство рандомному число
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();                    // Кнопка СТАРТ
    void on_pushButton_2_clicked();                  // Кнопка СТОП

};
#endif // MAINWINDOW_H
