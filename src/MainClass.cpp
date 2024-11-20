#include "MainClass.h"

QString arr2hex(QByteArrayView arr){
    if(arr.isEmpty()) return "";
    QString res_str("0x");
    for(auto i=0;i<arr.size();i++)
        res_str.append(QString("%1").arg((quint8)arr.at(i), 2, 16, QChar('0')).toUpper());
    return res_str;
}


MainClass::MainClass(QObject *parent)
    : QFile(parent)
{
    setFileName("1.bin");
    if(!open(QIODeviceBase::WriteOnly | QIODeviceBase::Truncate)){
        qWarning().noquote().nospace() << "can't open;" << fileName();
    }
    buf.open(QBuffer::WriteOnly);
}

void MainClass::Writer(){
    QByteArray arr;
    for(uint i=0;i<71-8-1;i++) arr.append(i);

    static qint64 ms= 0xAABBCCDD00112233;
    ms++;

    const quint8 f_cnt= 0xFF;

    QDataStream stream(&buf);
    //stream.writeRawData(arr.constData(), arr.size());
    //stream.writeRawData((const char*)&ms, sizeof(ms)); //because `stream << ms` changes ordering from little to big endian
    stream << f_cnt;

    buf_cnt+= sizeof(f_cnt);
}


void MainClass::myflush(){
    qDebug().noquote().nospace() << "myflush;" << buf.size() << " B;null=" << buf.buffer().isNull();
    if(isOpen()){
        write(buf.buffer().constData(), buf_cnt);
        flush();
        buf.close();
        buf.open(QBuffer::WriteOnly);
        qDebug() << "myflush;nul=" << buf.buffer().isNull() << buf.size();
        buf_cnt= 0;
    }
    //buf.buffer().append('0');
    //qDebug() << "myflush;nul=" << buf.buffer().isNull();
}

MainClass::~MainClass(){
    qDebug() << "~;nul=" << buf.buffer().isNull() << "size" << buf.size() << "B";
    write(buf.buffer().constData(), buf_cnt);
}
