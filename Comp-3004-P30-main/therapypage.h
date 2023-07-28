/* TherapyPage Class
 *
 * concrete entity calss that extends
 * the abstarct Page class
 *
 * initliazes a therapy with a timer, a start/stop
 * button, and an end therapy button.
 *
*/
#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include <string>
#include <QLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include "page.h"
#include "frequencypage.h"
#include "frequency.h"
#include "recording.h"
#include <unistd.h>
#include <cstdlib>
#include<QMessageBox>


class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);

    ~TherapyPage();

    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
    void setName(QString);
    void setFrequencyAndPower(int);
    void setMinsAndSecs(int,int);
    void setAllowSaveOption(bool);

private:
    QString minString ;
    QString secsString;
    QString name;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;
    QLabel *nameLabel;
    QLabel *frequencyNumberLabel;
    QLabel *powerNumberLabel;
    QLabel *frequencyLabel;
    QLabel *powerLabel;
    QLabel *adjustPowerAndElectrodeLabel;
    QLayout *layout;
    QHBoxLayout *labelLayout;
    QMessageBox msgBox;
    bool allowSaveOption=true;
    bool therapyStarted=false;
    bool electrodePlaced=false;
    int timerMins;
    int timerSecs;
    int recordingMinutes;
    int recordingSeconds;
    int freq;
    int powerLevel;
    int maxPower;
    int prevMins;
    int prevSeconds;
    int prevFreq;
    int counter = 1;
    void recordMinutesAndSecond();
    void validateTime(int,int);
    void resetTimer();
    void createRecording(QString,QString, QTime,int,int,int,int);


signals:
    void emitStopThread();
    void emitRecording(Recording *);
    void emitPowerLevel(int);
    void emitSensorOffSkin();

public slots:
     void endTimer();



private slots:
    void showTime();
    void startTimer();
    void stopTimer();
    void increasePowerLevel(int);
    void decreasePowerLevel(int);
    void showFrequencyOnDisplay(int);
    void sensorOnSkin(bool);
};

#endif // THERAPYPAGE_H
