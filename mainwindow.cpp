#include <QApplication>
#include <QAction>
#include <QEventLoop>
#include <QDir>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include <KTextEdit>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

#include <knotification.h>
#include <kstatusnotifieritem.h>

#include "o1.h"
#include "mauth.h"
#include "notice.h"
#include "notica.h"
#include "waitsignal.h"
#include "photodown.h"
#include "mainwindow.h"

Notice *obav;
Notica *oblak;
Mauth *flkr;
PhotoDown *m_photo;




MainWindow::MainWindow(QWidget *parent) : KXmlGuiWindow(parent)
{
    // QFrame *okvir;
    // QPixmap *slika;
    // okvir  = new QFrame();
    // okvir->setFrameStyle(QFrame::StyledPanel);
    // okvir->setStyleSheet("background-image: slika");
    // url(/home/vjeko/bin/geko-mali.jpg)
    // QVBoxLayout *tabla = new QVBoxLayout();
    // okvir->setLayout(tabla);
    // slika    = new QPixmap("/home/vjeko/bin/geko-mali.jpg");
    // QBrush *brush  = new QBrush(*slika);
    // slika = new QPixmap();
    // slika->load("/home/vjeko/bin/geko-mali.jpg");
    // tabla->addWidget((QWidget*) textArea);
    // tabla->addWidget(new QPushButton("Click me!"));
    // pal.setBrush(QPalette::Background, *brush);
    // QPalette pal; 
    // pal.setBrush( okvir->backgroundRole(), QBrush( QImage( "/home/vjeko/bin/geko-mali.jpg" ) ) );
    // okvir->setPalette(pal);  
    
    textArea = new KTextEdit();
    setCentralWidget(textArea);
  
    obav = new Notice(this);   // u system tray
    oblak = new Notica(this);   // u system tray
    flkr = new Mauth(this);    // oAuth 
  
    connect( flkr, SIGNAL( o1_linked(bool) ), this, SLOT(oauth_link(bool) ) );
  
    poruka = i18n("Ona posvuduša je opet stavila sliku na Flickr !");
    
    date_from = QString("1477550147");
    date_to = QString("1480142147");
    
    tag = QString("decorations");
    savePath = QString("/home/vjeko/slike/")+tag;
    QDir dir(savePath);
    if ( !dir.exists() )
    {
        dir.mkpath(".");
    }
    
    m_photo =  new PhotoDown(this);       // downloadad + save
    
    connect( m_photo, SIGNAL( done() ), this, SLOT(down_done() ) );
    // connect( m_photo, SIGNAL( downloaded(QString) ), this, SLOT(down_down(QString) ) );
    connect( m_photo, SIGNAL( transfer(QString) ), this, SLOT(down_transfer(QString) ) );
  
    setupActions();
}

