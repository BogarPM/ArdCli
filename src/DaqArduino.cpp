#include<Arduino.h>
#include<DaqArduino.h>
#include<pinConfig.h>

DaqArduino::DaqArduino(){
    Serial.println("Works!");
    init();
}

DaqArduino::~DaqArduino(){

}

void DaqArduino::init(){
    //Serial.println("From init function");
}

void DaqArduino::daqLoop(){
    Serial.println("from loop");
    _pins.toggle();
    //deiay()
    delay(20);
}

void DaqArduino::log(Print& stream){
    stream.println("debug info works");
}

void DaqArduino::addPin(int pin, int type, bool stat){
    _pins = pinConfig(pin,type,stat);
}