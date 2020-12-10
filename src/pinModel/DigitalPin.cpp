#include<Arduino.h>
#include "./Pin.h"
#include "./DigitalPin.h"


DigitalPin::DigitalPin(){
    _pin = -1;
    _status = -1;
    _mode = -1;
}

DigitalPin::DigitalPin(int pin): Pin(pin){

}

DigitalPin::DigitalPin(int pin, int mode, bool status): Pin(pin){
    _mode = mode;
    _status = status;
}

DigitalPin::~DigitalPin(){
    _mode = INPUT;
    _status = LOW;
}

void DigitalPin::setMode(int mode){
    _mode = mode;
}

void DigitalPin::set(bool status){
    if(_mode==OUTPUT){
        _status = status;
        digitalWrite(_pin, _status);
    }
}

void DigitalPin::toggle(){
    if(_mode==OUTPUT){
        _status = !_status;
        digitalWrite(_pin, _status);
    }
}

bool DigitalPin::get(){
    return _status;
}

