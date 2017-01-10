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
#include <QStandardItemModel>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>


#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

#include "linesearch.h"
#include "mainwindow.h"
#include "people.h"

LineSearch *lin_id;
QCalendarWidget *dat_1;
QCalendarWidget *dat_2;
QCheckBox *opt1;
QCheckBox *opt2;

QSettings *p_set;
MainWindow *m_win;
   

People::People(QWidget *parent, QSettings *mset) : QDialog(parent)
{
    m_win = (MainWindow*) parent;
    p_set = mset;
    
    QStringList group_list;
    
    int i_ind = 0;
    QSqlQuery m_ery;
    m_ery.prepare("SELECT id,name FROM people WHERE 1");
    if ( m_ery.exec() )
    {
        
        int i_id, i_name;
        i_id = m_ery.record().indexOf("id");
        i_name = m_ery.record().indexOf("name");
    
        while (m_ery.next())
        {
            
            
            QString id = m_ery.value(i_id).toString();
            QString name = m_ery.value(i_name).toString();
            QString pokaz = id + " " + name;
            
            group_list.append(pokaz);
            i_ind++;
        }
    }
    else
    {
        qDebug() << " db error " << m_ery.lastError();
    }
    
    QGridLayout* topGrid = new QGridLayout;
    
    // ----------------------------------------------------- basic settings
    
    QLabel *lab_id = new QLabel(i18n("Flickr user ID: "));
    
    lin_id = new LineSearch(group_list);
    
    // QString mes3 = p_set->value("last_user_id", "none").toString();
    // lin_id->setMaximumWidth(340);
    // lin_id->setText(mes3) ;  
    
    // m_win->user_id = mes3;
    QPushButton* btn1;
    btn1 = new QPushButton("Apply");
    // btn1->setVisible(false);
    connect(btn1, SIGNAL( clicked()), this, SLOT(set_id()));
    
    QHBoxLayout* h1Layout = new QHBoxLayout;
    h1Layout->addWidget(lab_id);
    h1Layout->addWidget(lin_id);
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
    
    // --- not saving date, but string (long) unix timestamp, this is usless
    // mset.value("last_date_from", "none").value<QDate>()
    
    QString mes4 = p_set->value("last_date_to", "none").toString();
    QString mes5 = p_set->value("last_date_from", "none").toString();
    
    qint64 unix_from = mes5.toLong();
    qint64 unix_to = mes4.toLong();
    
    QDateTime date1;
    date1.setTime_t(unix_from);
    QDateTime date2;
    date2.setTime_t(unix_to);
    
    QDate m_dat_from = QDate(date1.date());
    QDate m_dat_to = QDate(date2.date());
    
    // qDebug() << m_dat_from << m_dat_to;
    
    dat_1 = new QCalendarWidget();
    dat_1->setSelectedDate( m_dat_from );
    dat_1->setFixedSize(250,280);
    dat_1->setFirstDayOfWeek(Qt::Monday);
    dat_2 = new QCalendarWidget();
    dat_2->setSelectedDate( m_dat_to );
    dat_2->setFixedSize(250,280);
    dat_2->setFirstDayOfWeek(Qt::Monday);
    
    connect( dat_1, SIGNAL (selectionChanged()) , this, SLOT( set_date_from()) );
    connect( dat_2, SIGNAL (selectionChanged()) , this, SLOT( set_date_to()) );
    
    QHBoxLayout* h3Layout = new QHBoxLayout;
    h3Layout->addWidget(lab_dte1);
    h3Layout->addWidget(lab_dte2);
    
    
    QHBoxLayout* h4Layout = new QHBoxLayout;
    h4Layout->addWidget(dat_1);
    h4Layout->addWidget(dat_2);
    
    midGrid->addLayout(h3Layout,0,0);
    midGrid->addLayout(h4Layout,1,0);
    
    QGroupBox *frame2 = new QGroupBox();
    frame2->setFixedSize(600,370);
    // frame2->setTitle(i18n("Search arguments"));
	frame2->setLayout(midGrid);
    
    // ----------------------------------------------- download Size
    
    // QButtonGroup grp1;
    
    QString suf = p_set->value("img_sufix").toString();  
    m_win->img_sufix = suf;

    opt1 = new QCheckBox(i18n("_z suffix, picture size  640 x Y"), this);
    opt2 = new QCheckBox(i18n("_b suffix, picture size 1024 x Y"), this);
    
    int flag = QString::compare(suf, "_z");
    // qDebug() << "sufix " << stat << "if " << flag;
    
    if (flag == 0)
    {
        opt1->setCheckState(Qt::Checked);
        opt2->setCheckState(Qt::Unchecked);
    }
    else
    {
        opt1->setCheckState(Qt::Unchecked);
        opt2->setCheckState(Qt::Checked);
    }   
    
    connect( opt1, SIGNAL (stateChanged(int)) , this, SLOT( set_img_z(int)) );
    connect( opt2, SIGNAL (stateChanged(int)) , this, SLOT( set_img_b(int)) );
    
    // grp1.addButton(opt1);
    // grp1.addButton(opt2);

    QVBoxLayout* v1Layout = new QVBoxLayout;
    v1Layout->addWidget(opt1);
    v1Layout->addWidget(opt2);
    
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
    setWindowTitle(QString("Search Photos by user_ID ")) ;
}

