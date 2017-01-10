#include <QApplication>
#include <QAction>
#include <QEventLoop>
#include <QDesktopServices>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>

#include <QDir>
#include <QSettings>

#include <KTextEdit>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

#include <knotification.h>
#include <kstatusnotifieritem.h>

#include "O1/o1.h"
#include "O1/o0globals.h"
#include "O1/o1requestor.h"

#include "groups.h"
#include "favorites.h"
#include "tags.h"
#include "people.h"
#include "notice.h"
#include "notica.h"
#include "waitsignal.h"
#include "photodown.h"
#include "dblite.h"
#include "postavke.h"
#include "mainwindow.h"

O1 *o1;
Notice *obav;
Notica *oblak;

QNetworkAccessManager *manager;
O1Requestor *requestor;   

PhotoDown *m_photo;
DBlite *db;
QSettings *mset;


const char O1_KEY[] = "put-your-key";
const char O1_SECRET[] = "put-your-secret";
const char USER_ID[] = "put-your-id";  



MainWindow::MainWindow(QWidget *parent) : KXmlGuiWindow(parent)
{
    textArea = new KTextEdit();
    setCentralWidget(textArea);
  
    mset = new QSettings();  
    
    o1 = new O1(this);
    
    o1_key = QString(O1_KEY);
    o1_secret = QString(O1_SECRET);
    
    o1->setClientId(o1_key);
    o1->setClientSecret(o1_secret);
        
    o1->setRequestTokenUrl(QUrl("https://www.flickr.com/services/oauth/request_token"));
    o1->setAuthorizeUrl(QUrl("https://www.flickr.com/services/oauth/authorize?perms=write"));  // write read
    o1->setAccessTokenUrl(QUrl("https://www.flickr.com/services/oauth/access_token"));
        
    connect(o1, SIGNAL( linkedChanged() ), this, SLOT( onLinkedChanged() ) );
    connect(o1, SIGNAL(linkingFailed()), this, SLOT(onLinkingFailed()));
    connect(o1, SIGNAL(linkingSucceeded()), this, SLOT(onLinkingSucceeded()));
    connect(o1, SIGNAL(openBrowser(QUrl)), this, SLOT(onOpenBrowser(QUrl)));
    connect(o1, SIGNAL(closeBrowser()), this, SLOT(onCloseBrowser()));
    
    QString db_path = QDir::homePath() + QString("/bin/flickr.db");
    db = new DBlite(db_path);
    // qDebug() << db_path;
    
    if (db->isOpen())
    {
        textArea->append(QString("*** DB ok "));
    }
    else
    {
        textArea->append(QString("DB error: sqlite has to be installed !  Hint: put flickr.db to app folder "));
    }
    
    obav = new Notice(this);   // u system tray
    oblak = new Notica(this);   // u system tray
    // flkr = new Mauth(this, mset, o1);    // oAuth 
    // connect( flkr, SIGNAL( o1_linked(bool) ), this, SLOT(oauth_link(bool) ) );
  
    o1->link();
    
    manager = new QNetworkAccessManager(this);
    requestor =  new O1Requestor(manager, o1, this);   
    
    poruka = i18n("Ona posvuduša je opet stavila sliku na Flickr !");
    
    if (mset->value("pic_root_dir", "none") == "none")
    {
        img_dir = "none";    // cant save
        qDebug() << "cant save, choose pic home dir !";
    }
    else
    {
        img_dir = mset->value("pic_root_dir").toString();
        textArea->append(QString("*** Pic_dir: ")+img_dir);
    }
    
    m_photo =  new PhotoDown(this);       // downloadad + save
    connect( m_photo, SIGNAL( done() ), this, SLOT(down_done() ) );
    // connect( m_photo, SIGNAL( downloaded(QString) ), this, SLOT(down_down(QString) ) );
    connect( m_photo, SIGNAL( transfer(QString) ), this, SLOT(down_transfer(QString) ) );
  
    setupActions();
    this->setWindowIcon( QIcon("angel_icon.png"));
}

