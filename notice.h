#ifndef NOTICE_H
#define NOTICE_H
 
#include <kstatusnotifieritem.h>

class KStatusNotifierItem;
 
class Notice : public KStatusNotifierItem
{
    Q_OBJECT
    
    public:
        Notice(QWidget *parent=0);
        virtual ~Notice() {};
         
    public slots:
        void staviNotice();
// QString &mstr
        
        
    private:
        
        
       
};
 
#endif

