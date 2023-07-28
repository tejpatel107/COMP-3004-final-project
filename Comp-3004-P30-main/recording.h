/* Recording Class
 *
 * inherits the QT class QObject
 *
 * initializes an object that contains all
 * of the information correspending to a therapy
 * that has been completed by the user
 *
 *attributes:
 *  name
 *  type
 *  date
 *  powerLevel
 *  freq
 *  seconds
 *  minutes
 */
#ifndef RECORDING_H
#define RECORDING_H

#include <QString>
#include <QObject>
#include <QTime>
class Recording: public QObject
{
    Q_OBJECT
public:
    Recording(QString,QString, QTime,int,int,int,int);
    QString getName();
    QString getType();
    QTime getTime();
    QString getDay();
    int getPowerLevel();
    int getFreq();
    int getSeconds();
    int getMinutes();
private:
    QString name;
    QString type;
    QTime time;
    QDateTime date;
    int powerLevel;
    int freq;
    int seconds;
    int minutes;
   \
};

#endif // RECORDING_H
