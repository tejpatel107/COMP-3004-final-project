#include"programspage.h"

ProgramsPage::ProgramsPage(QWidget *parent ): Page (parent){
    this->list->addItem("ALLERGY");
    this->list->addItem("BLOATING");
    this->list->addItem("TRAUMA");
    this->list->addItem("KIDNEYS");
    this->list->addItem("THROT");
    this->list->addItem("HEAD");

    list->setCurrentRow(0);

    layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);

}

ProgramsPage::~ProgramsPage(){
    delete layout;
}






