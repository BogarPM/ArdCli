#include "./Pin.h"
#include<Arduino.h>

Pin::Pin(){
    _pin = -1;
}

Pin::Pin(int pin){
    _pin = pin;
}

Pin::~Pin(){
    _pin = -1;
}

void Pin::setPin(int pin){
    _pin = pin;
}

int Pin::pin(){
    return _pin;
}