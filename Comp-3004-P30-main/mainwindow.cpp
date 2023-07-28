#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(250,250,700,700);
    setFixedSize(size());
    setWindowTitle("DENAS PCM6 Simulation");

        display = new Display(this);
        battery = new Battery(100,475,50,this);
        batteryLabel = new QLabel("Battery",this);
        batteryLabel->move(375,50);

        power = new PowerLevel(this);
        powerLevelLabel = new QLabel("Power Level", this);
        powerLevelLabel->move(375,150);

        electrode = new Electrode(this);
        QLabel *electrodeLabel = new QLabel("Placed On Skin",this);
        electrodeLabel->move(375,200);

        fs = new Frequency(this);
        QLabel *fslabel = new QLabel(this);
        fslabel->setText("Frequency");
        fslabel->move(375,100);


        style = new QCommonStyle();

        QPixmap p1(":/resources/images/red-go-back-arrow.png");
        QPixmap p2(":/resources/images/power.webp");

        up = new Button(tr(""),143,300,style->standardIcon(QStyle::SP_ArrowUp),this);
        down  = new Button(tr(""),143,510,style->standardIcon(QStyle::SP_ArrowDown),this);
        left  = new Button(tr(""),25,405,style->standardIcon(QStyle::SP_ArrowLeft),this);
        right  = new Button(tr(""),260,405,style->standardIcon(QStyle::SP_ArrowRight),this);
        start  = new Button(tr(""),260,300, QIcon(p2),this);
        ok = new Button(tr("OK"),143,405,QIcon(),this);
        back  = new Button(tr(""),25,300, QIcon(p1),this);

}





MainWindow::~MainWindow()
{

    delete ui;
    delete display;
    delete battery;
    delete power;
    delete electrode;
    delete fs;
    delete style;
    delete up;
    delete down;
    delete left;
    delete right;
    delete start;
    delete ok;
    delete back;
    delete electrodeLabel;
    delete powerLevelLabel;
    delete batteryLabel;
    delete fslabel;
}


