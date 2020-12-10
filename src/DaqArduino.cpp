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
//Run this function on the main loop function
void DaqArduino::daqLoop(){
    STREAM.println("from loop");
    if(_pinConfig){
        for(int i = 0;i<MAX_PINS;i++){
            if(_pins[i].pin()!=0){
                STREAM.println();
                _pins[i].toggle();
            }else{
                break;
            }
        }
    }
    //_pins.toggle();
    delay(20);
}

void DaqArduino::log(Print& stream){
    stream.println("debug info works");
}

void DaqArduino::addPin(int pin, int type, bool stat){

    //_pins = pinConfig(pin,type,stat);
}


/*Format for recieving the json Pin-Configuration Object
{
    "pn": {
        "pin": pin_number,
        "type": gpio_type,
        "status": defalut_value
    }
}

*/

void DaqArduino::setupPins(char* json){
    DeserializationError err = deserializeJson(_doc,json);
    if(err){
        STREAM.println(err.f_str());
        STREAM.println("Error from inside the class");
        return;
    }
    for(int i = 1;i<MAX_PINS +1;i++){
        char pname[2] = "pn";   //Pin name: p1, p2, p3, ... , pn
        //Convert int i -> char
        char ichar[2];
        String str = String(i);
        str.toCharArray(ichar,2);
        pname[1] = ichar[0];
        /////////////////////////////////////////
        int pin = _doc[pname][PIN_PARAMETER];
        if(pin==0){break;}
        int type = _doc[pname][TYPE_PARAMETER];
        bool st = _doc[pname][STATUS_PARAMETER];
        _pins[i-1] = pinConfig(pin,type,st);
    }
    /*int p1 = _doc["p1"]["pin"];
    int type = _doc["p1"]["type"];
    STREAM.print("Variable P1: ");
    STREAM.println(p1);
    STREAM.print("Type for P1: ");
    STREAM.println(type);*/
    _pinConfig = 1;

}

