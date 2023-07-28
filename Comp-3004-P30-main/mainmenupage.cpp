#include"mainmenupage.h"

MainMenuPage::MainMenuPage(QWidget *parent ): Page (parent){

    this->list->addItem("Programs");
    this->list->addItem("Frequency");
    this->list->addItem("History");
    this->list->addItem("Screening");
    this->list->addItem("Children");
    this->list->addItem("Settings");

    list->setCurrentRow(0);


    layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);

}


MainMenuPage::~MainMenuPage(){
    delete layout;
}
