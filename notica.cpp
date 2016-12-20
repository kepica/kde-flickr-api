
#include <QApplication>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

#include <kpassivepopup.h>

#include "mainwindow.h"
#include "notica.h"

MainWindow *gazi;
Notica *pop;

Notica::Notica(QWidget *parent) : KPassivePopup(parent)
{
    // this->setPopupStyle(Boxed);      // Balloon
    // this->setTimeout( -1 );  // 0- disable , tada clicked() -> hide() ,  -1 default
    
    pop = this;
    gazi = (MainWindow*) parent;
    
}

// QString &mstr
void Notica::staviPopup()
{
    QPixmap px;
    px.load("/home/vjeko/bin/geko-mali.jpg");
    QString mstr = gazi->poruka;
    pop->message(Balloon, mstr, "           Flick API widget, (*) kepica 2016",  px, pop, -1, QPoint(100,1050));
    // pop->show();
}    


