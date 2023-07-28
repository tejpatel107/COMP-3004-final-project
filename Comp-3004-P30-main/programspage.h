/* ProgramPage Class
 *
 * concrete entity class the extends
 * abstract Page class
 *
 * displays the programs to the user.
 *
 */
#ifndef PROGRAMSPAGE_H
#define PROGRAMSPAGE_H
#include"page.h"
#include <QWidget>
#include <QListWidget>
#include<QLabel>
#include <QLayout>




class ProgramsPage: public Page{
    Q_OBJECT

public:
    ProgramsPage(QWidget *parent =nullptr);
   ~ProgramsPage();
private:
     QLayout *layout;



};

#endif // PROGRAMSPAGE_H
