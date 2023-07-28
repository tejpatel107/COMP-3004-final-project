/* Thread class
 *
 * inherits the QT class QThread
 *
 * has a battery object and initialzies a
 * thread so the battery can drain simultainously
 * with the denas program.
 */
#ifndef THREAD_H
#define THREAD_H
#include<QtCore>
#include<QString>
#include<QProgressBar>
#include<battery.h>
class Thread: public QThread
{
    Q_OBJECT
public:

    Thread(Battery *battery);
    void run();
    void stop();
    Battery *battery;

private slots:
    void stopThread();
};

#endif // THREAD_H