void MainWindow::onLinkedChanged() 
{
        
    qDebug() << "linked changed ...";
}

void MainWindow::onLinkingFailed() 
{
    textArea->append(QString("LINK to flickr fail !!! "));
}

void MainWindow::onLinkingSucceeded() 
{
    textArea->append(QString("*** LINK to flickr ok "));
}

void MainWindow::onOpenBrowser(const QUrl &url)
{
    qDebug() << "open firefox ... ";
    QDesktopServices::openUrl(url);
}

void MainWindow::onCloseBrowser()
{
    qDebug() << "browser closed";
}

void MainWindow::setupActions()
{
    
    // ----------------------------------------------------------------------- Tools menu
    
    QAction* clearAction = new QAction(this);
    clearAction->setText(i18n("&Clear"));
    clearAction->setIcon(QIcon::fromTheme("document-new"));    
    actionCollection()->setDefaultShortcut(clearAction, Qt::CTRL + Qt::Key_W);
    actionCollection()->addAction("clear", clearAction);
    connect(clearAction, SIGNAL(triggered(bool)), textArea, SLOT(clear()));
  
    QAction* postavkeAction = new QAction(this);
    postavkeAction->setText(i18n("Profile &Settings"));
    actionCollection()->setDefaultShortcut(postavkeAction, Qt::CTRL + Qt::Key_S);
    actionCollection()->addAction("postavke", postavkeAction);
    connect(postavkeAction, SIGNAL(triggered(bool)), this, SLOT( set_postavke() ) );
  
    /*
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
   */
    
    // ---------------------------------------------------------------------------    Notify menu
    
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
    
    // ------------------------------------------------------------------------- Flickr menu
    
    QAction* frendAction = new QAction(this);
    frendAction->setText(i18n("&Friends list"));
    // echotestAction->setIcon(QIcon::fromTheme("journal-new"));
    actionCollection()->setDefaultShortcut(frendAction, Qt::CTRL + Qt::Key_F);
    actionCollection()->addAction("frend", frendAction);
    connect(frendAction, SIGNAL(triggered(bool)), this, SLOT( friend_list() ) );
    
    QAction* groupsAction = new QAction(this);
    groupsAction->setText(i18n("&Get groups ID"));
    actionCollection()->setDefaultShortcut(groupsAction, Qt::CTRL + Qt::Key_G);
    actionCollection()->addAction("groups", groupsAction);
    connect(groupsAction, SIGNAL(triggered(bool)), this, SLOT( groups_list() ) );
    
    /*
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
    */
    
    // -----------------------------------------------------------------------   Trace menu
    
    /*
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
   */
    
    // -------------------------------------------------------------------------------- SEARCH menu
    
    /*
    QAction* favoritesAction = new QAction(this);
    favoritesAction->setText(i18n("&Favorites"));
    actionCollection()->setDefaultShortcut(favoritesAction, Qt::CTRL + Qt::Key_C);
    actionCollection()->addAction("favorites", favoritesAction);
    connect(favoritesAction, SIGNAL(triggered(bool)), flkr, SLOT( get_favorites() ) );
    */
    QAction* osobneAction = new QAction(this);
    osobneAction->setText(i18n("Search by user"));
    actionCollection()->setDefaultShortcut(osobneAction, Qt::CTRL + Qt::Key_U);
    actionCollection()->addAction("osobne", osobneAction);
    connect(osobneAction, SIGNAL(triggered(bool)), this, SLOT( search_people() ) );
    
    QAction* tagsAction = new QAction(this);
    tagsAction->setText(i18n("Search by tag"));
    actionCollection()->setDefaultShortcut(tagsAction, Qt::CTRL + Qt::Key_T);
    actionCollection()->addAction("tags", tagsAction);
    connect(tagsAction, SIGNAL(triggered(bool)), this, SLOT( search_tags() ) );
   
    QAction* poolsAction = new QAction(this);
    poolsAction->setText(i18n("Search group pool"));
    actionCollection()->setDefaultShortcut(poolsAction, Qt::CTRL + Qt::Key_P);
    actionCollection()->addAction("pools", poolsAction);
    connect(poolsAction, SIGNAL(triggered(bool)), this, SLOT( search_pools() ) );
    
    QAction* grupeAction = new QAction(this);
    grupeAction->setText(i18n("Search in groups"));
    actionCollection()->setDefaultShortcut(grupeAction, Qt::CTRL + Qt::Key_G);
    actionCollection()->addAction("grupe", grupeAction);
    connect(grupeAction, SIGNAL(triggered(bool)), this, SLOT( search_groups() ) );
    
   
    
    KStandardAction::quit(qApp, SLOT(quit()), actionCollection());

    setupGUI(Default, "oblaciui.rc");
}

