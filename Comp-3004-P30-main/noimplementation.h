/* NoImplementation Class
 *
 * concrete entity class that extends
 * the abstract Page class
 *
 * has  QLabel that displays to the screen:
 *  "Features have not been implemented"
 *
*/
#ifndef NOIMPLEMENTATION_H
#define NOIMPLEMENTATION_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QLayout>

#include"page.h"

class NoImplementation : public Page
{
    Q_OBJECT
public:
    explicit NoImplementation(QWidget *parent = nullptr);
    ~NoImplementation();

private:
    QLabel *label;
    QLayout *layout;
};

#endif // NOIMPLEMENTATION_H
