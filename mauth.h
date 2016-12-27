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
        void search_tags();
        void print_osobne();
        void print_tagirane();
        void stats_photo();
        void stats_suma();
        void test_echo();
        void test_login();
    
    Q_SIGNALS:
        
        void o1_linked(bool flag);
        
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
        void searchTags();
        void respStatSuma();
        void respStatPhoto();
        void loadImage();
        
    private:
        
        
       
};
 
#endif


