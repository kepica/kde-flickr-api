#include <QApplication>
#include <QAction>
#include <QNetworkAccessManager>

#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>
// #include <QFile>
// #include <QDir>
// #include <QDateTime>
#include <QSettings>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

#include "o1.h"
#include "o0globals.h"
#include "o1requestor.h"


#include "photodown.h"
#include "favorites.h"
#include "komentar.h"
#include "mainwindow.h"
#include "mauth.h"

MainWindow *gore;
// Mauth *dole;


O1Requestor *m_requestor;   
QSettings *m_set;  
   
Mauth::Mauth(QWidget *parent, QSettings *mset, O1Requestor *o1req) : QObject(parent)
{
    gore = (MainWindow*) parent;
    m_set = mset;  // local copy
    m_requestor = o1req;
    
  
}






void Mauth::activity_comments()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.activity.userComments");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    QByteArray paramName3("per-page");
    QString mes3 = QString("30");
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikComments() ) );

    qDebug() << "activity comments START ";
}

void Mauth::photo_comments()
{
    qint64 unixtime = QDateTime::currentMSecsSinceEpoch()/1000;
    
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.photos.comments.getList");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    QByteArray paramName3("photo_id");
    QString mes3 = QString("29903216193");
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    
    QByteArray paramName4("max_comment_date");
    QString mes4 = QString::number(unixtime);
    reqParams << O0RequestParameter(paramName4, mes4.toLatin1());
    QByteArray paramName5("min_comment_date");
    QString mes5 = QString::number(unixtime-90*86400);
    reqParams << O0RequestParameter(paramName5, mes5.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikComments() ) );

    qDebug() << "od " << mes5 << " do " << mes4;
}

void Mauth::get_favorites()
{
    // qint64 unixtime = QDateTime::currentMSecsSinceEpoch()/1000;
    
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.favorites.getList");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    QByteArray paramName3("per_page");
    QString mes3 = QString("30");
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    /*
    QByteArray paramName4("max_comment_date");
    QString mes4 = QString::number(unixtime);
    reqParams << O0RequestParameter(paramName4, mes4.toLatin1());
    QByteArray paramName5("min_comment_date");
    QString mes5 = QString::number(unixtime-90*86400);
    reqParams << O0RequestParameter(paramName5, mes5.toLatin1());
    */
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikFavorites() ) );

    qDebug() <<  "favorites";  // "od " << mes5 << " do " << mes4;
}


void Mauth::get_groups()
{
    
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.groups.pools.getGroups");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    // QByteArray paramName6("extras");
    // QString mes6 = QString("tags, date_upload, owner_name");
    // reqParams << O0RequestParameter(paramName6, mes6.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikResponse() ) );

    qDebug() <<  "get groups ";
}

void Mauth::search_tags()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.photos.search");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    // QByteArray paramName3("user_id");
    // QString mes3 = QString(USER_ID);
    // reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    QByteArray paramName3("tags");
    QString mes3 = gore->tag;  // QString("decoration");   
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    QByteArray paramName4("max_upload_date");
    QString mes4 = gore->date_to; // QString::number(unixtime);
    reqParams << O0RequestParameter(paramName4, mes4.toLatin1());
    QByteArray paramName5("min_upload_date");
    QString mes5 = gore->date_from;  // QString::number(unixtime);
    reqParams << O0RequestParameter(paramName5, mes5.toLatin1());
    QByteArray paramName6("extras");
    QString mes6 = QString("owner_name");     
    reqParams << O0RequestParameter(paramName6, mes6.toLatin1());
    QByteArray paramName7("privacy_filter");
    QString mes7 = QString("1");     // 1- public
    reqParams << O0RequestParameter(paramName7, mes7.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( searchTags() ) );

    qDebug() <<  "public from " << mes5 << " to " << mes4;
}

void Mauth::search_pools()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.groups.pools.getPhotos");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    QByteArray paramName3("group_id");
    QString mes3 = QString("2389839@N23");   // in-explore
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    // QByteArray paramName3("tags");
    // QString mes3 = gore->tag;  // QString("decoration");   
    // reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    QByteArray paramName4("extras");
    QString mes4 = QString("owner_name");     
    reqParams << O0RequestParameter(paramName4, mes4.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( searchPools() ) );

    qDebug() <<  "inexplore pool ";
}

