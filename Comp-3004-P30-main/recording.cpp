#include "recording.h"

Recording::Recording(QString type,QString name,QTime t, int pl,int f,int s,int m)
{
    this->type=type;
    this->name = name;
    this->time = t;
    this->powerLevel = pl;
    this->freq = f;
    this->seconds = s;
    this->minutes = m;
    date = QDateTime::currentDateTime();
}

QString Recording::getName(){
    return this->name;
}
QString Recording::getType(){
    return this->type;
}

QTime Recording::getTime(){
    return this->time;
}

int Recording::getPowerLevel(){
    return this->powerLevel;
}

int Recording::getFreq(){
    return this->freq;
}

int Recording::getSeconds(){
    return this->seconds;
}

int Recording::getMinutes(){
    return this->minutes;
}

QString Recording::getDay(){

  return QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss");

}


