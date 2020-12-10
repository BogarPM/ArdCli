#include<Pin.h>
#include<Arduino.h>

Pin::Pin(int pin){
    _pin = pin;
}

Pin::~Pin(){
    _pin = -1;
}

void Pin::setPin(int pin){
    _pin = pin;
}