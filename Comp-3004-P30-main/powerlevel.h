/* PoweLevel Class
 *
 * inherits the QT class QLCDNumber
 *
 * displays and adjusts the power level
 * to the user.
 *
 * attributes:
 *  power
 *  maxPower
 *  minPower
 *  allowPowerLevelChange
*/
#ifndef POWERLEVEL_H
#define POWERLEVEL_H
#include<QLCDNumber>
#include<QLabel>
#include <QLayout>



class PowerLevel : public QLCDNumber{

    Q_OBJECT

public:
    PowerLevel( QWidget *parent = nullptr);
    ~PowerLevel();
    int getPowerLevel();
signals:
  void  emitPowerLevel(int);
private slots:
    void increasePower();
    void decreasePower();
    void checkallowButtonBool(bool);
    void adjustPowerLevelDuringTherapy(int);

private:
    int power;
    int maxPower;
    int minPower;
    bool allowPowerLevelChange;

};

#endif // POWERLEVEL_H