void MainWindow::down_done()
{
    // qDebug() << " download + writ
}

void MainWindow::set_postavke()
{
    // this dont work , why ???
    // Postavke m_postavke(this);
    // m_postavke.show();
    
    // on heap is ok !
    Postavke *m_postavke = new Postavke(this, mset);
    m_postavke->show();
}

void MainWindow::search_people()
{
    People *m_people = new People(this, mset);
    m_people->show();
}

void MainWindow::search_tags()
{
    Tags *m_tags = new Tags(this, mset);
    m_tags->show();
}

void MainWindow::search_pools()
{
    Tags *m_tags = new Tags(this, mset);
    m_tags->show();
}

void MainWindow::search_groups()
{
    Groups *m_grp = new Groups(this, mset);
    m_grp->show();
}

void MainWindow::friend_list()
{
    get_reply(71);
}

void MainWindow::groups_list()
{
    get_reply(72);
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

void MainWindow::down_start(QString url, QString dir, QString name, int koji)
{

    QString m_path = mset->value("pic_root_dir").toString();
    
    switch (koji)
    {
        case 1:
            m_path = m_path + "/people/" + dir;
            break;
        case 2:
            m_path = m_path + "/tags/" + dir;
            break;
        case 3:
            m_path = m_path + "/groups/" + dir;
            break;
    }
    
    QDir m_dir(m_path);
    if ( !m_dir.exists() )
    {
        m_dir.mkpath(".");
    };
            
    
    WaitSignal pause((QObject*) m_photo, SIGNAL( done()) );
    m_photo->setFile(url, name, m_path);
    
    if ( pause.wait(60100) )
    {
        textArea->append(QString("*** saved: ")+name);
    }
    else
    {
        qDebug() << "out of time: download + save file";
    }
}


void MainWindow::get_reply(int koji)
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramN1 = "method";
    QByteArray paramN2 = "api-key";
    QByteArray paramN3;
    QByteArray paramN4;
    QByteArray paramN5;
    QByteArray paramN6;
    QByteArray paramN7;
    QString mes1;
    QString mes2 = o1_key;
    QString mes3;
    QString mes4;
    QString mes5;
    QString mes6;
    QString mes7;
    QByteArray postData;
    QNetworkReply *reply;
    
    switch (koji)
    {
        case 1:
             
            mes1 = QString("flickr.people.getPhotos");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            paramN3 = "user_id";
            mes3 = user_id;
            reqParams << O0RequestParameter(paramN3, mes3.toLatin1());
            paramN4 = "max_upload_date";
            mes4 = date_to;
            reqParams << O0RequestParameter(paramN4, mes4.toLatin1());
            paramN5 = "min_upload_date";
            mes5 = date_from;
            reqParams << O0RequestParameter(paramN5, mes5.toLatin1());
            paramN6 = "extras";
            mes6 = QString("tags, date_upload, owner_name");
            reqParams << O0RequestParameter(paramN6, mes6.toLatin1());            
            
            photo_search = 1;
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_photo() ) );
            qDebug() <<  " user " << mes3 << " from " << mes5 << " to " << mes4;
            break;
            
        case 2:
            
            mes1 = QString("flickr.photos.search");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            paramN3 = "tags";
            mes3 = img_tag;
            reqParams << O0RequestParameter(paramN3, mes3.toLatin1());
            paramN4 = "max_upload_date";
            mes4 = date_to;
            reqParams << O0RequestParameter(paramN4, mes4.toLatin1());
            paramN5 = "min_upload_date";
            mes5 = date_from;
            reqParams << O0RequestParameter(paramN5, mes5.toLatin1());
            paramN6 = "extras";
            mes6 = QString("owner_name, date_upload, tags");
            reqParams << O0RequestParameter(paramN6, mes6.toLatin1());            
            paramN7 = "privacy_filter";
            mes7 = QString("1");    // 1- public only TODO in settings
            reqParams << O0RequestParameter(paramN7, mes7.toLatin1());            
            
            photo_search = 2;
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_photo() ) );
            qDebug() <<  "public " << img_tag << " from " << mes5 << " to " << mes4;
            break;
            
        case 3:
            
            mes1 = QString("flickr.groups.pools.getPhotos");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            paramN3 = "group_id";
            mes3 = group_id;
            reqParams << O0RequestParameter(paramN3, mes3.toLatin1());
            paramN4 = "extras";
            mes4 = QString("owner_name, date_upload, tags");
            reqParams << O0RequestParameter(paramN6, mes6.toLatin1());            
            
            photo_search = 3;
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_photo() ) );
            qDebug() << " pool photos " << group_id;
            break;
            
        case 4:
            
            mes1 = QString("flickr.photos.search");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            paramN3 = "group_id";
            mes3 = group_id;
            reqParams << O0RequestParameter(paramN3, mes3.toLatin1());
            paramN4 = "max_upload_date";
            mes4 = date_to;
            reqParams << O0RequestParameter(paramN4, mes4.toLatin1());
            paramN5 = "min_upload_date";
            mes5 = date_from;
            reqParams << O0RequestParameter(paramN5, mes5.toLatin1());
            paramN6 = "extras";
            mes6 = QString("owner_name, date_upload, tags");
            reqParams << O0RequestParameter(paramN6, mes6.toLatin1());            
            paramN7 = "privacy_filter";
            mes7 = QString("1");    // 1- public only TODO in settings
            reqParams << O0RequestParameter(paramN7, mes7.toLatin1());            
            
            photo_search = 3;  // same as group pool
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_photo() ) );
            qDebug() <<  "group " << group_id << " from " << mes5 << " to " << mes4;
            break;
            
        case 71:
                         
            // --------------------------------------- insert contacts to People table
            mes1 = QString("flickr.contacts.getList");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            paramN2 = "api-key";
            mes2 = o1_key;
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_friend() ) );
            qDebug() <<  " friends ";
            break;
            
        case 72:
            
            // ---------------------------------- insert group-ID into Group table
            mes1 = QString("flickr.groups.pools.getGroups");
            reqParams << O0RequestParameter(paramN1, mes1.toLatin1());
            reqParams << O0RequestParameter(paramN2, mes2.toLatin1());
            
            postData = O1::createQueryParameters(reqParams);
            reply = requestor->post(request, reqParams, postData);
            connect(reply, SIGNAL(finished()), this, SLOT( parse_groups_id() ) );
            qDebug() <<  "get groups ID ";
            break;

    }
}

