#ifndef Pin_h
#define Pin_h

#include<Arduino.h>

class Pin{
    public:
        Pin(int pin);
        ~Pin();
        void setPin(int pin);
    private:
        int _pin;
}
#endif
