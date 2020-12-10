#ifndef DaqArduino_h
#define DaqArduino_h

#include <Arduino.h>
#include<pinConfig.h>

class DaqArduino
{
private:
    /* data */
    void init();
    pinConfig _pins;

public:
    DaqArduino();
    ~DaqArduino();
    void daqLoop();
    void log(Print& stream);
    void addPin(int pin, int type = Digital_IO_Pin, bool stat = 1);
};

#endif