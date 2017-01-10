#include <QApplication>
#include <QAction>
#include <QEventLoop>
#include <QDir>
#include <QFileDialog>
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
#include <QDebug>

#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>


#include "mainwindow.h"
#include "postavke.h"

MainWindow *prvi;
QLineEdit *line_id;
QLineEdit *line_root;
QCalendarWidget *date_1;
QCalendarWidget *date_2;
QSettings *s_set;

Postavke::Postavke(QWidget *parent, QSettings *mset) : QDialog(parent)
{
    s_set = mset;   // local copy
     
    // ----------------------------------------------------- basic settings
    
    QGridLayout* topGrid = new QGridLayout;
        
    QLabel *lab_id = new QLabel(i18n("Enter your flickr ID: "));
    QLabel *lab_root = new QLabel(i18n("Downloads directory: "));
    
    line_id = new QLineEdit();
    line_id->setMaximumWidth(240);
    line_id->setText(s_set->value("flickr_user_id", "none").toString()) ;
    
    line_root = new QLineEdit();
    line_root->setMinimumWidth(240);
    line_root->setReadOnly(true);
    line_root->setText(s_set->value("pic_root_dir", "none").toString()) ;
    
    QPushButton* btn_id;
    btn_id = new QPushButton("Apply");
    connect(btn_id, SIGNAL(clicked()), this, SLOT(set_myid()));
    
    QPushButton* btn_root;
    btn_root = new QPushButton("Select");
    connect(btn_root, SIGNAL(clicked()), this, SLOT(set_root()));
    
    QHBoxLayout* h1Layout = new QHBoxLayout;
    h1Layout->addWidget(lab_id);
    h1Layout->addWidget(line_id);
    h1Layout->addWidget(btn_id);
    
    QHBoxLayout* h2Layout = new QHBoxLayout;
    h2Layout->addWidget(lab_root);
    h2Layout->addWidget(line_root);
    h2Layout->addWidget(btn_root);

    topGrid->addLayout(h1Layout,0,0);
    topGrid->addLayout(h2Layout,1,0);
   
    QGroupBox *frame1 = new QGroupBox();
    frame1->setFixedSize(600,110);
    frame1->setTitle(i18n("Basic settings"));
	frame1->setLayout(topGrid);

    // ------------------------------------------------- Search options
    
    QGridLayout* midGrid = new QGridLayout;
        
    QLabel *lab_dte1 = new QLabel(i18n("From date: "));
    QLabel *lab_dte2 = new QLabel(i18n("To date: "));
    
    date_1 = new QCalendarWidget();
    date_1->setSelectedDate(s_set->value("search_date_from", "none").value<QDate>() );
    date_1->setFixedSize(250,280);
    
    date_2 = new QCalendarWidget();
    date_2->setSelectedDate(s_set->value("search_date_to", "none").value<QDate>() );
    date_2->setFixedSize(250,280);
    
    QPushButton* btn_dte;
    btn_dte = new QPushButton("Apply");
    connect(btn_dte, SIGNAL(clicked()), this, SLOT(set_date()));
    
    
    QHBoxLayout* h3Layout = new QHBoxLayout;
    h3Layout->addWidget(lab_dte1);
    h3Layout->addWidget(btn_dte);
    h3Layout->addWidget(lab_dte2);
    
    QHBoxLayout* h4Layout = new QHBoxLayout;
    h4Layout->addWidget(date_1);
    h4Layout->addWidget(date_2);
    
    midGrid->addLayout(h3Layout,0,0);
    midGrid->addLayout(h4Layout,1,0);
    
    QGroupBox *frame2 = new QGroupBox();
    frame2->setFixedSize(600,370);
    frame2->setTitle(i18n("Search arguments"));
	frame2->setLayout(midGrid);
    
    // ----------------------------------------------- download Size
    
    QButtonGroup grp1;
    
    QCheckBox *opt1 = new QCheckBox(i18n("_z suffix, picture size  640 x y"), this);
    QCheckBox *opt2 = new QCheckBox(i18n("_b suffix, picture size 1024 x y"), this);
    
    grp1.addButton(opt1);
    grp1.addButton(opt2);

    QVBoxLayout* v1Layout = new QVBoxLayout;
    v1Layout->addWidget(opt1);
    v1Layout->addWidget(opt2);
    
    QGroupBox *frame3 = new QGroupBox();
    frame3->setFixedSize(600,100);
    frame3->setTitle(i18n("Image size"));
	frame3->setLayout(v1Layout);
    
    // ----------------------------------------------------- activity
    
    
    QCheckBox *opt3 = new QCheckBox(i18n("trace comments activity"), this);
    QCheckBox *opt4 = new QCheckBox(i18n("trace group activity"), this);
    QCheckBox *opt5 = new QCheckBox(i18n("trace friend activity"), this);
    QCheckBox *opt6 = new QCheckBox(i18n("trace whatever ..."), this);
    
    QVBoxLayout* v2Layout = new QVBoxLayout;
    v2Layout->addWidget(opt3);
    v2Layout->addWidget(opt4);
    v2Layout->addWidget(opt5);
    v2Layout->addWidget(opt6);
    
    QGroupBox *frame4 = new QGroupBox();
    frame4->setFixedSize(600,160);
    frame4->setTitle(i18n("Activity options"));
	frame4->setLayout(v2Layout);
    
    // ----------------------------------------------------- general
    
    
    QCheckBox *opt11 = new QCheckBox(i18n("disable Welcome dialog"), this);
    QCheckBox *opt12 = new QCheckBox(i18n("something else ..."), this);
    
    QVBoxLayout* v3Layout = new QVBoxLayout;
    v3Layout->addWidget(opt11);
    v3Layout->addWidget(opt12);
    
    QGroupBox *frame5 = new QGroupBox();
    frame5->setFixedSize(600,110);
    frame5->setTitle(i18n("General options"));
	frame5->setLayout(v3Layout);
    
    /*
    QHBoxLayout* h7Layout = new QHBoxLayout;
    QPushButton* btn7;
    btn7 = new QPushButton("Close");
    connect(btn7, SIGNAL(clicked()), this, SLOT(slot_close()));
    QLabel *lab1 = new QLabel();
    QLabel *lab2 = new QLabel();

    h7Layout->addWidget(lab1);
    h7Layout->addWidget(btn7);
    h7Layout->addWidget(lab2);
    */
    QVBoxLayout* mainGrid = new QVBoxLayout;
    
    mainGrid->addWidget((QWidget*) frame1);
    mainGrid->addWidget((QWidget*) frame2);
    mainGrid->addWidget((QWidget*) frame3);
    mainGrid->addWidget((QWidget*) frame4);
    mainGrid->addWidget((QWidget*) frame5);
    // mainGrid->addWidget((QWidget*) h7Layout);
 
    setLayout(mainGrid);
    
  
    prvi = (MainWindow*) parent;
    
    // poruka = i18n("Ona posvuduša je opet stavila sliku na Flickr !");
    // date_from = QString("1477550147");
    // date_to = QString("1480142147");
    // tag = QString("in-explore");
    // savePath = QString("/home/vjeko/slike/")+tag;
    /*
    QDir dir(savePath);
    if ( !dir.exists() )
    {
        dir.mkpath(".");
    }
    */  
    setWindowTitle(QString("Profile Settings ")) ;
}

void Postavke::slot_close()
{
    this->close();
}

void Postavke::set_root()
{
    QString dir = QFileDialog::getExistingDirectory(this, i18n("Select Folder"), 
                                "/home",
                                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    
    line_root->setText(dir);
    prvi->img_dir = dir;
    s_set->setValue("pic_root_dir", dir);
}
                                                    
void Postavke::set_myid()
{
    
    QString m_myid = line_id->text();
    
    prvi->user_id = m_myid;
    s_set->setValue("flickr_user_id", m_myid);
}

void Postavke::set_date()
{
    
    QDate m_dte1 = date_1->selectedDate();
    QString s_dte1 = m_dte1.toString();
    
    qDebug() << m_dte1;
    qDebug() << s_dte1;
    
    prvi->date_from = s_dte1;
    s_set->setValue("search_date_from", m_dte1);
}


