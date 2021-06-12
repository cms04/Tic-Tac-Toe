#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "field.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_b00_clicked();

        void on_b01_clicked();

        void on_b02_clicked();

        void on_b10_clicked();

        void on_b11_clicked();

        void on_b12_clicked();

        void on_b20_clicked();

        void on_b21_clicked();

        void on_b22_clicked();

        void on_actionReset_Scores_triggered();

    private:
        Ui::MainWindow *ui;
        Field *field;
        uint8_t current_player;
        void updatePlayer();
        void showWinningMessage();
        void resetField();
        void updateScore();
};
#endif // MAINWINDOW_H
