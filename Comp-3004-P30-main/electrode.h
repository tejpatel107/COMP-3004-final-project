/* Electrode Class
 *
 * inherits the QT class QCheckBox
 *
 * simulates the electrode of the device
 * being placed on the user's skin through
 * a checkbox.
*/
#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>

class Electrode : public QCheckBox
{
    Q_OBJECT

public:
    Electrode(QWidget *parent=nullptr);
    ~Electrode();

private slots:
    //sets the checkbox false
    void sensorOffSkin();
};

#endif // ELECTRODE_H
