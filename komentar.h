#ifndef KOMENTAR_H
#define KOMENTAR_H
 
#include <QObject>

 
class Komentar : public QObject
{
    Q_OBJECT
    
    public:
        Komentar(QWidget *parent=0);
        virtual ~Komentar() {};
         
        QString m_id;
        QString m_author;
        QString m_author_is_deleted;
        QString m_author_name;
        QString m_iconserver;
        QString m_iconfarm;
        QString m_datecreate;
        QString m_permalink;
        QString m_path_alias;
        QString m_realname;
        QString m_tekst;
        
    public slots:
        
        void test();
        
    private slots:
        
        
    private:
        
        
       
};
 
#endif



