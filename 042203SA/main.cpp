#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,400);


    LoginDialog logDLg;
    logDLg.exec();
    if(logDLg.m_login)
    {

        w.show();

        return a.exec();
    }



    return 0;
}
