#ifndef GROUPS_H
#define GROUPS_H
 
#include <QDialog>

class QSettings;

class Groups : public QDialog
{
    Q_OBJECT
    
    public:
        Groups(QWidget *parent=0, QSettings *mset=0);
        virtual ~Groups() {};
        

public Q_SLOTS:
       
    
private Q_SLOTS:

        void set_id();
        void set_date_from();
        void set_date_to();
        void set_img_z(int state);
        void set_img_b(int state);
        void slot_close();
        void get_photos();
        
        
    private:
    
    
};
 
#endif



