#ifndef MAUTH_H
#define MAUTH_H
 
#include <QObject>

class QSettings;
class O1Requestor;
 
class Mauth : public QObject
{
    Q_OBJECT
    
    public:
        Mauth(QWidget *parent=0, QSettings *mset=0, O1Requestor *o1req=0);
        virtual ~Mauth() {};
        
        
    public Q_SLOTS:
        
        void activity_comments();
        void photo_comments();
        void get_favorites();
        
        // void print_osobne();
        // void print_tagirane();
        void stats_photo();
        void stats_suma();
        void test_echo();
        void test_login();
    
   
        
    private slots:
       
        void flikResponse();
        void flikComments();
        void flikFavorites();
        
        void respStatSuma();
        void respStatPhoto();
        void loadImage();
        
    private:
        
        
       
};
 
#endif


