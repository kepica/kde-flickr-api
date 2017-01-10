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

#include "linesearch.h"
#include "mainwindow.h"
#include "groups.h"

LineSearch *g_lin_id;
QCalendarWidget *g_dat_1;
QCalendarWidget *g_dat_2;
QCheckBox *g_opt1;
QCheckBox *g_opt2;
// QLabel *loc_dir;

QSettings *g_set;
MainWindow *g_win;
   

Groups::Groups(QWidget *parent, QSettings *mset) : QDialog(parent)
{
    g_win = (MainWindow*) parent;
    g_set = mset;
    
    
    QStringList id_list;
    
    QSqlQuery m_ery;
    m_ery.prepare("SELECT id,name FROM groups WHERE 1");
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
    
    
    
    
    QGridLayout* topGrid = new QGridLayout;
    
    // ----------------------------------------------------- basic settings
    
    QLabel *lab_id = new QLabel(i18n("Flickr group ID: "));
    // QLabel *lab_dir = new QLabel(i18n("Local folder name: "));
    
    g_lin_id = new LineSearch(id_list);
    // g_lin_id->setMaximumWidth(340);
    // g_lin_id->setText(mes3) ;
    // g_win->group_id = mes3;
    
    
    
    QPushButton* btn1;
    btn1 = new QPushButton("Apply");
    connect(btn1, SIGNAL( clicked()), this, SLOT(set_id()));
    // connect(lin_id, SIGNAL(editingFinished()), this, SLOT(set_id()));
    
    QHBoxLayout* h1Layout = new QHBoxLayout;
    h1Layout->addWidget(lab_id);
    h1Layout->addWidget(g_lin_id);
    h1Layout->addWidget(btn1);
    
    
    topGrid->addLayout(h1Layout,0,0);
    // topGrid->addLayout(h2Layout,1,0);
    
    QGroupBox *frame1 = new QGroupBox();
    frame1->setFixedSize(600,110);
    //  frame1->setTitle(i18n("Flickr user-ID"));
	frame1->setLayout(topGrid);

    // ------------------------------------------------- Search options
    
    QGridLayout* midGrid = new QGridLayout;
        
    QLabel *lab_dte1 = new QLabel(i18n("From date: "));
    QLabel *lab_dte2 = new QLabel(i18n("To date: "));
    
    // --- not saving date, but string (long) unix timestamp, this is usless
    // mset.value("last_date_from", "none").value<QDate>()
    
    QString mes4 = g_set->value("last_date_to", "none").toString();
    QString mes5 = g_set->value("last_date_from", "none").toString();
    
    qint64 unix_from = mes5.toLong();
    qint64 unix_to = mes4.toLong();
    
    QDateTime date1;
    date1.setTime_t(unix_from);
    QDateTime date2;
    date2.setTime_t(unix_to);
    
    QDate m_dat_from = QDate(date1.date());
    QDate m_dat_to = QDate(date2.date());
    
    // qDebug() << m_dat_from << m_dat_to;
    
    g_dat_1 = new QCalendarWidget();
    g_dat_1->setSelectedDate( m_dat_from );
    g_dat_1->setFixedSize(250,280);
    g_dat_1->setFirstDayOfWeek(Qt::Monday);
    g_dat_2 = new QCalendarWidget();
    g_dat_2->setSelectedDate( m_dat_to );
    g_dat_2->setFixedSize(250,280);
    g_dat_2->setFirstDayOfWeek(Qt::Monday);
    
    connect( g_dat_1, SIGNAL (selectionChanged()) , this, SLOT( set_date_from()) );
    connect( g_dat_2, SIGNAL (selectionChanged()) , this, SLOT( set_date_to()) );
    
    QHBoxLayout* h3Layout = new QHBoxLayout;
    h3Layout->addWidget(lab_dte1);
    h3Layout->addWidget(lab_dte2);
    
    
    QHBoxLayout* h4Layout = new QHBoxLayout;
    h4Layout->addWidget(g_dat_1);
    h4Layout->addWidget(g_dat_2);
    
    midGrid->addLayout(h3Layout,0,0);
    midGrid->addLayout(h4Layout,1,0);
    
    QGroupBox *frame2 = new QGroupBox();
    frame2->setFixedSize(600,370);
    // frame2->setTitle(i18n("Search arguments"));
	frame2->setLayout(midGrid);
    
    // ----------------------------------------------- download Size
    
    // QButtonGroup grp1;
    
    QString suf = g_set->value("img_sufix").toString();  
    g_win->img_sufix = suf;

    g_opt1 = new QCheckBox(i18n("_z suffix, picture size  640 x Y"), this);
    g_opt2 = new QCheckBox(i18n("_b suffix, picture size 1024 x Y"), this);
    
    int flag = QString::compare(suf, "_z");
    // qDebug() << "sufix " << stat << "if " << flag;
    
    if (flag == 0)
    {
        g_opt1->setCheckState(Qt::Checked);
        g_opt2->setCheckState(Qt::Unchecked);
    }
    else
    {
        g_opt1->setCheckState(Qt::Unchecked);
        g_opt2->setCheckState(Qt::Checked);
    }   
    
    connect( g_opt1, SIGNAL (stateChanged(int)) , this, SLOT( set_img_z(int)) );
    connect( g_opt2, SIGNAL (stateChanged(int)) , this, SLOT( set_img_b(int)) );
    
    // grp1.addButton(opt1);
    // grp1.addButton(opt2);

    QVBoxLayout* v1Layout = new QVBoxLayout;
    v1Layout->addWidget(g_opt1);
    v1Layout->addWidget(g_opt2);
    
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
    setWindowTitle(QString("Search Photos by group_ID ")) ;
}

