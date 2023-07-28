#include "historypage.h"

HistoryPage::HistoryPage(QWidget *parent):
    Page(parent)
{
    list = new QListWidget ();
    this->list->addItem("View");
    this->list->addItem("Clear");

    list->setCurrentRow(0);

    layout = new QVBoxLayout ();
    layout->addWidget(this->list);
    setLayout(layout);
}

HistoryPage::~HistoryPage(){

    delete layout;
}


