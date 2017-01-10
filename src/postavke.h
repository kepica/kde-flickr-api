#ifndef POSTAVKE_H
#define POSTAVKE_H
 
#include <QDialog>

class QSettings;
 
class Postavke : public QDialog
{
    Q_OBJECT
    
    public:
        Postavke(QWidget *parent=0, QSettings *mset=0);
        virtual ~Postavke() {};
        
        // QString poruka;
        // QString tag;
        // QString savePath;
        // QString date_from;
        // QString date_to;
        

public Q_SLOTS:
       
    
private Q_SLOTS:
        void set_root();
        void set_myid();
        void set_date();
        void slot_close();
        
        
    private:
    
        
    
};
 
#endif

