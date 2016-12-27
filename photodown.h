#ifndef PHOTODOWN_H
#define PHOTODOWN_H
 
#include <QFile>
#include <QUrl>

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
 
class PhotoDown : public QObject
{
    Q_OBJECT
    public:
        explicit PhotoDown(QObject *parent = 0);
        virtual ~PhotoDown();
        
        void setFile(QString fileURL, QString name, QString subdir);
        
 
    signals:
        // void downloaded(QString name);
        void transfer(QString trans);
        void done();        // download + write
        
    private slots:
        void onDownloadProgress(qint64,qint64);
        void onFinished(QNetworkReply*);
        void onReadyRead();
        void onReplyFinished();
 
    private:
        QNetworkAccessManager *manager;
        QNetworkReply *reply;
        QFile *file;
        QString m_name;
};
 
#endif 
