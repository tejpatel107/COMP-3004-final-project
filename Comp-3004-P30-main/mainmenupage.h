/* MainMenuPage Class
 *
 * concrete entity class that extends
 * the abstract Page class
 *
 * displays all of the menu options to the user:
 *  Programs
 *  Frequency
 *  History
 *  Screening
 *  Children
 *  Settings
 *
 */

#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H
#include<QLabel>
#include <QLayout>
#include <QWidget>
#include <QListWidget>
#include"page.h"


class MainMenuPage: public Page{
    Q_OBJECT



public:
    MainMenuPage(QWidget *parent =nullptr);
    ~MainMenuPage();


private:
     QLayout *layout;

};

#endif // MAINMENUPAGE_H
