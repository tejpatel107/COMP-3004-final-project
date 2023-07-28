#include "button.h"

Button::Button(const QString &text,int x, int y, const QIcon icon, QWidget *parent):QPushButton (parent)
{
    move(x,y);
    setGeometry(x,y,90,90);
    setText(text);
    setIcon(icon);
    setIconSize(QSize(80,80));
    setStyleSheet("font: bold; font-size: 18px;");

}


Button::~Button(){

}




