#ifndef MAUTH_H
#define MAUTH_H
 
#include <QObject>

 
class Mauth : public QObject
{
    Q_OBJECT
    
    public:
        Mauth(QWidget *parent=0);
        virtual ~Mauth() {};
         
public Q_SLOTS:
        
        void lnk();
        void ulnk();
        void activity_comments();
        void photo_comments();
        void get_favorites();
        void get_osobne();
        void print_osobne();
        void stats_photo();
        void stats_suma();
        void test_echo();
        void test_login();
        
    private slots:
        void onLinkedChanged(); 
        void onLinkingFailed(); 
        void onLinkingSucceeded(); 
        void onOpenBrowser(const QUrl &url); 
        void onCloseBrowser(); 
        void flikResponse();
        void flikComments();
        void flikFavorites();
        void flikPersonal();
        void respStatSuma();
        void respStatPhoto();
        void loadImage();
        
    private:
        
        
       
};
 
#endif


