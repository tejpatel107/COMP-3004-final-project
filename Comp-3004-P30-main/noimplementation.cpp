#include "noimplementation.h"

NoImplementation::NoImplementation(QWidget *parent) : Page(parent)
{

    label = new QLabel;
    label->setText("Features have not been implemented");

    layout = new QVBoxLayout();
    layout->addWidget(label);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont( "Arial", 12, QFont::Bold));

    setLayout(layout);

}

NoImplementation::~NoImplementation(){

    delete label;
    delete layout;

}