void Groups::slot_close()
{
    this->close();
}

                                                    
void Groups::set_id()
{
    QString str = g_lin_id->text();    
    QStringList list = str.split(" ");
    
    // QString m_dir;
    // QString m_str;
    QString m_id = list.at(0);
    /*
    for (int i = 1; i < list.size(); ++i)
    {
        m_str = list.at(i);
        m_dir += m_str;
    }
    m_dir.remove( QRegExp("[^\\w]") );
    if (m_dir.length() > 24)
        m_dir = m_dir.left(24);
    */
    
    g_lin_id->disableSearch();
    g_lin_id->setEnabled(false);
    
    g_win->group_id = m_id;
    g_lin_id->setText(m_id);
    g_set->setValue("last_group_id", m_id);
}

void Groups::set_date_from()
{
    QDate date1 = g_dat_1->selectedDate();
    QDateTime dt1 = QDateTime(date1);
    long timestamp1 = dt1.toTime_t();
    QString mstr1 = QString::number(timestamp1);
    
    g_win->date_from = mstr1;
    g_set->setValue("last_date_from", mstr1);
}

void Groups::set_date_to()
{
    QDate date2 = g_dat_2->selectedDate();
    QDateTime dt2 = QDateTime(date2);
    long timestamp2 = dt2.toTime_t();
    QString mstr2 = QString::number(timestamp2);
    
    g_win->date_to = mstr2;
    g_set->setValue("last_date_to", mstr2);
}

void Groups::set_img_z(int state)
{
    // opt1 _z check / Unchecked
    QString m_su;
    if (state == 0)
    {
        g_opt2->setCheckState(Qt::Checked);
        m_su = "_b";
    }
    else if (state == 2)
    {
        g_opt2->setCheckState(Qt::Unchecked);
        m_su = "_z";
    }
    g_win->img_sufix = m_su;
    g_set->setValue("img_sufix", m_su);
}

void Groups::set_img_b(int state)
{
    // opt2 _b check / Unchecked
    QString m_su;
    if (state == 0)
    {
        g_opt1->setCheckState(Qt::Checked);
        m_su = "_z";
    }
    else if (state == 2)
    {
        g_opt1->setCheckState(Qt::Unchecked);
        m_su = "_b";
    }
    g_win->img_sufix = m_su;
    g_set->setValue("img_sufix", m_su);
}

void Groups::get_photos()
{
    g_win->get_reply(4);  // 4- groups
}



