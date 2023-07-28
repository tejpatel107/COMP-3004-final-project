#include "battery.h"


Battery::Battery(int l,int x, int y, QWidget *parent):QProgressBar (parent)
{
      level=l;
      move(x,y);
      setMinimum(0);
      setMaximum(100);
      this->setValue(l);
      p=this->palette();
      p.setColor(QPalette::Highlight, Qt::darkGreen);
      this->setPalette(p);


}


Battery::~Battery(){}
int Battery::getBatteryLevel()
{
    return level;
}

void Battery::drainingSpeed()
{
    if(drainSpeed < 10)
        sleep(4);
    else if(drainSpeed >= 10 && drainSpeed < 25)
        sleep(3);
    else if(drainSpeed >= 25 && drainSpeed < 50)
        sleep(2);
    else if(drainSpeed >= 50 && drainSpeed < 75)
        usleep(1500000);
    else
        sleep(1);

}

void Battery::drainBattery()
{

    while(this->value() != 0){
        this->setValue(level-1);
        level-=1;

        if(level== 20){
        p.setColor(QPalette::Highlight, Qt::red);
        this->setPalette(p);
        }
        drainingSpeed();
    }


    emit emitPowerOff();
}


void Battery::rechargeBattery()
{
    p.setColor(QPalette::Highlight, Qt::darkGreen);
    this->setPalette(p);
    this->setValue(25);
    sleep(1);
    this->setValue(50);
    sleep(1);
    this->setValue(75);
    sleep(1);
    this->setValue(100);
    level=100;
}

void Battery:: setBatteryLevel(int num)
{
    level= num;
}

void Battery::setDrainingSpeed(int power)
{
    drainSpeed = power;
}


