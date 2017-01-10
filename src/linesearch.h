#ifndef LINESEARCH_H
#define LINESEARCH_H
 
#include <QLineEdit>

class QFocusEvent;
class QStringList;
class QString;

class LineSearch : public QLineEdit
{
    Q_OBJECT
    
    public:
        LineSearch(QStringList words, QWidget *parent=0);
        virtual ~LineSearch() {};
        
        void disableSearch();
        
public Q_SLOTS:
       
        
        void setCompleter(const QString &text);
        void completeText(const QModelIndex &index);
        // QStringList filteredModelFromText(const QString &text);
        
protected:
    
        void focusOutEvent(QFocusEvent *e);
        void keyPressEvent(QKeyEvent *e);
        
private Q_SLOTS:

        
        
    private:
        QStringList m_list;
        bool search_disabled;
};
 
#endif



