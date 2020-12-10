#include<Arduino.h>
#include<Pin.h>

DigitalPin::DigitalPin(int pin): Pin(pin){

}

DigitalPin::DigitalPin(int pin, int mode, int status): Pin(pin){
    _mode = mode;
    _status = status;
}

DigitalPin::~DigitalPin(){
    _mode = INPUT;
    _status = LOW;
}

void setMode(int mode){
    _mode = mode;
}

void set(bool status){
    if(_mode==OUTPUT){
        _status = status;
        digitalWrite(_pin, _status);
    }
}

void toggle(){
    if(_mode==OUTPUT){
        _status = !_status;
        digitalWrite(_pin, _status);
    }
}

bool DigitalPin::get(){
    return _status;
}

