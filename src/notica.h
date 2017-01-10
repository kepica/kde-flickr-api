#ifndef NOTICA_H
#define NOTICA_H
 
#include <kpassivepopup.h>

class KPassivePopup;
 
class Notica : public KPassivePopup
{
    Q_OBJECT
    
    public:
        Notica(QWidget *parent=0);
        virtual ~Notica() {};
         
    public slots:
        void staviPopup();
        
        
    private:
        
        
       
};
 
#endif


