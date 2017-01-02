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
        QString tag;
        QString savePath;
        QString pic_dir;
        QString user_id;
        QString date_from;
        QString date_to;
        QString img_sufix;

        void get_reply(int koji);
        
        // ---------- db helper
        
        bool add_Photo(const QString &id, const QString &owner, const QString &secret, const QString &server,
                      const QString &farm, const QString &title, const QString &tags, const QString &dateupload, 
                      const QString &ownernme);
       
        
        // ---------- db helper end
        

public Q_SLOTS:
        void down_start(QString url, QString id, QString name, int koji);
    
private Q_SLOTS:
    
        void onLinkedChanged(); 
        void onLinkingFailed(); 
        void onLinkingSucceeded(); 
        void onOpenBrowser(const QUrl &url); 
        void onCloseBrowser(); 
        
        void down_done();
        void down_transfer(QString str);

        void set_postavke();
        void search_people();
        void parse_people();
        void friend_list();
        void parse_friend();
        
    private:
       
        KTextEdit *textArea;
        void setupActions();
    
};
 
#endif
