#ifndef DBLITE_H
#define DBLITE_H
 
#include <QObject>

 
class DBlite : public QObject
{
    Q_OBJECT
    
    public:
        DBlite(const QString &path=0);
        virtual ~DBlite();
        
        bool isOpen() const;
        
        bool addPhoto(const QString &id, const QString &owner, const QString &secret, const QString &server,
                      const QString &farm, const QString &title, const QString &tags, const QString &dateupload, 
                      const QString &ownernme);
        
        bool addTagirane(const QString &id, const QString &owner, const QString &secret, const QString &server,
                      const QString &farm, const QString &title, const QString &ownernme);
        
        bool addPeople(const QString &id, const QString &name, const QString &nick, const QString &server);
        
        bool removePhoto(const QString &id);
        
        bool removeAllPhoto();
        bool removeAllTagirane();
        
        bool photoExists(const QString &id) const;
        bool userExists(const QString &id) const;
        
        void printPhotos() const;
        void printTagirane() const;
        
         
public Q_SLOTS:
        
        
    private slots:
        
    private:
        
        
        
        
       
};
 
#endif



