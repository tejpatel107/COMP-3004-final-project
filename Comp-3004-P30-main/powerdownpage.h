/* PowerDownPage Class
 *
 * concrete entity class that extends
 * the abstract Page class
 *
 * has a QLabel that displays to the user:
 * recharging...
 * when the battery level reaches 0.
 *
*/
#ifndef POWERDOWNPAGE_H
#define POWERDOWNPAGE_H

#include "page.h"

#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QLayout>


class PowerDownPage: public Page
{

    Q_OBJECT
public:
    explicit PowerDownPage(QWidget *parent = nullptr);
    ~PowerDownPage();

private:
    QLabel *label;
    QLayout *layout;
};

#endif // POWERDOWNPAGE_H
