#include "electrode.h"

Electrode::Electrode(QWidget *parent) :
    QCheckBox (parent)
{
    move(515,200);
}

Electrode::~Electrode()
{}

void Electrode::sensorOffSkin()
{
    setChecked(false);
}
