#include "display.h"


Display::Display(QWidget *parent ): QStackedWidget (parent){


      setGeometry(25,25,325,250);
      setStyleSheet("background-color:rgb(192, 192, 192);");

      startPage = new StartPage(this);                  // 0
      mainMenuPage  = new MainMenuPage;                 // 1
      programsPage = new ProgramsPage;                  // 2
      frequencyPage = new FrequencyPage;                // 3
      historyOptionsPage = new HistoryPage;             // 4
      therapyPage = new TherapyPage;                    // 5
      viewHistoryPage = new ViewHistoryPage;            // 6
      noImplementationPage = new NoImplementation;      // 7
      frequencyTherapyPage= new FrequencyTherapyPage;   // 8
      powerDownPage =new PowerDownPage;



      this->addWidget(startPage);
      this->addWidget(mainMenuPage);
      this->addWidget(programsPage);
      this->addWidget(frequencyPage);
      this->addWidget(historyOptionsPage);
      this->addWidget(therapyPage);
      this->addWidget(viewHistoryPage);
      this->addWidget(noImplementationPage);
      this->addWidget(frequencyTherapyPage);
      this->addWidget(powerDownPage);
}

Display::~Display(){
    delete startPage;
    delete mainMenuPage;
    delete programsPage;
    delete frequencyPage;
    delete historyOptionsPage;
    delete therapyPage;
    delete viewHistoryPage;
    delete noImplementationPage;
    delete frequencyTherapyPage;
    delete powerDownPage;
}


StartPage* Display::getStartPage()
{
    return startPage;
}

MainMenuPage* Display::getMainPage()
{
    return mainMenuPage;
}
ProgramsPage* Display::getProgramsPage()
{
    return programsPage;
}
FrequencyPage* Display::getFrequencyPage()
{
    return frequencyPage;
}
HistoryPage* Display::getHistoryPage()
{
    return historyOptionsPage;
}
TherapyPage* Display::getTherapyPage()
{
    return therapyPage;
}
ViewHistoryPage* Display::getViewHistoryPage()
{
    return viewHistoryPage;
}

NoImplementation* Display::getNoImplementationPage()
{
    return noImplementationPage;
}

FrequencyTherapyPage * Display::getFrequencyTherapyPage(){

    return frequencyTherapyPage;
}
void Display:: enableButtons(bool x)
{

    emit allowButton(x);
}

void Display:: setFrequencyOnSlider(int freq){
    emitFrequency(freq);
}

void Display:: resetFrequencyOnSlider(){
    emit resetFrequency();
}
void Display::changeToMainPage()
{
    if(this->currentIndex() == startPage->getID())
    {
        setCurrentIndex(mainMenuPage->getID());
    }
    else if(currentIndex() == mainMenuPage->getID())
    {
        setCurrentIndex(startPage->getID());
    }
}



void Display:: selectChoice(){
    if(this->currentIndex()==startPage->getID()){
        return;
    }

    else if (this->currentIndex()== mainMenuPage->getID())
    {
        int currentRow=this->mainMenuPage->list->currentRow();


        if (currentRow==0)
        {
            setCurrentIndex(programsPage->getID());
        }
        else if(currentRow ==1){
            setCurrentIndex(frequencyPage->getID());
        }
        else if(currentRow==2)
        {
            setCurrentIndex(historyOptionsPage->getID());
        }
        else {
            setCurrentIndex(noImplementationPage->getID());
        }

    }
    else if (this->currentIndex()==programsPage->getID())
    {
        int currentRow=this->programsPage->list->currentRow();
        enableButtons(true);
        startProgram(currentRow);
    }
    else if(this->currentIndex()==historyOptionsPage->getID()){

        if(this->historyOptionsPage->list->currentRow()==1){
           emit emitClearHistory();
            return;
        }

        setCurrentIndex(viewHistoryPage->getID());
    }


}

