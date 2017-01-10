#include <QTimer>
#include <QEventLoop>

#include "waitsignal.h"

QEventLoop *m_loop;

WaitSignal::WaitSignal(QObject *object, const char *signal)  : b_flag( false )
{
    m_loop = new QEventLoop();
    connect(object, signal, m_loop, SLOT( quit() ) );
}

bool WaitSignal::wait(int ms)
{
    QTimer m_timer;
    if ( ms != 0)
    {
        m_timer.setInterval(ms);
        m_timer.start();
        connect(&m_timer, SIGNAL( timeout() ), this, SLOT( timeout() ) );
    }
    // else forever
    
    b_flag = false;
    
    m_loop->exec();
    
    return !b_flag;
}

void WaitSignal::timeout()
{
    b_flag = true;
    m_loop->quit();
}
