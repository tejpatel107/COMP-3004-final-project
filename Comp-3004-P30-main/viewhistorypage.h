/* ViewHistoryPage Class
 *
 * concrete entity class the extends
 * the abstracy page class
 *
 * displays the recording objects that
 * contain all the information on past
 * therapys completed by the user.
 *
 * also has a clear history option.
 */
#ifndef VIEWHISTORYPAGE_H
#define VIEWHISTORYPAGE_H
#include"page.h"
#include "recording.h"
#include"QLabel"
#include"QGridLayout"
#include"QFrame"
class ViewHistoryPage : public Page
{
    Q_OBJECT
public:
    ViewHistoryPage(QWidget *parent=nullptr);
    ~ViewHistoryPage();

private:
    QGridLayout *layout;
private slots:
    void addRecording(Recording*);
    void clearHistory();


};

#endif // VIEWHISTORYPAGE_H
