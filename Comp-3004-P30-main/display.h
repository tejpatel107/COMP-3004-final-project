/* Display Class
 *
 * inherits the QT class QStackedWidget
 *
 * diplays all of the pages and fuctionalities
 * of the program.
*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QStackedWidget>
#include<QPushButton>
#include <QListWidget>
#include"page.h"
#include "frequencypage.h"
#include "historypage.h"
#include "therapypage.h"
#include"mainmenupage.h"
#include"startpage.h"
#include"programspage.h"
#include"powerdownpage.h"
#include"noimplementation.h"
#include"viewhistorypage.h"
#include "powerlevel.h"
#include"frequencytherapypage.h"
#include"bloating.h"
#include"allergy.h"
#include"trauma.h"
#include"kidney.h"



class Display: public QStackedWidget{
    Q_OBJECT


private:
    //pages displayed to the user
    StartPage *startPage;
    MainMenuPage *mainMenuPage;
    ProgramsPage *programsPage;
    FrequencyPage *frequencyPage;
    HistoryPage *historyOptionsPage;
    TherapyPage *therapyPage;
    NoImplementation *noImplementationPage;
    ViewHistoryPage *viewHistoryPage;
    FrequencyTherapyPage* frequencyTherapyPage;
    PowerDownPage* powerDownPage;
    Trauma *trauma;
    Allergy *allergy;
    Bloating *bloating;
    Kidney *kidney;

    //int current;


public:
    Display(QWidget *parent =nullptr);
    ~Display();
    //function responsible for starting a program, a program number is passed to
    //it and depending on the number the program is appropriatley picked
    void startProgram(int programNumber);
    StartPage* getStartPage();
    MainMenuPage* getMainPage();
    ProgramsPage* getProgramsPage();
    FrequencyPage* getFrequencyPage();
    HistoryPage* getHistoryPage();
    TherapyPage* getTherapyPage();
    ViewHistoryPage* getViewHistoryPage();
    FrequencyTherapyPage* getFrequencyTherapyPage();
    NoImplementation* getNoImplementationPage();

private:
    //function that calls a signal
    void  enableButtons(bool);
    //function that calls a signal
    void setFrequencyOnSlider(int);
    //functions that calls a signal
    void resetFrequencyOnSlider();

signals:
    //function that sends a signal to enable/disable buttons
    void allowButton(bool);
    //function that sends a signl with a frequency value to set it on the slider
    void emitFrequency(int);
    //reset the frequency to 0
    void resetFrequency();
    //clears the recording history
    void emitClearHistory();
    //Function to turn off the start button of the program
    void emitPowerLevel(int);
    //Signal sent to start charging the device
    void emitStartCharge();
    //signal sent to change to the Start page of the program
    void emitChangetoStartPage();
    //signal sent to stop the thread
    void emitStopThread();
    //signal sent with an integer to set the battery level to 100
    void emitRecharged(int);
    //signal sent to notify that sensor is off the skin
    void emitSensorOffSkin();

private slots:
    //sets the index of pages to the main page
    void changeToMainPage();
    //function to determine the choice selected and switch to the selected page
    void selectChoice();
    //function switches to the frequency therapy page and sets the frequency approprietly
    //and enables powerlevel buttons
    void startFrequency();
    //navigated down the list
    void navigateDownList();
    //navigates up the list
    void navigateUpList();
    //function to back out the page
    void backOutOfPage();
    //function that ends all therapies and emits a signal to start charging the device
    void rechargeBattery();
    //changes back to the starting page of the program
    void changetoStartPage();


};

#endif // DISPLAY_H
