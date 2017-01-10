#include <QApplication>

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QScrollArea>
#include <QAbstractScrollArea>
#include <QtCore>

#include <KTextEdit>
#include <KLocalizedString>

#include "welcome.h"

Welcome::Welcome(int koji) : QDialog()
{
    QPixmap slika;
    slika.load("./angel_s.jpg");
   
    QLabel *label = new QLabel();
    label->setBackgroundRole(QPalette::Base);
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label->setScaledContents(true);
    label->setPixmap(slika);
    
    QScrollArea *okvir = new QScrollArea();
    okvir->setBackgroundRole(QPalette::Dark);
    okvir->setWidget(label);
    okvir->setVisible(true);
    okvir->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    okvir->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff ); 
    
    // horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    // verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");

    
    KTextEdit *textArea = new KTextEdit();
    textArea->setReadOnly(true);
    textArea->setMinimumSize(400, 597);
    
    QGridLayout* mainGrid = new QGridLayout;
    // QVBoxLayout* topLayout = new QVBoxLayout;
    // topLayout->addWidget(h1Layout);
    // topLayout->addWidget(h2Layout);
    
    QHBoxLayout* h1Layout = new QHBoxLayout;
    h1Layout->addWidget(okvir);
    h1Layout->addWidget(textArea);
    
    QHBoxLayout* h2Layout = new QHBoxLayout;
    QPushButton* btn1;
    btn1 = new QPushButton("OK");
    connect(btn1, SIGNAL(clicked()), this, SLOT(slot_accept()));
    // QPushButton* btn2;
    // btn2 = new QPushButton("Cancel");
    // connect(btn2, SIGNAL(clicked()), this, SLOT(sl_cancel()));
    QLabel *lab1 = new QLabel();
    QLabel *lab2 = new QLabel();

    h2Layout->addWidget(lab1);
    h2Layout->addWidget(btn1);
    h2Layout->addWidget(lab2);
    
    mainGrid->addLayout(h1Layout,0,0);
    mainGrid->addLayout(h2Layout,1,0);
 
    setLayout(mainGrid);
    
    textArea->setHtml("<font size=""3"">WELCOME to Oblaci from Vedra Nebesa </font>"  
            "<font size=""2""><br/>" 
            "Flickr API client for KDE desktop<br/>"
            " <br/>"
            "Beautifull photos from Flickr on your desktop.<br/>"
            "Create local gallery based on your preferences. <br/>"
            "Search and download photography selected by tag , <br/>"
            "or selected by authors, or choose from flickr groups. <br/>"
            "If you have flickr account, activity can be traced here: <br/>"
            "comments on your photos, or any other activity <br/>"
            " * your friend upload new photo <br/>"
            " * there is new post on discusion <br/>"
            " * new photo is uploaded to group pools <br/>"
            "</font>" );
    
    switch (koji)
    {
        
        case 0:       // -- first start
            textArea->append("<html><font size=""3"">" 
                " <br/>"
                " *** WARNING ! <br/>"
                " <br/>"
                "Application's settings are not set. <br/>"
                "Goto Tools > Profile Settings and select <br/>"
                " <br/>"
                " * picture home directory <br/>"
                " <br/>"
                " * flickr-id if you have one <br/>"
                " <br/>"
                " <br/>"
                "  *** (c) 2017 Oblaci from Vedra Nebesa, by kepica <br/>"
                "</font></html>");
            break;
            
        case 1:       // -- flickr-id missing            
            textArea->append("<html><font size=""3"">" 
                " <br/>"
                " *** WARNING ! <br/>"
                " <br/>"
                "Goto Tools > Profile Settings and select <br/>"
                " <br/>"
                " * flickr-id if you have one <br/>"
                " <br/>"
                "... or Disable this dialog <br/>"
                " <br/>"
                " <br/>"
                "  *** (c) 2017 Oblaci from Vedra Nebesa, by kepica <br/>"
                "</font></html>");
            break;
            
        case 2:       // -- all set, but user dont disable this dialog
            textArea->append("<html><font size=""3"">" 
                " <br/>"
                " Hello ! <br/>"
                " <br/>"
                " All important settings allready done. <br/>"
                " <br/>"
                "Goto Tools > Profile Settings and  <br/>"
                "     Disable this dialog <br/>"
                " ... or change whatever you want! <br/>"
                " <br/>"
                " <br/>"
                "  *** (c) 2017 Oblaci from Vedra Nebesa, by kepica <br/>"
                "</font></html>");
            break;
    }
    
    setWindowTitle(QString("Welcome ")) ;
}

void Welcome::slot_accept()
{
    this->close();
}
