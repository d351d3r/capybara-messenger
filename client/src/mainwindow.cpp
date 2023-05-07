#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new QTcpSocket(this)) {
    ui->setupUi(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onSocketReady);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::onSocketDisconnected);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_connectButton_clicked() {
    QString server_address = ui->serverAddressLineEdit->text();
    int server_port = ui->serverPortLineEdit->text().toInt();
    
    socket->connectToHost(server_address, server_port);
}

void MainWindow::on_sendButton_clicked() {
    QString message = ui->messageLineEdit->text();
    if (!message.isEmpty()) {
        socket->write(message.toUtf8());
        ui->messageLineEdit->clear();
    }
}

void MainWindow::onSocketReady() {
    QByteArray data = socket->readAll();
    ui->messagesTextEdit->append(QString::fromUtf8(data));
}

void MainWindow::onSocketDisconnected() {
    QMessageBox::information(this, "Disconnected", "The connection was lost.");
}