void MainWindow::setupActions()
{
    /*
    QAction* clearAction = new QAction(this);
    clearAction->setText(i18n("&Clear"));
    clearAction->setIcon(QIcon::fromTheme("document-new"));    
    actionCollection()->setDefaultShortcut(clearAction, Qt::CTRL + Qt::Key_W);
    actionCollection()->addAction("clear", clearAction);
    connect(clearAction, SIGNAL(triggered(bool)), textArea, SLOT(clear()));
    */
    
    QAction* pokazAction = new QAction(this);
    pokazAction->setText(i18n("&Pokaz"));
    pokazAction->setIcon(QIcon::fromTheme("document-save"));
    actionCollection()->setDefaultShortcut(pokazAction, Qt::CTRL + Qt::Key_P);
    actionCollection()->addAction("pokaz", pokazAction);
    connect(pokazAction, SIGNAL(triggered(bool)), obav, SLOT( staviNotice() ) );
    
    QAction* balonAction = new QAction(this);
    balonAction->setText(i18n("&Balon"));
    balonAction->setIcon(QIcon::fromTheme("document-new"));
    actionCollection()->setDefaultShortcut(balonAction, Qt::CTRL + Qt::Key_B);
    actionCollection()->addAction("balon", balonAction);
    connect(balonAction, SIGNAL(triggered(bool)), oblak, SLOT( staviPopup() ) );
    
    QAction* echotestAction = new QAction(this);
    echotestAction->setText(i18n("&Echo-test"));
    // echotestAction->setIcon(QIcon::fromTheme("journal-new"));
    actionCollection()->setDefaultShortcut(echotestAction, Qt::CTRL + Qt::Key_E);
    actionCollection()->addAction("echotest", echotestAction);
    connect(echotestAction, SIGNAL(triggered(bool)), flkr, SLOT( test_echo() ) );
   
    QAction* logintestAction = new QAction(this);
    logintestAction->setText(i18n("&Login-test"));
    // echotestAction->setIcon(QIcon::fromTheme("journal-new"));
    actionCollection()->setDefaultShortcut(logintestAction, Qt::CTRL + Qt::Key_L);
    actionCollection()->addAction("logintest", logintestAction);
    connect(logintestAction, SIGNAL(triggered(bool)), flkr, SLOT( test_login() ) );
    
    QAction* linkAction = new QAction(this);
    linkAction->setText(i18n("&Link"));
    // echotestAction->setIcon(QIcon::fromTheme("journal-new"));
    actionCollection()->setDefaultShortcut(linkAction, Qt::CTRL + Qt::Key_K);
    actionCollection()->addAction("link", linkAction);
    connect(linkAction, SIGNAL(triggered(bool)), flkr, SLOT( lnk() ) );
    
    QAction* unlinkAction = new QAction(this);
    unlinkAction->setText(i18n("&Unlink"));
    // echotestAction->setIcon(QIcon::fromTheme("journal-new"));
    actionCollection()->setDefaultShortcut(unlinkAction, Qt::CTRL + Qt::Key_U);
    actionCollection()->addAction("unlink", unlinkAction);
    connect(unlinkAction, SIGNAL(triggered(bool)), flkr, SLOT( ulnk() ) );
    
    QAction* commentsAction = new QAction(this);
    commentsAction->setText(i18n("&Comments"));
    actionCollection()->setDefaultShortcut(commentsAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("comments", commentsAction);
    connect(commentsAction, SIGNAL(triggered(bool)), flkr, SLOT( photo_comments() ) );
    
    QAction* statsumAction = new QAction(this);
    statsumAction->setText(i18n("&Stats-Sume"));
    actionCollection()->setDefaultShortcut(statsumAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("statsum", statsumAction);
    connect(statsumAction, SIGNAL(triggered(bool)), flkr, SLOT( stats_suma() ) );
   
    QAction* statphotoAction = new QAction(this);
    statphotoAction->setText(i18n("&Stats-Photo"));
    actionCollection()->setDefaultShortcut(statphotoAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("statphoto", statphotoAction);
    connect(statphotoAction, SIGNAL(triggered(bool)), flkr, SLOT( stats_photo() ) );
   
    QAction* favoritesAction = new QAction(this);
    favoritesAction->setText(i18n("&Favorites"));
    actionCollection()->setDefaultShortcut(favoritesAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("favorites", favoritesAction);
    connect(favoritesAction, SIGNAL(triggered(bool)), flkr, SLOT( get_favorites() ) );
   
    QAction* osobneAction = new QAction(this);
    osobneAction->setText(i18n("&Moje slike"));
    actionCollection()->setDefaultShortcut(osobneAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("osobne", osobneAction);
    connect(osobneAction, SIGNAL(triggered(bool)), flkr, SLOT( get_osobne() ) );
   
    QAction* printAction = new QAction(this);
    printAction->setText(i18n("&Print sql photo"));
    actionCollection()->setDefaultShortcut(printAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("print", printAction);
    connect(printAction, SIGNAL(triggered(bool)), flkr, SLOT( print_osobne() ) );
   
    QAction* listAction = new QAction(this);
    listAction->setText(i18n("&List sql tagirane"));
    actionCollection()->setDefaultShortcut(listAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("list", listAction);
    connect(listAction, SIGNAL(triggered(bool)), flkr, SLOT( print_tagirane() ) );
   
    QAction* tagsAction = new QAction(this);
    tagsAction->setText(i18n("&Search by tag"));
    actionCollection()->setDefaultShortcut(tagsAction, Qt::CTRL + Qt::Key_T);
    actionCollection()->addAction("tags", tagsAction);
    connect(tagsAction, SIGNAL(triggered(bool)), flkr, SLOT( search_tags() ) );
   
    KStandardAction::quit(qApp, SLOT(quit()), actionCollection());

    
    // -------------------------------------- na kraju odradi
    setupGUI(Default, "oblaciui.rc");
}

void MainWindow::down_done()
{
    // qDebug() << " download + writ
}

void MainWindow::oauth_link(bool flag)
{
    if (flag)
    {
        textArea->append(QString("*** LINK to flickr ok "));
    }
    else
    {
        qDebug() << "link fail";
    }
}

/*
void MainWindow::down_down(QString name)
{
    textArea->append(QString("--- downloaded: ")+name);
}
*/

void MainWindow::down_transfer(QString str)
{
    // qDebug() << " transfer " << str;
    textArea->append(str);
}

void MainWindow::down_start(QString url, QString name)
{
    WaitSignal pause((QObject*) m_photo, SIGNAL( done()) );
    m_photo->setFile(url, name, savePath);
    
    if ( pause.wait(60100) )
    {
        textArea->append(QString("*** saved: ")+name);
    }
    else
    {
        qDebug() << "istekla 1 minuta";
    }
}
