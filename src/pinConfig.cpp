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
    if(type==Digital_OUTPUT_PIN){
        //Serial.println("Configured as the init stat parameter");
        pinMode(pin,OUTPUT);
        digitalWrite(pin, initStat);
    }else if(type==Digital_INPUT_PIN){
        pinMode(pin,INPUT);
    }
}

pinConfig::~pinConfig(){
    _pin = -1;
    _type = -1;
    _stat = -1;
}

void pinConfig::toggle(){
    //Serial.println("From toggle");
    if(_type == Digital_OUTPUT_PIN){
        _stat = !_stat;
        digitalWrite(_pin,_stat);
        Serial.println("it should be toggling");
    }
}

int pinConfig::pin(){
    return _pin;
}

int pinConfig::type(){
    return _type;
}

bool pinConfig::stat(){
    return _stat;
}