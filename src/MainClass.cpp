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

void MainClass::Writer(const quint8 f_cnt){
    QDataStream stream(&buf);
    stream << f_cnt;
    buf_cnt+= sizeof(f_cnt);
    qDebug().noquote().nospace() << "Writer;size;" << buf.size() << ";" << buf.buffer().size() << ";B;isNull;" << buf.buffer().isNull() << ";buf_cnt;" << buf_cnt;
}


void MainClass::myflush(){
    //Write to file
    write(buf.buffer().constData(), buf_cnt);
    flush();
    buf_cnt= 0;
    qDebug().noquote().nospace() << "myflush;size;" << buf.size() << ";" << buf.buffer().size() << ";B;isNull;" << buf.buffer().isNull();

    //Choose A) or B) or C)
    /*//A) Open-close way
    buf.close();
    buf.open(QBuffer::WriteOnly);*/
    /*//B) Clear way
    buf.buffer().clear();*/
    //C) Seek way
    buf.seek(0L);

    qDebug().noquote().nospace() << "myflush;size;" << buf.size() << ";" << buf.buffer().size() << ";B;isNull;" << buf.buffer().isNull();
}

MainClass::~MainClass(){
    qDebug().noquote().nospace() << "~;size;" << buf.size() << ";" << buf.buffer().size() << ";B;isNull;" << buf.buffer().isNull() << ";buf_cnt;" << buf_cnt;
    write(buf.buffer().constData(), buf_cnt);
}
