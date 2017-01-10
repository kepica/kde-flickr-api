#include <QDir>
#include "photodown.h"
 
PhotoDown::PhotoDown(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager;
}
 
PhotoDown::~PhotoDown() 
{ 
    manager->deleteLater();
}
 
void PhotoDown::setFile(QString fileURL, QString name, QString subdir)
{
    QString saveFile = QDir(subdir).filePath(name);
    // QString saveFile = subdir+ "/" + name;
    m_name = name;

    QNetworkRequest request;
    request.setUrl(QUrl(fileURL));
    reply = manager->get(request);

    file = new QFile;
    file->setFileName(saveFile);
    file->open(QIODevice::WriteOnly);

    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(onReplyFinished()));
}

void PhotoDown::onDownloadProgress(qint64 bytesRead,qint64 bytesTotal)
{
    QString trans;
    trans = QString::number(bytesRead).toLatin1() +" : "+ QString::number(bytesTotal).toLatin1();
    emit transfer(trans);
}

void PhotoDown::onFinished(QNetworkReply * reply)
{
    switch(reply->error())
    {
        case QNetworkReply::NoError:
        {
            // qDebug("file is downloaded successfully.");
            // emit downloaded(m_name);
        }break;
        default:{
            qDebug() << reply->errorString().toLatin1();
        };
    }

    if(file->isOpen())
    {
        file->close();
        file->deleteLater();
    }
}

void PhotoDown::onReadyRead()
{
    // qDebug() << "write to file ... ";
    file->write(reply->readAll());
}

void PhotoDown::onReplyFinished()
{
    // qDebug() << "file saved ok ! ";
    emit done();
    if(file->isOpen())
    {
        file->close();
        file->deleteLater();
    }
}