void MainWindow::parse_photo()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        
        QByteArray data = reply->readAll();
        qDebug() << data;
        
        QDomNode node;
        QDomElement elem, v;
        QDomDocument doc;
        doc.setContent(data);
        
        qDebug() << " xml parser photo ... ";
        
        Favorites f1;
        QDomNodeList list1 = doc.elementsByTagName("photo");

        int m_limit = 30;   // TODO put this limit to Settings
        
        if (list1.count() < m_limit)
        {
            m_limit = list1.count();
        }
        
        for(int i = 0 ; i <  m_limit; i++)
        {
            node = list1.item(i);
            elem = node.toElement(); 
            if (elem.hasAttribute("id")) f1.m_id = elem.attribute("id");
            if (elem.hasAttribute("owner")) f1.m_owner = elem.attribute("owner");
            if (elem.hasAttribute("ownername")) f1.m_ownername = elem.attribute("ownername");
            if (elem.hasAttribute("secret")) f1.m_secret = elem.attribute("secret");
            if (elem.hasAttribute("server")) f1.m_server = elem.attribute("server");
            if (elem.hasAttribute("farm")) f1.m_farm = elem.attribute("farm");
            if (elem.hasAttribute("title")) f1.m_title = elem.attribute("title");
            if (elem.hasAttribute("tags")) f1.m_tags = elem.attribute("tags");
            if (elem.hasAttribute("dateupload")) f1.m_dateupload = elem.attribute("dateupload");

            QString m_name;
            if (db->addPhoto(f1.m_id,f1.m_owner,f1.m_secret,f1.m_server,f1.m_farm,
                f1.m_title,f1.m_tags,f1.m_dateupload,f1.m_ownername)) 
            {
                QString m_url =  "https://farm"+f1.m_farm+".staticflickr.com/"+f1.m_server+"/"+f1.m_id+"_"+f1.m_secret+img_sufix+".jpg"; 
                switch (photo_search)
                {
                    case 1:
                        m_name = f1.m_id+".jpg";
                        down_start(m_url, f1.m_owner, m_name, 1);  
                        break;
                    case 2:
                        m_name = f1.m_owner+"-"+f1.m_id+".jpg";
                        down_start(m_url, img_tag, m_name, 2);
                        break;
                    case 3:
                        m_name = f1.m_owner+"-"+f1.m_id+".jpg";
                        down_start(m_url, group_id, m_name, 3);
                        break;
                } // sw
            } // add
        } // for
    } // reply
}

