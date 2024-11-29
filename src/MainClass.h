#pragma once

#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QDebug>

#include <QBuffer>
#include <QFile>

class MainClass : public QFile
{
    Q_OBJECT
    QBuffer buf;
    uint buf_cnt{}; //buf.buffer in fact size
public:
    MainClass(QObject *parent);
    ~MainClass();

public slots:
    void Writer(const quint8 f_cnt);
    void myflush();
};
