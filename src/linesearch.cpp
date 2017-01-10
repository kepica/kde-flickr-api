#include <QKeyEvent>
#include <QListView>
#include <QStringListModel>
#include <QDebug>

#include "linesearch.h"

QListView *listView;
QStringListModel *model;

LineSearch::LineSearch( QStringList words, QWidget *parent) : QLineEdit(parent)
{
    listView = new QListView(this);
    model = new QStringListModel(this);
    listView->setWindowFlags(Qt::ToolTip);
    
    m_list = words;

    connect(this, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));
    connect(listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));

    // listView->setModel(model);
}

void LineSearch::focusOutEvent(QFocusEvent *e)
{
    listView->hide();
    QLineEdit::focusOutEvent(e);
}

void LineSearch::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if (!listView->isHidden())
    {
        int count = listView->model()->rowCount();
        QModelIndex currentIndex = listView->currentIndex();

        if (key == Qt::Key_Down || key == Qt::Key_Up)
        {
            int row = currentIndex.row();
            switch(key) 
            {
                case Qt::Key_Down:
                if (++row >= count)
                    row = 0;
                break;
                case Qt::Key_Up:
                if (--row < 0)
                    row = count - 1;
                break;
            }

            if (listView->isEnabled())
            {
                QModelIndex index = listView->model()->index(row, 0);
                listView->setCurrentIndex(index);
            }
        }
        // || Qt::Key_Space == key
        else if ((Qt::Key_Enter == key || Qt::Key_Return == key) && listView->isEnabled())
        {
            if (currentIndex.isValid())
            {
                QString text = currentIndex.data().toString();
                setText(text + " ");
                listView->hide();
                setCompleter(this->text());
            }
            else if (this->text().length() > 1)
            {
               QString text = model->stringList().at(0);
                setText(text + " ");
                listView->hide();
                setCompleter(this->text());
            }
            else
            {
                QLineEdit::keyPressEvent(e);
            }
        }
        else if (Qt::Key_Escape == key)
        {
            listView->hide();
        }
        else
        {
            // listView->hide();
            QLineEdit::keyPressEvent(e);
        }
    }
    else
    {
        if (key == Qt::Key_Down || key == Qt::Key_Up)
        {
            setCompleter(this->text());

            if (!listView->isHidden())
            {
                int row;
                switch(key) 
                {
                    case Qt::Key_Down:
                        row = 0;
                    break;
                    case Qt::Key_Up:
                        row = listView->model()->rowCount() - 1;
                    break;
                }
                if (listView->isEnabled())
                {
                    QModelIndex index = listView->model()->index(row, 0);
                    listView->setCurrentIndex(index);
                }
            }
        }
        else
        {
            QLineEdit::keyPressEvent(e);
        }
    }
}

void LineSearch::setCompleter(const QString &text)
{
    if (text.isEmpty())
    {
        listView->hide();
        return;
    }

    /*
    if ((text.length() > 1) && (!listView->isHidden()))
    {
        return;
    }
    */
    
    if (search_disabled)
    {
        listView->hide();
        return;
    }
    else
    {
        QStringList sl;
        foreach(QString word, m_list) {
            if (word.contains(text, Qt::CaseInsensitive)) {
                sl << word;
            }
        }

        model->setStringList(sl);
        listView->setModel(model);

        if (model->rowCount() == 0) {
            return;
        }

        // Position the text edit
        listView->setMinimumWidth(width());
        listView->setMaximumWidth(width());

        QPoint p(0, height());
        int x = mapToGlobal(p).x();
        int y = mapToGlobal(p).y() + 1;

        listView->move(x, y);
        listView->show();
    }

    /*
    model->setStringList(filteredModelFromText(text));
    if (model->rowCount() == 0)
    {
        return;
    }
    int maxVisibleRows = 10;
    // Position the text edit
    QPoint p(0, height());
    int x = mapToGlobal(p).x();
    int y = mapToGlobal(p).y() + 1;
    listView->move(x, y);
    listView->setMinimumWidth(width());
    listView->setMaximumWidth(width());
    if (model->rowCount() > maxVisibleRows)
    {
        listView->setFixedHeight(maxVisibleRows * (listView->fontMetrics().height() + 2) + 2);
    }
    else
    {
        listView->setFixedHeight(model->rowCount() * (listView->fontMetrics().height() + 2) + 2);
    }
    listView->show();
    */
}

//Basically just a slot to connect to the listView's click event
void LineSearch::completeText(const QModelIndex &index)
{
    QString text = index.data().toString();
    setText(text);
    listView->hide();
}

void LineSearch::disableSearch()
{
    search_disabled = true;
}

/*
QStringList LineSearch::filteredModelFromText(const QString &text)
{
    Q_UNUSED(text);
    QStringList newFilteredModel;
    //do whatever you like and fill the filteredModel
    return newFilteredModel;
}
*/
