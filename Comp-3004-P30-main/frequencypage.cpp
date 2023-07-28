#include "frequencypage.h"

FrequencyPage::FrequencyPage(QWidget *parent) :
    Page(parent)
{
    promptLabel = new QLabel();
    frequencyValue = new QLabel();
    startFrequency = new QPushButton;
    startFrequency->setText("start Frequency");
    promptLabel->setText("Move slider on side to set frequency");
    frequencyValue->setNum(60);

    layout = new QVBoxLayout();
    layout->addWidget(promptLabel);
    layout->addWidget(frequencyValue);
    layout->addWidget(startFrequency);

    promptLabel->setAlignment(Qt::AlignCenter);
    promptLabel->setFont(QFont( "Arial", 12, QFont::Bold));
    frequencyValue->setAlignment(Qt::AlignCenter);
    frequencyValue->setFont(QFont( "Arial", 15, QFont::Bold));


    setLayout(layout);
}

FrequencyPage::~FrequencyPage(){
    delete promptLabel;
    delete frequencyValue;
    delete startFrequency;
    delete layout;
}

void FrequencyPage::showValueOnDisplay(int value)
{
    promptLabel->setText("Frequency selected: ");
    frequencyValue->setNum(value);
}

QString FrequencyPage::getValue()
{
    return frequencyValue->text();
}

QPushButton* FrequencyPage::getStartFrequency(){

    return startFrequency;
}
