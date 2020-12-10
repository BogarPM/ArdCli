#ifndef pinConfig_h
#define pinConfig_h

#include<Arduino.h>


//Types of pin
#define Digital_OUTPUT_PIN 1
#define Digital_INPUT_PIN 2
#define Analog_PIN 3
#define Digital_PWM_PIN 4
//Types of peripherals

#define Serial_Peripheral 5



class pinConfig
{
private:
    /* data */
    int _pin;
    int _type;
    bool _stat;

public:
    pinConfig();
    pinConfig(int pin, int type = Digital_INPUT_PIN, bool initStat = 1);
    ~pinConfig();
    void toggle();
    int pin();
    int type();
    bool stat();
};

#endif