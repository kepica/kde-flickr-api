#ifndef WELCOME_H
#define WELCOME_H
 
#include <QDialog>

 
class Welcome : public QDialog
{
    Q_OBJECT
    
    public:
        Welcome(int koji=0);
        virtual ~Welcome() {};
        
        
        
    private slots:
        void slot_accept();
        
    private:
        
        
        
        
       
};
 
#endif




