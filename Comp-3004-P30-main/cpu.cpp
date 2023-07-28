#include"cpu.h"


Cpu::Cpu(QWidget *parent):QObject(parent), thread(m.battery)
{



}


void Cpu::startDevice(){




    m.show();

/*
 * Button  Connections
 *
 * Start Button responsible for powering on/off the device which changes the display to main menu page when pressed.
 * Ok button responsible for navigating through the deveice.
 * Up and Down arrow key buttons for navigating up and down the options lists.
 * Right and Left arrow key buttons for increasing/decreasing power level.
 * Back button to go to previous page.

 * When a button is clicked a signal is sent to a slot that is connected to it.

*/

    connect(m.start,SIGNAL(clicked()),m.display,SLOT(changeToMainPage()));
    connect(m.ok,SIGNAL(clicked()),m.display,SLOT(selectChoice()));
    connect(m.up,SIGNAL(clicked()),m.display,SLOT(navigateUpList()));
    connect(m.down,SIGNAL(clicked()),m.display,SLOT(navigateDownList()));
    connect (m.back,SIGNAL(clicked()),m.display,SLOT(backOutOfPage()));
    connect(m.right,SIGNAL(clicked()),m.power,SLOT(increasePower()));
    connect(m.left,SIGNAL(clicked()),m.power,SLOT(decreasePower()));

/*
 * Frequency slider connections
 *
 * When the slider value is changed the signal is sent to different pages slots appropriately connected
 * to them to show the value on display.
 */

    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getFrequencyPage(),SLOT(showValueOnDisplay(int)));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getTherapyPage(),SLOT(showFrequencyOnDisplay(int)));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getFrequencyTherapyPage(),SLOT(showFrequencyOnDisplay(int)));

/*
 * Power Level connections
 *
 * When the LCD number is changed using the left/right buttons the signal is sent to different pages slots
 * appropriately connected to them to show the value on display.
 */
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getTherapyPage(),SLOT(increasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getTherapyPage(),SLOT(decreasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getFrequencyTherapyPage(),SLOT(increasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getFrequencyTherapyPage(),SLOT(decreasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.battery,SLOT(setDrainingSpeed(int)));

    connect(m.display->getFrequencyPage()->getStartFrequency(),SIGNAL(clicked()),m.display,SLOT(startFrequency()));

/*
 * Therapy Page connections.
 *
 * Therapy Pages have 2 buttons, 1 responsible for start/stop/'continue therapy' and another is end button for ending
 * the therapy.
 *
 * When start button is clicked it starts the thread that is responsible for drarining the battery, it is also
 * responsible for starting, stoping and continuing therapy, by sending a signal to the appropriate slot in the
 * therapy page.
*/

    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(startTimer()));
    connect(m.display->getTherapyPage()->end,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(endTimer()));

/*
 * Frequency Therapy Page connections.
 *
 * Frequency Therapy Pages have 2 buttons, 1 responsible for start/stop/'continue therapy' and another is end button for ending
 * the frequency therapy.
 *
 * When start button is clicked it starts the thread that is responsible for drarining the battery, it is also
 * responsible for starting, stoping and continuing therapy, by sending a signal to the appropriate slot in the
 * frequency therapy page.
*/
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(startTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(endTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),&thread,SLOT(stopThread()));

/*
 * Program Therapy and Frequency Therapy pages To Power connections.
 *
 * 1st Connection sends a signal from the display to the power to enable/disable the left/right buttons to adjust power.
 * The other connections are responsible for adjusting the Power Level during therapies by sending a signal to the power
 * class slots to update the power level.
*/

    connect(m.display,SIGNAL(allowButton(bool)),m.power,SLOT(checkallowButtonBool(bool)));
    connect(m.display->getTherapyPage(),SIGNAL(emitPowerLevel(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitPowerLevel(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));
    connect(m.display,SIGNAL(emitPowerLevel(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));

/*
 * Program Therapy and Frequency Therapy pages To Frequency slider connections.
 *
 * 1st Connection sends a signal from the display to the slider to disable it and to adjust the frequency based on what
 * the user picks.
 *
 * The other connection is responsible for resetting the Frequency Slider after therapies are completed and enabling the
 * frequency slider.
*/

    connect(m.display,SIGNAL(emitFrequency(int)),m.fs,SLOT(setFrequencyValue(int)));
    connect(m.display,SIGNAL(resetFrequency()),m.fs,SLOT(enableFrequencyChange()));

/*
 * Program Therapy and Frequency Therapy pages to Threads connections
 *
 * Signals send to the thread to start/stop the thread.
*/

    connect(m.display,SIGNAL(emitStartCharge()),&thread,SLOT(start()));
    connect(m.display->getTherapyPage(),SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));
    connect(m.display,SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));

/*
 * Program Therapy and Frequency Therapy pages to History Page connections
 *
 * Signals send to the History Page with a recorded therapy to be display to the user using the appropriate slot.
*/


    connect(m.display->getTherapyPage(),SIGNAL(emitRecording(Recording*)),m.display->getViewHistoryPage(),SLOT(addRecording(Recording *)));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitRecording(Recording*)),m.display->getViewHistoryPage(),SLOT(addRecording(Recording *)));
    connect(m.display,SIGNAL(emitClearHistory()),m.display->getViewHistoryPage(),SLOT(clearHistory()));

/*
 * Electrode to Program Therapy and Frequency Therapy pages connections
 *
 * Signal sent from electrode class indicating whether the checkbox is checked or not. Sent to the appropriate slot to stop
 * timer.
*/

    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getTherapyPage(),SLOT(sensorOnSkin(bool)));
    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getTherapyPage(),SLOT(stopTimer()));
    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getFrequencyTherapyPage(),SLOT(sensorOnSkin(bool)));
    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getFrequencyTherapyPage(),SLOT(stopTimer()));

/*
 * Program Therapy and Frequency Therapy pages to Electrode connections
 *
 * Signal sent from therpy/frequency pages to uncheck the checkbox. Sent to the appropriate slot of the electrode class.
*/

    connect(m.display->getTherapyPage(),SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));
    connect(m.display,SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));

/* Battery and Display connections
 *
 * 1st connections is responsible for showing the battery is getting recharged.
 * 2nd connection when the battery recharges it powers up the device and switches to start page.
*/

    connect(m.display,SIGNAL(emitRecharged(int)),m.battery,SLOT(setBatteryLevel(int)));
    connect(m.battery,SIGNAL(emitPowerOff()),m.display,SLOT(rechargeBattery()));

    connect(m.display,SIGNAL(emitChangetoStartPage()),m.display,SLOT(changetoStartPage()));
}




Cpu::~Cpu(){


}


