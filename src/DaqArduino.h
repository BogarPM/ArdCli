#ifndef DaqArduino_h
#define DaqArduino_h

#define STREAM Serial   //Serial to console
//#define ESP_Serial      //Serial to ESP8266 Module

#define PIN_PARAMETER "pin"
#define TYPE_PARAMETER "type"
#define STATUS_PARAMETER "st"

#define MAX_PINS 20
#define JSON_DOC_LENGHT 300


#include <Arduino.h>
#include<pinConfig.h>
#include<ArduinoJson.h>

class DaqArduino
{
private:
    /* data */
    void init();
    void send();
    char* getJson();
    bool _pinConfig; //if true: pins are already configured
    bool _statusInterchange; //allows the data transmit between Arduino and ESP8266

    pinConfig _pins[MAX_PINS];
    StaticJsonDocument<JSON_DOC_LENGHT> _doc;   //thougth to pass small json objects when a change is detected
                                    //in the pins

public:
    DaqArduino();
    ~DaqArduino();
    void daqLoop();
    void log(Print& stream);
    void addPin(int pin, int type = Digital_INPUT_PIN, bool stat = 1);
    void setupPins(char* json);
};

#endif