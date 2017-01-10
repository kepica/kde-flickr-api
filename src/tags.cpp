
#include <QApplication>
#include <QAction>
#include <QSettings>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCompleter>
#include <QDebug>


#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>


#include "mainwindow.h"
#include "tags.h"

QLineEdit *t_lin_id;
QCalendarWidget *t_dat_1;
QCalendarWidget *t_dat_2;
QCheckBox *t_opt1;
QCheckBox *t_opt2;

QSettings *t_set;
MainWindow *t_win;
   

Tags::Tags(QWidget *parent, QSettings *mset) : QDialog(parent)
{
    t_win = (MainWindow*) parent;
    t_set = mset;
    
    /*
    QStringList id_list;
    
    QSqlQuery m_ery;
    m_ery.prepare("SELECT id,name FROM people WHERE 1");
    if ( m_ery.exec() )
    {
        int i_id, i_name;
        i_id = m_ery.record().indexOf("id");
        i_name = m_ery.record().indexOf("name");
        // qDebug() << "id " << i_id << " mame " << i_name;
    
        while (m_ery.next())
        {
            QString id = m_ery.value(i_id).toString();
            QString name = m_ery.value(i_name).toString();
            // qDebug() << id << name;
            id_list.append(id+" "+name);
        }
    }
    else
    {
        qDebug() << " db error " << m_ery.lastError();
    }
    
    // qDebug() << id_list;
    */
    
    
    
    QGridLayout* topGrid = new QGridLayout;
    
    // ----------------------------------------------------- basic settings
    
    QLabel *lab_id = new QLabel(i18n("Flickr photo tags: "));
    
    QString mes3 = t_set->value("last_img_tag", "none").toString();
    t_win->img_tag = mes3;
    
    t_lin_id = new QLineEdit();
    t_lin_id->setMaximumWidth(340);
    t_lin_id->setText(mes3) ;
    // t_lin_id->setInputMask("000000000A99");
    
    
    // QCompleter *completer = new QCompleter(id_list, this);
    // completer->setCaseSensitivity(Qt::CaseInsensitive);
    // t_lin_id->setCompleter(completer);

    QPushButton* btn1;
    btn1 = new QPushButton("Apply");
    connect(btn1, SIGNAL( clicked()), this, SLOT(set_tag()));
    // connect(t_lin_id, SIGNAL(editingFinished()), this, SLOT(set_tag()));
    
    QHBoxLayout* h1Layout = new QHBoxLayout;
    h1Layout->addWidget(lab_id);
    h1Layout->addWidget(t_lin_id);
    h1Layout->addWidget(btn1);
    
    topGrid->addLayout(h1Layout,0,0);
    
    QGroupBox *frame1 = new QGroupBox();
    frame1->setFixedSize(600,110);
    //  frame1->setTitle(i18n("Flickr user-ID"));
	frame1->setLayout(topGrid);

    // ------------------------------------------------- Search options
    
    QGridLayout* midGrid = new QGridLayout;
        
    QLabel *lab_dte1 = new QLabel(i18n("From date: "));
    QLabel *lab_dte2 = new QLabel(i18n("To date: "));
    
    QString mes4 = t_set->value("last_date_to", "none").toString();
    QString mes5 = t_set->value("last_date_from", "none").toString();
    
    qint64 unix_from = mes5.toLong();
    qint64 unix_to = mes4.toLong();
    
    QDateTime date1;
    date1.setTime_t(unix_from);
    QDateTime date2;
    date2.setTime_t(unix_to);
    
    QDate m_dat_from = QDate(date1.date());
    QDate m_dat_to = QDate(date2.date());
    
    // qDebug() << m_dat_from << m_dat_to;
    
    t_dat_1 = new QCalendarWidget();
    t_dat_1->setSelectedDate( m_dat_from );
    t_dat_1->setFixedSize(250,280);
    t_dat_1->setFirstDayOfWeek(Qt::Monday);
    t_dat_2 = new QCalendarWidget();
    t_dat_2->setSelectedDate( m_dat_to );
    t_dat_2->setFixedSize(250,280);
    t_dat_2->setFirstDayOfWeek(Qt::Monday);
    
    connect( t_dat_1, SIGNAL (selectionChanged()) , this, SLOT( set_date_from()) );
    connect( t_dat_2, SIGNAL (selectionChanged()) , this, SLOT( set_date_to()) );
    
    QHBoxLayout* h3Layout = new QHBoxLayout;
    h3Layout->addWidget(lab_dte1);
    h3Layout->addWidget(lab_dte2);
    
    
    QHBoxLayout* h4Layout = new QHBoxLayout;
    h4Layout->addWidget(t_dat_1);
    h4Layout->addWidget(t_dat_2);
    
    midGrid->addLayout(h3Layout,0,0);
    midGrid->addLayout(h4Layout,1,0);
    
    QGroupBox *frame2 = new QGroupBox();
    frame2->setFixedSize(600,370);
    // frame2->setTitle(i18n("Search arguments"));
	frame2->setLayout(midGrid);
    
    // ----------------------------------------------- download Size
    
    // QButtonGroup grp1;
    
    QString suf = t_set->value("img_sufix").toString();  
    t_win->img_sufix = suf;

    t_opt1 = new QCheckBox(i18n("_z suffix, picture size  640 x Y"), this);
    t_opt2 = new QCheckBox(i18n("_b suffix, picture size 1024 x Y"), this);
    
    int flag = QString::compare(suf, "_z");
    // qDebug() << "sufix " << stat << "if " << flag;
    
    if (flag == 0)
    {
        t_opt1->setCheckState(Qt::Checked);
        t_opt2->setCheckState(Qt::Unchecked);
    }
    else
    {
        t_opt1->setCheckState(Qt::Unchecked);
        t_opt2->setCheckState(Qt::Checked);
    }   
    
    connect( t_opt1, SIGNAL (stateChanged(int)) , this, SLOT( set_img_z(int)) );
    connect( t_opt2, SIGNAL (stateChanged(int)) , this, SLOT( set_img_b(int)) );
    
    // grp1.addButton(opt1);
    // grp1.addButton(opt2);

    QVBoxLayout* v1Layout = new QVBoxLayout;
    v1Layout->addWidget(t_opt1);
    v1Layout->addWidget(t_opt2);
    
    QGroupBox *frame3 = new QGroupBox();
    frame3->setFixedSize(600,100);
    // frame3->setTitle(i18n("Image size"));
	frame3->setLayout(v1Layout);
    
    // ---------------------------------------  Go !
    
    
    QHBoxLayout* h7Layout = new QHBoxLayout;
    
    QPushButton* btn7;
    btn7 = new QPushButton("Close");
    connect(btn7, SIGNAL(clicked()), this, SLOT(slot_close()));
    
    QPushButton* btn8;
    btn8 = new QPushButton("Start search");
    connect(btn8, SIGNAL(clicked()), this, SLOT( get_photos() ) );    // start search
    QLabel *lab1 = new QLabel();

    h7Layout->addWidget(btn7);
    h7Layout->addWidget(lab1);
    h7Layout->addWidget(btn8);
    
    QGroupBox *frame4 = new QGroupBox();
    frame4->setFixedSize(600,50);
    // frame4->setTitle(i18n("naslov"));
	frame4->setLayout(h7Layout);
    
    QVBoxLayout* mainGrid = new QVBoxLayout;
    
    mainGrid->addWidget((QWidget*) frame1);
    mainGrid->addWidget((QWidget*) frame2);
    mainGrid->addWidget((QWidget*) frame3);
    mainGrid->addWidget((QWidget*) frame4);
 
    setLayout(mainGrid);
    setWindowTitle(QString("Search Photos by Tags ")) ;
}

