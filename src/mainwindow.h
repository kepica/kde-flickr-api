#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <KXmlGuiWindow>

class KTextEdit;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent=0);
        virtual ~MainWindow() {};
        
        QString o1_key;
        QString o1_secret;
    
        QString poruka;
        QString img_tag;
        QString savePath;
        QString img_dir;
        QString img_license;
        QString user_id;
        QString group_id;
        QString group_name;
        QString date_from;
        QString date_to;
        QString img_sufix;

        void get_reply(int koji);
        
     

public Q_SLOTS:
        void down_start(QString url, QString dir, QString name, int koji);
    
private Q_SLOTS:
    
        void onLinkedChanged(); 
        void onLinkingFailed(); 
        void onLinkingSucceeded(); 
        void onOpenBrowser(const QUrl &url); 
        void onCloseBrowser(); 
        
        void down_done();
        void down_transfer(QString str);
        
        void test_echo();
        void panda_ling();
        void panda_hsing();
        void panda_wang();
        void get_interest();

        void set_postavke();
        void search_people();
        void search_tags();
        void search_pools();
        void search_groups();
        
        void parse_photo();
        
        void friend_list();
        void groups_list();
        void parse_friend();
        void parse_groups_id();
        void parse_echo();
        
    private:
       
        KTextEdit *textArea;
        void setupActions();
        
        int photo_search;
    
};
 
#endif
