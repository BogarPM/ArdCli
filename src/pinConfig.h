#ifndef pinConfig_h
#define pinConfig_h

#include<Arduino.h>


//Types of pin
#define Digital_IO_Pin 1
#define Analog_Pin 2
#define Digital_PWM_Pin 3
//Types of peripherals
#define Serial_Peripheral 4

class pinConfig
{
private:
    /* data */
    int _pin;
    int _type;
    bool _stat;

public:
    pinConfig();
    pinConfig(int pin, int type = Digital_IO_Pin, bool initStat = 1);
    ~pinConfig();
    void toggle();
};

#endif