#ifndef PEOPLE_H
#define PEOPLE_H
 
#include <QDialog>

class QSettings;

class People : public QDialog
{
    Q_OBJECT
    
    public:
        People(QWidget *parent=0, QSettings *mset=0);
        virtual ~People() {};
        

public Q_SLOTS:
       
    
private Q_SLOTS:

        void set_id();
        void set_date_from();
        void set_date_to();
        void set_img_z(int state);
        void set_img_b(int state);
        void slot_close();
        void get_people();
        
        
    private:
    
    
};
 
#endif


