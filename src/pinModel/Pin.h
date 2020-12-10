#ifndef Pin_h
#define Pin_h

#include<Arduino.h>

#define DIGITAL_PIN 1
#define ANALOG_PIN 2

class Pin{
    public:
        Pin();
        Pin(int pin);
        ~Pin();
        void setPin(int pin);
        int pin();
    protected:
        int _pin;
};
#endif
