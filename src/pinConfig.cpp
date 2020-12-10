#include<Arduino.h>
#include<pinConfig.h>

pinConfig::pinConfig(){
    _pin = -1;
    _type = -1;
    _stat = -1;
}

pinConfig::pinConfig(int pin, int type, bool initStat){
    _pin = pin;
    _type = type;
    _stat = initStat;
    if(type==Digital_IO_Pin){
        Serial.println("Configured as the init stat parameter");
        pinMode(pin,initStat);
    }else if(type==Digital_PWM_Pin){
        pinMode(pin,OUTPUT);
    }
}

pinConfig::~pinConfig(){
    _pin = -1;
    _type = -1;
    _stat = -1;
}

void pinConfig::toggle(){
    Serial.println("From toggle");
    if(_type == Digital_IO_Pin){
        _stat = !_stat;
        digitalWrite(_pin,_stat);
        Serial.println("it should be toggling");
    }
}