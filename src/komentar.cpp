#include <QApplication>
#include <QAction>
#include <QNetworkAccessManager>
#include <QDesktopServices>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>
#include <QFile>
#include <QDateTime>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>


#include "mainwindow.h"
#include "komentar.h"

MainWindow *gor1;
Komentar *dol1;


   
Komentar::Komentar(QWidget *parent) : QObject(parent)
{
    
    dol1 = this;
    gor1 = (MainWindow*) parent;
   
   
}


void Komentar::test() 
{
        
    qDebug() << "linked changed vidim sada ...";
}
