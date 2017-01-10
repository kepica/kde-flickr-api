#ifndef FAVORITES_H
#define FAVORITES_H
 
#include <QObject>

 
class Favorites : public QObject
{
    Q_OBJECT
    
    public:
        Favorites(QWidget *parent=0);
        virtual ~Favorites() {};
         
        QString m_id;
        QString m_owner;
        QString m_ownername;
        QString m_secret;
        QString m_server;
        QString m_farm;
        QString m_title;
        QString m_tags;
        QString m_pub;
        QString m_date;
        QString m_dateupload;
        
        
        
    public slots:
        
        void test();
        
    private slots:
        
        
    private:
        
        
       
};
 
#endif