void Mauth::stats_suma()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.stats.getTotalViews");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    // QByteArray paramName3("date");
    // QString mes3 = QString("2016-12-16");
    // reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
   
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( respStatSuma() ) );

    qDebug() << "stats suma START ";
}

void Mauth::stats_photo()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.stats.getPhotoStats");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    QByteArray paramName3("date");
    QString mes3 = QString("2016-12-16");
    reqParams << O0RequestParameter(paramName3, mes3.toLatin1());
    QByteArray paramName4("photo_id");
    QString mes4 = QString("29903216193");
    reqParams << O0RequestParameter(paramName4, mes4.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( respStatPhoto() ) );

    qDebug() << "stats photo START ";
}


void Mauth::test_echo()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");
    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.test.echo");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikResponse() ) );

    qDebug() << "test echo START ";
    
}

void Mauth::test_login()
{
    QUrl url1 = QUrl("https://www.flickr.com/services/rest/");    
    QList<O0RequestParameter> reqParams = QList<O0RequestParameter>();
    QByteArray paramName1("method");
    QString mes1 = QString("flickr.test.login");
    reqParams << O0RequestParameter(paramName1, mes1.toLatin1());
    QByteArray paramName2("api-key");
    QString mes2 = gore->o1_key;
    reqParams << O0RequestParameter(paramName2, mes2.toLatin1());
    
    QByteArray postData = O1::createQueryParameters(reqParams);
    QNetworkRequest request(url1);
    request.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QNetworkReply *reply = m_requestor->post(request, reqParams, postData);
    connect(reply, SIGNAL(finished()), this, SLOT( flikResponse() ) );

    qDebug() << "test login START ";
    
}

void Mauth::flikResponse()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        QByteArray data = reply->readAll();
        qDebug() << data;
    }
}

void Mauth::flikComments()
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
        /*
        QFile file("/home/vjeko/Documents/data.xml");
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << QString("ne mogu otvoriti file");
            return;
        }
        QString m_error = QString("sve pet, nema greske");
        int i_line, i_col;
        i_line = 0;
        i_col = 0;
        m_doc.setContent(&file, &m_error, &i_line, &i_col );
        if (i_line != 0)
        {
            qDebug() << m_error << QString::number(i_line)  << QString::number(i_col);
           return;
        }
        */
        
        qDebug() << " xml parser ... ";
        // doc_elem = m_doc.documentElement();
        
        Komentar k1;
        // QList<Komentar> list2;
        QDomNodeList list1 = doc.elementsByTagName("comment");
        for(int i = 0 ; i < list1.count() ; i++)
        {
            node = list1.item(i);
            elem = node.toElement(); 
            if (elem.hasAttribute("author")) k1.m_author = elem.attribute("author");
            if (elem.hasAttribute("author_name")) k1.m_author_name = elem.attribute("author_name");
            if (elem.hasAttribute("realname")) k1.m_realname = elem.attribute("realname");
            if (elem.hasAttribute("iconserver")) k1.m_iconserver = elem.attribute("iconserver");
            if (elem.hasAttribute("iconfarm")) k1.m_iconfarm = elem.attribute("iconfarm");
            k1.m_tekst = elem.text();
            // list2.append(k1);
            
            qDebug() << k1.m_author << k1.m_author_name << k1.m_realname << k1.m_tekst;
        }
        
        /*
        QDomNodeList n_activity = m_doc.elementsByTagName("activity");
        QDomNode node = n_items.item(1);
        QDomELement m_event = node.firstChildElement("event");
    
        
        // if(doc_elem.nodeName().compare("T")==0)
        // {
            QDomNode node = doc_elem.firstChild();
            while (!node.isNull())
            {
                qDebug() << node.toElement().attribute("t");
                node = node.nextSibling();
            }
        // }
        */
        
    }
}

