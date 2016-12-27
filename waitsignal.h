#ifndef WAITSIGNAL_H
#define WAITSIGNAL_H
 
#include <QObject>

 
class WaitSignal : public QObject
{
    Q_OBJECT
    
    public:
        WaitSignal(QObject *object=0, const char *signal=0);
        virtual ~WaitSignal() {};
         
        bool wait(int ms);
        
public Q_SLOTS:
        
        void timeout();
        
    private:
        
        bool b_flag;

       
};
 
#endif



