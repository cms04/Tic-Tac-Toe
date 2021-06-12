#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    field = new Field;
    resetField();
    current_player = 0;
}

void MainWindow::updatePlayer() {
    current_player = (current_player + 1) % 2;
}

MainWindow::~MainWindow() {
    delete ui;
    delete field;
}

void MainWindow::showWinningMessage() {
    QMessageBox msg;
    msg.setText("Player " + QString::number(current_player + 1) + " won!");
    msg.setStandardButtons(QMessageBox::Close | QMessageBox::Abort | QMessageBox::Ok);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setButtonText(QMessageBox::Abort, "Reset All");
    msg.setButtonText(QMessageBox::Ok, "New Game");
    switch (msg.exec()) {
        case QMessageBox::Close:
            this->close();
            break;
        case QMessageBox::Abort:
            this->on_actionReset_Scores_triggered();
            break;
        default:
            updateScore();
            updatePlayer();
            resetField();
    }
}

void MainWindow::showFullMessage() {
    QMessageBox msg;
    msg.setText("Nobody won.");
    msg.setStandardButtons(QMessageBox::Close | QMessageBox::Abort | QMessageBox::Ok);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setButtonText(QMessageBox::Abort, "Reset All");
    msg.setButtonText(QMessageBox::Ok, "New Game");
    switch (msg.exec()) {
        case QMessageBox::Close:
            this->close();
            break;
        case QMessageBox::Abort:
            this->on_actionReset_Scores_triggered();
            break;
        default:
            resetField();
            current_player = 0;
    }
}

void MainWindow::updateScore() {
    if (current_player == 0) {
        uint16_t points = ui->label_points1->text().toUShort(NULL, 10);
        ui->label_points1->setText(QString::number(points + 1, 10));
    } else {
        uint16_t points = ui->label_points2->text().toUShort(NULL, 10);
        ui->label_points2->setText(QString::number(points + 1, 10));
    }
}

void MainWindow::resetField() {
    field->reset();
    ui->b00->setText(" ");
    ui->b01->setText(" ");
    ui->b02->setText(" ");
    ui->b10->setText(" ");
    ui->b11->setText(" ");
    ui->b12->setText(" ");
    ui->b20->setText(" ");
    ui->b21->setText(" ");
    ui->b22->setText(" ");
}

void MainWindow::on_b00_clicked() {
    if (field->setField(0, 0, current_player)) {
        char rep = field->getRepresentation(0, 0);
        ui->b00->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b01_clicked() {
    if (field->setField(0, 1, current_player)) {
        char rep = field->getRepresentation(0, 1);
        ui->b01->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b02_clicked() {
    if (field->setField(0, 2, current_player)) {
        char rep = field->getRepresentation(0, 2);
        ui->b02->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b10_clicked() {
    if (field->setField(1, 0, current_player)) {
        char rep = field->getRepresentation(1, 0);
        ui->b10->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b11_clicked() {
    if (field->setField(1, 1, current_player)) {
        char rep = field->getRepresentation(1, 1);
        ui->b11->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b12_clicked() {
    if (field->setField(1, 2, current_player)) {
        char rep = field->getRepresentation(1, 2);
        ui->b12->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b20_clicked() {
    if (field->setField(2, 0, current_player)) {
        char rep = field->getRepresentation(2, 0);
        ui->b20->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b21_clicked() {
    if (field->setField(2, 1, current_player)) {
        char rep = field->getRepresentation(2, 1);
        ui->b21->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_b22_clicked() {
    if (field->setField(2, 2, current_player)) {
        char rep = field->getRepresentation(2, 2);
        ui->b22->setText(QString::fromLocal8Bit(&rep, 1));
        if (field->check(current_player)) {
            showWinningMessage();
            return;
        }
        if (field->isFull()) {
            showFullMessage();
            return;
        }
        updatePlayer();
    }
}

void MainWindow::on_actionReset_Scores_triggered() {
    resetField();
    current_player = 0;
    ui->label_points1->setText("0");
    ui->label_points2->setText("0");
}

void MainWindow::on_actionClose_triggered() {
    this->close();
}

