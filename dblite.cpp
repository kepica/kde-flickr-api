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
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>


#include "favorites.h"
#include "komentar.h"
#include "mainwindow.h"
#include "dblite.h"

MainWindow *gor3;
DBlite *dol3;



   
DBlite::DBlite(QWidget *parent, const QString &path) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    
    if ( !m_db.open() )
    {
        qDebug() << "error-db: wrong path ?";
    }
    
    dol3 = this;
    gor3 = (MainWindow*) parent;
}

DBlite::~DBlite()
{
    if (m_db.open())
    {
        m_db.close();
    }
}

bool DBlite::isOpen() const
{
    return m_db.isOpen();
}

bool DBlite::addPhoto(const QString &id, const QString &owner, const QString &secret, const QString &server,
                      const QString &farm, const QString &title, const QString &tags, const QString &dateupload, 
                      const QString &ownername)
{
    bool success = false;
    
    if ( !photoExists(id))
    {
        QSqlQuery m_ery;
        m_ery.prepare("INSERT INTO photo (id,owner,secret,server,farm,title,tags,dateupload,ownername)"
                        "VALUES (:id,:owner,:secret,:server,:farm,:title,:tags,:dateupload,:ownername)");
    
        m_ery.bindValue(":id",id);
        m_ery.bindValue(":owner",owner);
        m_ery.bindValue(":secret",secret);
        m_ery.bindValue(":server",server);
        m_ery.bindValue(":farm",farm);
        m_ery.bindValue(":title",title);
        m_ery.bindValue(":tags",tags);
        m_ery.bindValue(":dateupload",dateupload);
        m_ery.bindValue(":ownername",ownername);
    
        if (m_ery.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "insert error: " << m_ery.lastError();
        }
    }
    else
    {
        qDebug() << " photo id " << id << " exists in db";
    }
    return success;
}

bool DBlite::removePhoto(const QString &id)
{
    bool success;
    
    if ( photoExists(id) )
    {
        QSqlQuery m_ery;
        m_ery.prepare("DELETE FROM photo WHERE id = (:id)" );
        m_ery.bindValue(":id", id);
        success = m_ery.exec();
        
        if (!success)
        {
            qDebug() << "delete photo error " << m_ery.lastError();
        }
    }
    else
    {
        qDebug() << " photo id " << id << " not exists";
    }
    return success;
}

bool DBlite::removeAllPhoto()
{
    bool success = false;
    
    QSqlQuery m_ery;
    m_ery.prepare("DELETE FROM photo");
    if ( m_ery.exec() )
    {
        success = true;
    }
    else
    {
        qDebug() << " remove all error " << m_ery.lastError();
    }
    return success;
}

bool DBlite::photoExists(const QString &id) const
{
    bool exists = false;
    
    QSqlQuery m_ery;
    m_ery.prepare("SELECT id FROM photo WHERE id = (:id)");
    m_ery.bindValue(":id", id);
    
    if ( m_ery.exec())
    {
        if (m_ery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << " photo id " << id << " error " << m_ery.lastError();
    }
    return exists;
}

            
void DBlite::printPhotos() const
{
    QSqlQuery m_ery("SELECT * FROM photo");
    int i_id, i_owner, i_secret;
    i_id = m_ery.record().indexOf("id");
    i_owner = m_ery.record().indexOf("owner");
    i_secret = m_ery.record().indexOf("secret");
    while (m_ery.next())
    {
        QString id = m_ery.value(i_id).toString();
        QString owner = m_ery.value(i_owner).toString();
        QString secret = m_ery.value(i_secret).toString();
        qDebug() << id << owner << secret;
    }
}
    
        
bool DBlite::addTagirane(const QString &id, const QString &owner, const QString &secret, const QString &server,
                      const QString &farm, const QString &title, const QString &ownername)
{
    bool success = false;
    
        QSqlQuery m_ery;
        m_ery.prepare("INSERT INTO tagirane (id,owner,secret,server,farm,title,ownername)"
                        "VALUES (:id,:owner,:secret,:server,:farm,:title,:ownername)");
    
    m_ery.bindValue(":id",id);
    m_ery.bindValue(":owner",owner);
    m_ery.bindValue(":secret",secret);
    m_ery.bindValue(":server",server);
    m_ery.bindValue(":farm",farm);
    m_ery.bindValue(":title",title);
    m_ery.bindValue(":ownername",ownername);
    
    if (m_ery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "insert error: " << m_ery.lastError();
    }
    return success;
}

bool DBlite::removeAllTagirane()
{
    bool success = false;
    
    QSqlQuery m_ery;
    m_ery.prepare("DELETE FROM tagirane");
    if ( m_ery.exec() )
    {
        success = true;
    }
    else
    {
        qDebug() << " remove all error " << m_ery.lastError();
    }
    return success;
}

void DBlite::printTagirane() const
{
    QSqlQuery m_ery("SELECT * FROM tagirane");
    int i_id, i_owner, i_secret;
    i_id = m_ery.record().indexOf("id");
    i_owner = m_ery.record().indexOf("owner");
    i_secret = m_ery.record().indexOf("secret");
    while (m_ery.next())
    {
        QString id = m_ery.value(i_id).toString();
        QString owner = m_ery.value(i_owner).toString();
        QString secret = m_ery.value(i_secret).toString();
        qDebug() << id << owner << secret;
    }
}

