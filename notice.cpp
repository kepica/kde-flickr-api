#include <QApplication>
#include <QAction>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

// #include <knotification.h>
#include <kstatusnotifieritem.h>

#include "mainwindow.h"
#include "notice.h"

MainWindow *gazda;
Notice *glavni;

Notice::Notice(QWidget *parent) : KStatusNotifierItem(parent)
{
    this->setCategory( KStatusNotifierItem::ItemCategory(1) );
    // obav->setIconByName( QString("hisc-tapete-kicon.svgz") );
    // QIcon::fromTheme("document-new")
    this->setIconByName( QString("document-new") );
    this->setTitle( QString("neki naslov") );
    
    glavni = this;
    gazda = (MainWindow*) parent;
    // obav->showMessage( QString("naslov"), QString("poruka nekoliko redova"), QString("document-save"), 30300);
  
}

// QString &mstr
void Notice::staviNotice()
{
    QString mstr = gazda->poruka;
    glavni->showMessage( QString("Pazi vamo!"), mstr, QString("journal-new"), 30300);
    // obavijest->sendEvent();    
    // emit ideObavijest(mstr);
}    