void Display:: startProgram(int programNumber){

    if (programNumber == 0){
        allergy= new Allergy;
        therapyPage->setMinsAndSecs(allergy->minutes,allergy->seconds);
        therapyPage->setName(allergy->programName);
        therapyPage->setFrequencyAndPower(allergy->frequency);
        setFrequencyOnSlider(allergy->frequency);
        delete allergy;

    }
    else if(programNumber==1){
        bloating= new Bloating;
        therapyPage->setMinsAndSecs(bloating->minutes,bloating->seconds);
        therapyPage->setName(bloating->programName);
        therapyPage->setFrequencyAndPower(bloating->frequency);
         setFrequencyOnSlider(bloating->frequency);
         delete bloating;
    }
    else if (programNumber==2) {
        trauma= new Trauma;
        therapyPage->setMinsAndSecs(trauma->minutes,trauma->seconds);
        therapyPage->setName(trauma->programName);
        therapyPage->setFrequencyAndPower(trauma->frequency);
         setFrequencyOnSlider(trauma->frequency);
         delete trauma;
    }
    else if(programNumber==3){
        kidney =new Kidney;
        therapyPage->setMinsAndSecs( kidney->minutes, kidney->seconds);
        therapyPage->setName( kidney->programName);
        therapyPage->setFrequencyAndPower(kidney->frequency);
         setFrequencyOnSlider(kidney->frequency);
         delete kidney;
    }
    else{
        setCurrentIndex(noImplementationPage->getID());
        return;
    }

therapyPage->setAllowSaveOption(true);
setCurrentIndex(therapyPage->getID());
}
void Display:: startFrequency(){
    frequencyTherapyPage->setAllowSaveOption(true);
    frequencyTherapyPage->setName("Frequency");
    frequencyTherapyPage->setFrequencyAndPower(frequencyPage->getValue().toInt());
    setFrequencyOnSlider(frequencyPage->getValue().toInt());
    enableButtons(true);
    setCurrentIndex(frequencyTherapyPage->getID());
}

void Display:: navigateDownList(){


    if(this->currentIndex()==mainMenuPage->getID() && this->mainMenuPage->list->currentRow()<this->mainMenuPage->list->count()-1){
        this->mainMenuPage->list->setCurrentRow(this->mainMenuPage->list->currentRow()+1);
    }
    else if (this->currentIndex()==programsPage->getID() && this->programsPage->list->currentRow()<this->programsPage->list->count()-1) {
        this->programsPage->list->setCurrentRow(this->programsPage->list->currentRow()+1);
    }
    else if (this->currentIndex()==historyOptionsPage->getID() && this->historyOptionsPage->list->currentRow()<this->historyOptionsPage->list->count()-1) {
        this->historyOptionsPage->list->setCurrentRow(this->historyOptionsPage->list->currentRow()+1);
    }

    else if (this->currentIndex() == viewHistoryPage->getID() && this->therapyPage->list->currentRow()<this->therapyPage->list->count()-1) {
        this->therapyPage->list->setCurrentRow(this->therapyPage->list->currentRow()+1);
    }
}

void Display:: navigateUpList(){

    if(this->currentIndex()==mainMenuPage->getID() && this->mainMenuPage->list->currentRow()>0){
        this->mainMenuPage->list->setCurrentRow(this->mainMenuPage->list->currentRow()-1);
    }
    else if (this->currentIndex()==programsPage->getID() && this->programsPage->list->currentRow()>0) {
        this->programsPage->list->setCurrentRow(this->programsPage->list->currentRow()-1);
    }
    else if (this->currentIndex()==historyOptionsPage->getID() && this->historyOptionsPage->list->currentRow()>0) {
        this->historyOptionsPage->list->setCurrentRow(this->historyOptionsPage->list->currentRow()-1);
    }
    else if (this->currentIndex() == viewHistoryPage->getID() && this->therapyPage->list->currentRow()>0) {
        this->therapyPage->list->setCurrentRow(this->therapyPage->list->currentRow()-1);
    }
}


void Display:: backOutOfPage(){
    if(this->currentIndex()>mainMenuPage->getID()){
         if (this->currentIndex()==therapyPage->getID())
         {
             this->therapyPage->endTimer();
             enableButtons(false);
             resetFrequencyOnSlider();
             setCurrentIndex(programsPage->getID());
             emit emitPowerLevel(0);
             emit emitSensorOffSkin();
         }
         else if(this->currentIndex() == frequencyTherapyPage->getID()){
             this->frequencyTherapyPage->endTimer();
             resetFrequencyOnSlider();
             enableButtons(false);
             setCurrentIndex(mainMenuPage->getID());
             emit emitPowerLevel(0);
             emit emitSensorOffSkin();
         }
         else if (this->currentIndex()==viewHistoryPage->getID()) {
             setCurrentIndex(historyOptionsPage->getID());
         }

        else
        {
            setCurrentIndex(mainMenuPage->getID());
        }
    }


}

void Display::rechargeBattery(){

    setCurrentIndex(powerDownPage->getID());
    this->therapyPage->setAllowSaveOption(false);
    this->frequencyTherapyPage->setAllowSaveOption(false);
    this->therapyPage->endTimer();
    this->frequencyTherapyPage->endTimer();
    enableButtons(false);
    resetFrequencyOnSlider();
    emit emitSensorOffSkin();

    emit emitStartCharge();
    sleep(7);
    emit emitChangetoStartPage();
}

void Display:: changetoStartPage(){

    setCurrentIndex(startPage->getID());
    emit emitStopThread();
    emit emitRecharged(100);
}



