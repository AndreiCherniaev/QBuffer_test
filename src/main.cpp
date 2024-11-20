#include <QCoreApplication>
#include "MainClass.h"
#include <signal.h>

void SigInt_Handler(int n_signal){
    printf("interrupted with code %u\n", n_signal); //Ctrl+C
    QCoreApplication::instance()->quit();  //exit(1);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    signal(SIGINT, &SigInt_Handler);

    MainClass myApp(QCoreApplication::instance());
    myApp.Writer();
    myApp.myflush();
    //myApp.Writer();

    QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);
    int ret= QCoreApplication::exec();
    return ret;
}
