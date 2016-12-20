#ifndef PHOTODOWN_H
#define PHOTODOWN_H
 
#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
 
class PhotoDown : public QObject
{
    Q_OBJECT
    public:
        explicit PhotoDown(QUrl imageUrl, QObject *parent = 0);
        virtual ~PhotoDown();
        
        QByteArray downloadedData() const;
 
    signals:
        void downloaded();
 
    private slots:
        void fileDownloaded(QNetworkReply* pReply);
 
    private:
        QNetworkAccessManager m_WebCtrl;
        QByteArray m_DownloadedData;
};
 
#endif 
