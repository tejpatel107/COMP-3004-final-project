/* FrequencyTherapyPage Class
 *
 * concrete entity class that extends
 * the abstract Page class
 *
 * provides all of the fuctionality of
 * the frequency page.
*/

#ifndef FREQUENCYTHERAPYPAGE_H
#define FREQUENCYTHERAPYPAGE_H

#include <QObject>
#include <QWidget>
#include<QLCDNumber>
#include<QTimer>
#include<QTime>
#include<QMessageBox>
#include "page.h"
#include"recording.h"

class FrequencyTherapyPage : public Page
{
    Q_OBJECT
public:
    FrequencyTherapyPage(QString = "NULL", int = 60, QWidget *parent = nullptr);
    ~FrequencyTherapyPage();
    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
    void setName(QString);
    void setFrequencyAndPower(int);
    void setAllowSaveOption(bool);


private:
    QString minString ;
    QString secsString;
    QString name;
    QTimer *timer;
    QLabel *nameLabel;
    QLabel *frequencyNumberLabel;
    QLabel *powerNumberLabel;
    QLabel *frequencyLabel;
    QLabel *powerLabel;
    QLabel *adjustPowerAndElectrodeLabel;
    QLCDNumber *frequencyTherapyTimerDisplay;
    QLayout *layout;
    QHBoxLayout *labelLayout;
    Recording * r;
    bool allowSaveOption=true;
    bool electrodePlaced=false;
    int timerMins;
    int timerSecs;
    int freq;
    int powerLevel;
    int maxPower;
    int counter = 1;
    bool frequencyTherapyStarted=false;
    void validateTime(int, int);
    void createRecording(QString ,QString, QTime , int , int , int, int );

signals:
    //stops the thread that drains the battery, when the stop button and end button
    //is clicked
    void emitStopThread();
    //sends recording to history page
    void emitRecording(Recording*);
    void emitPowerLevel(int);
    void emitSensorOffSkin();

public slots:
    //ends the timer
     void endTimer();

private slots:
    void updateTime();
    void startTimer();
    void stopTimer();
    void increasePowerLevel(int);
    void decreasePowerLevel(int);
    void showFrequencyOnDisplay(int);
    void sensorOnSkin(bool);
};

#endif // FREQUENCYTHERAPYPAGE_H
