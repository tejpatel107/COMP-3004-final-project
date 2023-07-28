/* Battery Class
 *
 * inhertits the QT class QProgressBar
 *
 * This class simulates a battery which loses power
 * and gets recharged.
 *
 * attributes:
 *  level
 *  drainSpeed
 *
*/
#ifndef BATTERY_H
#define BATTERY_H
#include<QProgressBar>
#include <QtWidgets>
#include <unistd.h>
#include <cstdlib>
#include<QThread>

class Battery: public QProgressBar {
    Q_OBJECT
private:
    int level;
    int drainSpeed;
    // function to determine how fast the battery will drain.
    void drainingSpeed();

public slots:
    //slot function that sets the battery level
    void setBatteryLevel(int);
    //slot function that sets the draining speed of the battery
    void setDrainingSpeed(int);

public:
    Battery(int l,int x, int y,QWidget *parent =nullptr);
    QPalette p;
    //function executed when the thread starts and is responsible for draining
    //the battery,when the battery is fully drained this function emits a signal
    //to power off the device
    void drainBattery();
    //function responsible for recharging the battery to 100 %
    void rechargeBattery();
    int getBatteryLevel();
    ~Battery();


signals:
    //signal sent from the battery to the display clas to turn off device
    void emitPowerOff();
};

#endif // BATTERY_H
