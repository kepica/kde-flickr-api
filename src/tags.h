#ifndef TAGS_H
#define TAGS_H
 
#include <QDialog>

class QSettings;

class Tags : public QDialog
{
    Q_OBJECT
    
    public:
        Tags(QWidget *parent=0, QSettings *mset=0);
        virtual ~Tags() {};
        

public Q_SLOTS:
       
    
private Q_SLOTS:

        void set_tag();
        void set_date_from();
        void set_date_to();
        void set_img_z(int state);
        void set_img_b(int state);
        void slot_close();
        void get_photos();
        
        
    private:
    
    
};
 
#endif


