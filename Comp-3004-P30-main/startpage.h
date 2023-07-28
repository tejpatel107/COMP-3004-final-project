/* StartPage Class
 *
 * concrete entity class the extends
 * the abstract Page class
 *
 * displays DENAS-PCM6 to the user
 *
 * This is the first page the user will see
 */
#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QListWidget>
#include<QLabel>
#include <QLayout>
#include"page.h"


class StartPage: public Page{
    Q_OBJECT

private:
    QLabel *label;
    QLayout *layout;

public:
    StartPage(QWidget *parent =nullptr);
    ~StartPage();



};

#endif // STARTPAGE_H
