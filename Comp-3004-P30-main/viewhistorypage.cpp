#include "viewhistorypage.h"


ViewHistoryPage::ViewHistoryPage(QWidget *parent):Page(parent)
{

layout = new QGridLayout();
layout->addWidget(list);
setLayout(layout);
}

ViewHistoryPage::~ViewHistoryPage(){
    delete layout;
    list->clear();
};

void ViewHistoryPage::addRecording(Recording* r){
    QString freq = QString::number(r->getFreq());
    QString mins = QString::number(r->getMinutes());
    QString secs = QString::number(r->getSeconds());
    QString powerLevel = QString::number(r->getPowerLevel());
    QString as = QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss");

    list->addItem(r->getDay());
    if(r->getType()=="Program"){
        list->addItem("     Treatment: "+r->getType()+", " +r->getName());
    }
    else{
        list->addItem("     Treatment: "+r->getType());
    }

    list->addItem("     Power level: "+ powerLevel);
    list->addItem("     Frequency "+freq);
    list->addItem("     Duration: "+ mins +"m"+secs+"s");

    delete r;
}


void ViewHistoryPage::clearHistory(){

    list->clear();

}
