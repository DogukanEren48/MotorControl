#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , direction(true)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    qputenv("QT_LOGGING_RULES", QByteArray("*.debug=true"));
    serial->setPortName("COM9"); // STM32'nin bağlı olduğu port adı
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port could not be opened.";
        return;
    } else {
        qDebug() << "Serial port opened successfully.";
    }

    connect(ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::on_pushButton_start_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &MainWindow::on_pushButton_stop_clicked);
    connect(ui->pushButton_direction, &QPushButton::clicked, this, &MainWindow::on_pushButton_direction_clicked);
}

MainWindow::~MainWindow()
{
    if (serial->isOpen()) {
        serial->close();
    }
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    int speed = ui->horizontalSlider_speed->value();
    int angle = ui->horizontalSlider_angle->value();
    int duration = ui->spinBox_duration->value();
    int turns = ui->horizontalSlider_turns->value();

    qDebug() << "Start Button Clicked:";
    qDebug() << "Speed:" << speed;
    qDebug() << "Direction:" << (direction ? 1 : 0);
    qDebug() << "Angle:" << angle;
    qDebug() << "Duration:" << duration;
    qDebug() << "Turns:" << turns;

    sendMotorCommand(speed, direction ? 1 : 0, angle, duration, turns);
}

void MainWindow::on_pushButton_stop_clicked()
{
    sendMotorCommand(0, 0, 0, 0, 0);
}

void MainWindow::on_pushButton_direction_clicked()
{
    direction = !direction;
    ui->pushButton_direction->setText(direction ? "Clockwise" : "Counterclockwise");
    qDebug() << "Direction Button Clicked, New Direction:" << (direction ? "Clockwise" : "Counterclockwise");
}

void MainWindow::sendMotorCommand(int speed, int direction, int angle, int duration, int turns)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << (uint16_t)speed << (uint16_t)direction << (uint16_t)angle << (uint16_t)duration << (uint16_t)turns;

    // CRC hesapla
    uint16_t crc = 0xFFFF;
    for (int i = 0; i < data.size(); i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    stream << crc;
    qDebug() << "Sending data:" << data.toHex();
    serial->write(data);
}

void MainWindow::on_horizontalSlider_angle_rangeChanged(int min, int max)
{

}