void MainWindow::parse_friend()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        
        QByteArray data = reply->readAll();
        qDebug() << data;
        
        QDomNode node;
        QDomElement elem, v;
        QDomDocument doc;
        doc.setContent(data);
        
        qDebug() << " xml parser friends ... ";
        
        QString m_id;
        QString m_name;
        QString m_nick;
        QString m_server;
        QDomNodeList list1 = doc.elementsByTagName("contact");
        for(int i = 0 ; i < list1.count() ; i++)
        {
            node = list1.item(i);
            elem = node.toElement(); 
            if (elem.hasAttribute("nsid")) m_id = elem.attribute("nsid");
            if (elem.hasAttribute("realname")) m_name = elem.attribute("realname");
            if (elem.hasAttribute("username")) m_nick = elem.attribute("username");
            if (elem.hasAttribute("iconserver")) m_server = elem.attribute("iconserver");
            
            QString mstr =  m_id + m_name + m_nick + m_server; 
            qDebug() << mstr;
            db->addPeople(m_id, m_name, m_nick, m_server);
        }
    }
}

void MainWindow::parse_groups_id()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        
        QByteArray data = reply->readAll();
        qDebug() << data;
        
        QDomNode node;
        QDomElement elem, v;
        QDomDocument doc;
        doc.setContent(data);
        
        qDebug() << " xml parser groups ... ";
            
        QString m_id;
        QString m_name;
    
        QDomNodeList list1 = doc.elementsByTagName("group");
        for(int i = 0 ; i < list1.count() ; i++)
        {
            node = list1.item(i);
            elem = node.toElement(); 
            if (elem.hasAttribute("id")) m_id = elem.attribute("id");
            if (elem.hasAttribute("name")) m_name = elem.attribute("name");
           
            
            QString mstr =  m_id + m_name; 
            qDebug() << mstr;
            db->addGroups(m_id, m_name, m_name);
        }
    }
}