void Mauth::flikFavorites()
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
        
        qDebug() << " xml parser ... ";
        
        Favorites f1;
        // QList<Favorites> list2;
        QDomNodeList list1 = doc.elementsByTagName("photo");
        for(int i = 0 ; i < list1.count() ; i++)
        {
            node = list1.item(i);
            elem = node.toElement(); 
            if (elem.hasAttribute("id")) f1.m_id = elem.attribute("id");
            if (elem.hasAttribute("owner")) f1.m_owner = elem.attribute("owner");
            if (elem.hasAttribute("secret")) f1.m_secret = elem.attribute("secret");
            if (elem.hasAttribute("server")) f1.m_server = elem.attribute("server");
            if (elem.hasAttribute("title")) f1.m_title = elem.attribute("title");
            if (elem.hasAttribute("date_faved")) f1.m_date = elem.attribute("date_faved");
            if (elem.hasAttribute("ispublic")) f1.m_pub = elem.attribute("ispublic");
            if (elem.hasAttribute("farm")) f1.m_farm = elem.attribute("farm");
            // f1.m_tekst = elem.text();
            // list2.append(k1);
            
            QString mstr = "https://farm" + f1.m_farm + ".staticflickr.com/" + f1.m_server + "/" + f1.m_id + "_" + f1.m_secret + "_m.jpg"; 
            qDebug() << mstr;
            
            // QUrl imageUrl(mstr);
            // connect(m_photo, SIGNAL (downloaded()), dole, SLOT (loadImage()));
        }
                
    }
}


void Mauth::searchTags()
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
        
        // db->removeAllTagirane();             // reset last query 
        qDebug() << " xml parser ... ";
        
        Favorites f1;
        // QList<Favorites> list2;
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
            
            // list2.append(k1);
            // https://farm{farm-id}.staticflickr.com/{server-id}/{id}_{secret}_[mstzb].jpg
            
            QString m_url =  "https://farm"+f1.m_farm+".staticflickr.com/"+f1.m_server+"/"+f1.m_id+"_"+f1.m_secret+"_z.jpg"; 
            // qDebug() << m_url;
            QString m_name = f1.m_owner+"-"+f1.m_id+".jpg";
            
            // db->addTagirane(f1.m_id,f1.m_owner,f1.m_secret,f1.m_server,f1.m_farm,f1.m_title,f1.m_ownername); 
            
            gore->down_start(m_url, "tagirane", m_name, 2);  // 2- tags
             
        
        }
        
        
        
        qDebug() << " db tagirane saved ";
        
         
    }
}

void Mauth::searchPools()
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
        
        
        qDebug() << " xml parser ... ";
        
        Favorites f1;
        // QList<Favorites> list2;
        QDomNodeList list1 = doc.elementsByTagName("photo");
        
        int m_limit = 100;   // TODO put this limit to Settings
        
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
            
            // list2.append(k1);
            // https://farm{farm-id}.staticflickr.com/{server-id}/{id}_{secret}_[mstzb].jpg
            
            QString m_url =  "https://farm"+f1.m_farm+".staticflickr.com/"+f1.m_server+"/"+f1.m_id+"_"+f1.m_secret+"_z.jpg"; 
            qDebug() << m_url;
            
            QString m_name = f1.m_owner+"-"+f1.m_id+".jpg";
            gore->down_start(m_url, "groups", m_name, 3);        // 3- groups
             
        
        }
        
        
        
        qDebug() << " in-explore pool saved ";
        
         
    }
}
/*
void Mauth::print_osobne()
{
    db->printPhotos();
}
void Mauth::print_tagirane()
{
    db->printTagirane();
}
*/

void Mauth::loadImage()
{
    QPixmap buttonImage;
    // buttonImage.loadFromData(m_photo->downloadedData());
}

void Mauth::respStatSuma()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        qDebug() << "response";
        QByteArray data = reply->readAll();
        qDebug() << data;
    }
}

void Mauth::respStatPhoto()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) 
    {
        qDebug() << "ERR: " << reply->errorString();
        qDebug() << "Text: " << reply->readAll();
    }
    else
    {
        qDebug() << "response";
        QByteArray data = reply->readAll();
        qDebug() << data;
    }
}
