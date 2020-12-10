#ifndef DigitalPin_h
#define DigitalPin_h

#include<Arduino.h>
//#include<pinConfig.h>
#include "./Pin.h"

#define PWM_MODE 1


class DigitalPin: public Pin {
    public:
        DigitalPin();
        DigitalPin(int pin);
        DigitalPin(int pin, int mode = INPUT, bool status = LOW);
        ~DigitalPin();
        
        void set(bool status);
        void setMode(int mode);
        void toggle();

        bool get();

    protected:
        int _mode;
        bool _status;


};

#endif