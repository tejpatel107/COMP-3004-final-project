#include "frequencytherapypage.h"
#include <QFrame>

FrequencyTherapyPage::FrequencyTherapyPage(QString name, int freq, QWidget *parent):
    Page(parent)
{
    this->name = name;
    this->freq = freq;
    this->powerLevel = 0;
    this->timerMins = 0;
    this->timerSecs = 0;

    timer = new QTimer();
    nameLabel = new QLabel();
    frequencyNumberLabel = new QLabel();
    powerNumberLabel = new QLabel();
    frequencyLabel = new QLabel();
    powerLabel = new QLabel();
    adjustPowerAndElectrodeLabel= new QLabel();
    frequencyTherapyTimerDisplay = new QLCDNumber();

    startStop->setText("start");
    end->setText("end");
    nameLabel->setText(name);
    frequencyNumberLabel->setNum(freq);
    powerNumberLabel->setNum(0);
    frequencyLabel->setText("Frequency:");
    powerLabel->setText("Power Level:");


    QString qstr = QString::number(timerMins);
    QString qstr2 = QString::number(timerSecs);

    adjustPowerAndElectrodeLabel->setFont(QFont( "Arial", 8, QFont::Bold));
    frequencyTherapyTimerDisplay->setFrameShape(QFrame::NoFrame);
    frequencyTherapyTimerDisplay->display("0" + qstr + ":" + "0" + qstr2);




    layout = new QVBoxLayout();
    layout->addWidget(nameLabel);
    layout->addWidget(frequencyTherapyTimerDisplay);

    labelLayout = new QHBoxLayout();
    labelLayout->addWidget(frequencyLabel);
    labelLayout->addWidget(frequencyNumberLabel);
    labelLayout->addStretch();
    labelLayout->addWidget(powerLabel);
    labelLayout->addWidget(powerNumberLabel);

    frequencyLabel->setAlignment(Qt::AlignLeft);
    frequencyNumberLabel->setAlignment(Qt::AlignJustify);
    powerLabel->setAlignment(Qt::AlignRight);
    powerLabel->setIndent(-15);
    powerNumberLabel->setAlignment(Qt::AlignJustify);
    labelLayout->setAlignment(Qt::AlignBottom);

    layout->addItem(labelLayout);
    layout->addWidget(adjustPowerAndElectrodeLabel);
    layout->addWidget(startStop);
    layout->addWidget(end);

    nameLabel->setAlignment(Qt::AlignCenter);

    setLayout(layout);


    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));

}

FrequencyTherapyPage::~FrequencyTherapyPage(){
    delete timer;
    delete nameLabel;
    delete frequencyNumberLabel;
    delete powerNumberLabel;
    delete frequencyLabel;
    delete powerLabel;
    delete adjustPowerAndElectrodeLabel;
    delete frequencyTherapyTimerDisplay;
    delete layout;
    delete labelLayout;

}


void FrequencyTherapyPage::setName(QString name)
{
    this->name = name;
    nameLabel->setText(name);
}

void FrequencyTherapyPage::setFrequencyAndPower(int value)
{
    freq = value;
    frequencyNumberLabel->setNum(freq);
    this->powerLevel=0;
    this->powerNumberLabel->setNum(0);
}

void FrequencyTherapyPage::increasePowerLevel(int power)
{
    this->powerLevel=power;
    powerNumberLabel->setNum(power);
}

void FrequencyTherapyPage::decreasePowerLevel(int power)
{
    this->powerLevel=power;
    powerNumberLabel->setNum(power);
}

void FrequencyTherapyPage::showFrequencyOnDisplay(int value)
{
    freq = value;
    frequencyNumberLabel->setNum(freq);
}

void FrequencyTherapyPage::sensorOnSkin(bool placed)
{
    electrodePlaced = placed;

}
void FrequencyTherapyPage:: setAllowSaveOption(bool save){
    allowSaveOption=save;
}


void FrequencyTherapyPage::startTimer(){
    if(powerLevel != 0 && electrodePlaced == true)
    {
        adjustPowerAndElectrodeLabel->setText(nullptr);
        if(counter == 1)
        {
            this->maxPower=powerLevel;
            emit emitPowerLevel(powerLevel);
            counter+=1;
        }
        this->frequencyTherapyStarted= true;
        if(timer->isActive())
        {
            counter += 1;
            timer->stop();
            startStop->setText("Continue Therapy");
            emit emitStopThread();
            return;
        }
        startStop->setText("stop");
        timer->start(1000);
    }
    else
    {
            adjustPowerAndElectrodeLabel->setText("Please adjust power level and place electrode on skin.");
            emitStopThread();
            return;
    }
}

void FrequencyTherapyPage::stopTimer()
{
    if(frequencyTherapyStarted)
    {
        if(electrodePlaced == false)
        {
            counter += 1;
            timer->stop();
            startStop->setText("Continue Therapy");
            emit emitStopThread();
            return;
        }
    }
}

void FrequencyTherapyPage::updateTime(){
timerSecs++;
if(timerSecs == 60){
    timerSecs=0;
    timerMins++;
}
validateTime(timerMins,timerSecs);
}

void FrequencyTherapyPage::endTimer(){
    if(this->frequencyTherapyStarted==true){
    timer->stop();
    emit emitPowerLevel(0);
    emit emitStopThread();
    emit emitSensorOffSkin();


    if(allowSaveOption==true){
        int ret = QMessageBox::question(this, tr("Save Treatment"),
                                       tr("Do you want to save your Treatment?"),
                                       QMessageBox::Save | QMessageBox::Discard,
                                       QMessageBox::Save);
        if(ret ==2048){
    QTime time = QTime::currentTime();
    createRecording("Program",this->name,time,this->maxPower,this->freq,this->timerSecs,this->timerMins);
        }
    }

    startStop->setText("start");
    frequencyTherapyTimerDisplay->display("00:00");
    timerMins = 0;
    timerSecs=0;
    this->frequencyTherapyStarted=false;
    this->powerLevel=0;
    counter = 1;
    powerNumberLabel->setNum(0);
    adjustPowerAndElectrodeLabel->setText("This therapy cannot start without adjusting power level");
    this->frequencyTherapyStarted=false;

    }
}

void FrequencyTherapyPage::validateTime(int mins, int secs){
    minString = QString::number(mins);
    secsString = QString::number(secs);

    if (timerMins<10 && timerSecs<10) {
        frequencyTherapyTimerDisplay->display("0" + minString + ":" + "0" + secsString);
    }else if(timerMins<10) {
        frequencyTherapyTimerDisplay->display("0" + minString + ":" + secsString);
    }else if(timerSecs<10) {
        frequencyTherapyTimerDisplay->display(minString + ":" + "0" + secsString);
    }
}



void FrequencyTherapyPage::createRecording(QString type,QString name ,QTime t, int pl, int f, int s, int m){
    Recording *r = new Recording(type,name,t,pl,f,s,m);

    emit emitRecording(r);
}

