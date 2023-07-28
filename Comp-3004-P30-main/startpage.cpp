#include"startpage.h"
#include <QFont>

StartPage::StartPage(QWidget *parent ): Page (parent){

    label = new QLabel;
    label->setText("DENAS PCM6");

    layout = new QVBoxLayout();
    layout->addWidget(label);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont( "Arial", 15, QFont::Bold));

    setLayout(layout);
}
StartPage::~StartPage(){
    delete label;
    delete layout;

}
