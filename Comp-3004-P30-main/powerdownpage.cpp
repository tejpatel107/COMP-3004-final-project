#include "powerdownpage.h"

PowerDownPage::PowerDownPage(QWidget* parent): Page(parent)
{
this->label = new QLabel();
    label->setText("recharging...");

    layout = new QVBoxLayout();
    layout->addWidget(label);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont( "Arial", 12, QFont::Bold));


    setLayout(layout);

}

PowerDownPage::~PowerDownPage(){
    delete label;
    delete layout;

}