void People::slot_close()
{
    this->close();
}

                                                   
void People::set_id()
{
    QString str = lin_id->text(); 
    QStringList list1 = str.split(" ");
    select_id = list1[0];
    
    lin_id->disableSearch();
    lin_id->setEnabled(false);
    
    m_win->user_id = select_id;
    lin_id->setText(select_id);
    p_set->setValue("last_user_id", select_id);
    // qDebug() << select_id;
}


void People::set_date_from()
{
    QDate date1 = dat_1->selectedDate();
    QDateTime dt1 = QDateTime(date1);
    long timestamp1 = dt1.toTime_t();
    QString mstr1 = QString::number(timestamp1);
    
    m_win->date_from = mstr1;
    p_set->setValue("last_date_from", mstr1);
}

void People::set_date_to()
{
    QDate date2 = dat_2->selectedDate();
    QDateTime dt2 = QDateTime(date2);
    long timestamp2 = dt2.toTime_t();
    QString mstr2 = QString::number(timestamp2);
    
    m_win->date_to = mstr2;
    p_set->setValue("last_date_to", mstr2);
}

void People::set_img_z(int state)
{
    // opt1 _z check / Unchecked
    QString m_su;
    if (state == 0)
    {
        opt2->setCheckState(Qt::Checked);
        m_su = "_b";
    }
    else if (state == 2)
    {
        opt2->setCheckState(Qt::Unchecked);
        m_su = "_z";
    }
    m_win->img_sufix = m_su;
    p_set->setValue("img_sufix", m_su);
}

void People::set_img_b(int state)
{
    // opt2 _b check / Unchecked
    QString m_su;
    if (state == 0)
    {
        opt1->setCheckState(Qt::Checked);
        m_su = "_z";
    }
    else if (state == 2)
    {
        opt1->setCheckState(Qt::Unchecked);
        m_su = "_b";
    }
    m_win->img_sufix = m_su;
    p_set->setValue("img_sufix", m_su);
}

void People::get_photos()
{
    // qint64 unixtime_sada = QDateTime::currentMSecsSinceEpoch()/1000;
    // qint64 unixtime_prije = unixtime_sada - 7 * 86400;
    m_win->get_reply(1);  // 1- people
}
/*
void People::on_Activated(const QModelIndex &index)
{
    int row = index.row();
    select_id = completer->completionModel()->index(row, 1).data().toString();
    btn1->setVisible(true);
    // qDebug() << select_id;
}
void People::on_Edited(const QString &text)
{
    if (text.isEmpty())
    {
        btn1->setVisible(false);
    }
}
*/
