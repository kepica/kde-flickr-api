#include <QApplication>
#include <QAction>
#include <QNetworkAccessManager>
#include <QDesktopServices>

#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>


#include "mainwindow.h"
#include "favorites.h"

MainWindow *gor2;
Favorites *dol2;


   
Favorites::Favorites(QWidget *parent) : QObject(parent)
{
    
    dol2 = this;
    gor2 = (MainWindow*) parent;
   
   
}


void Favorites::test() 
{
    qDebug() << "linked changed vidim sada ...";
}