void Tags::slot_close()
{
    this->close();
}

                                                    
void Tags::set_tag()
{
    QString m_tag = t_lin_id->text();    
    t_win->img_tag = m_tag;
    t_set->setValue("last_img_tag", m_tag);
}

void Tags::set_date_from()
{
    QDate date1 = t_dat_1->selectedDate();
    QDateTime dt1 = QDateTime(date1);
    long timestamp1 = dt1.toTime_t();
    QString mstr1 = QString::number(timestamp1);
    
    t_win->date_from = mstr1;
    t_set->setValue("last_date_from", mstr1);
}

void Tags::set_date_to()
{
    QDate date2 = t_dat_2->selectedDate();
    QDateTime dt2 = QDateTime(date2);
    long timestamp2 = dt2.toTime_t();
    QString mstr2 = QString::number(timestamp2);
    
    t_win->date_to = mstr2;
    t_set->setValue("last_date_to", mstr2);
}

void Tags::set_img_z(int state)
{
    // opt1 _z check / Unchecked
    QString m_su;
    if (state == 0)
    {
        t_opt2->setCheckState(Qt::Checked);
        m_su = "_b";
    }
    else if (state == 2)
    {
        t_opt2->setCheckState(Qt::Unchecked);
        m_su = "_z";
    }
    t_win->img_sufix = m_su;
    t_set->setValue("img_sufix", m_su);
}

void Tags::set_img_b(int state)
{
    // opt2 _b check / Unchecked
    QString m_su;
    if (state == 0)
    {
        t_opt1->setCheckState(Qt::Checked);
        m_su = "_z";
    }
    else if (state == 2)
    {
        t_opt1->setCheckState(Qt::Unchecked);
        m_su = "_b";
    }
    t_win->img_sufix = m_su;
    t_set->setValue("img_sufix", m_su);
}

void Tags::get_photos()
{
    t_win->get_reply(2);  // 2- tags
}


