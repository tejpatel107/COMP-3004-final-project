/* MainWindow Class
 *
 * inherits the QT class QMainWindow
 *
 * initializes all of the buttons, battery,
 * and display of the program
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QtWidgets>
#include <QStyle>
#include <QPixmap>
#include "button.h"
#include "battery.h"
#include "frequency.h"
#include"display.h"
#include"powerlevel.h"
#include"ui_mainwindow.h"
#include"electrode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Display *display;
    Button *start;
    Button *up;
    Button*down;
    Button*left;
    Button*right;
    Button*ok;
    Button*back;
    Battery *battery;
    PowerLevel *power;
    Frequency *fs;
    Electrode *electrode;
    QCommonStyle *style;
    QLabel *batteryLabel;
    QLabel *powerLevelLabel;
    QLabel *fslabel;
    QLabel *electrodeLabel;

    ~MainWindow();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
