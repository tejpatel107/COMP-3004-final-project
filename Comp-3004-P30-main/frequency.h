/* Frequency Class
 *
 * inherits the QT calss QSlider
 *
 * allows the user to set their desired
 * frequency through a slider.
 *
 * attributes:
 *  value
*/

#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QListView>
#include <QObject>
#include <QLabel>
#include <QLayout>
#include <iostream>

using namespace std;

class Frequency : public QSlider
{

    Q_OBJECT

public:
    explicit Frequency(QWidget *parent = nullptr);
    ~Frequency();
    int getValue();   // getter for frequency value selected from slider.

private:
    int value;      // stores the value selected from slider.

private slots:
   // slot for connecting to the signal emitted by the slider when moved.
   void setFrequencyValue(int);
   //resets the value of the slider
   void enableFrequencyChange();


};

#endif // FREQUENCY_H
