/* HistoryPage class
 *
 *concrete entity clss the extends
 *the abstract Page class
 *
 *displays to the user a menu that has
 *a "View" and "Clear" option
 *
*/
#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include "page.h"
#include <QLayout>
#include <QLabel>
#include <QListWidget>

class HistoryPage : public Page
{
public:
    HistoryPage(QWidget *parent = nullptr);
    ~HistoryPage();
private:
     QLayout *layout;

};

#endif // HISTORYPAGE_H
