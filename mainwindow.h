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
        
        QString poruka;
        QString tag;
        QString savePath;
        QString date_from;
        QString date_to;
        

public Q_SLOTS:
        void down_start(QString url, QString name);
    
private Q_SLOTS:
        
        void oauth_link(bool flag);
        void down_done();
        void down_transfer(QString str);
        // void down_down(QString name);
        
        
    private:
       
        KTextEdit *textArea;
        void setupActions();
        
    
};
 
#endif
