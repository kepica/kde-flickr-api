#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <KXmlGuiWindow>


class KTextEdit;
 
class MainWindow : public KXmlGuiWindow
{
    public:
        MainWindow(QWidget *parent=0);
        
        QString poruka;
        // int koji_kveri;
        
    private:
       // KTextEdit *textArea;
        
        void setupActions();
        
    
};
 
#endif
