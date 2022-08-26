#include "MicroBit.h"
#include "Tests.h"
// #include <string>

extern MicroBit uBit;

void display_number(int n){
    if(n>50)
        n = 50;
    for(int i=0;i<n;i++){
        uBit.display.image.setPixelValue(i%10/2,i/10,50+200*(i%2));
    }
}

void displayAll(LightricityData data){
    uBit.display.scroll("ID",80);
    uBit.display.scroll(data.getSensorID());
    if(data.getTemp()){
        uBit.display.scroll("T=",80);
        uBit.display.scroll(data.getTempString() + 'C');

    }
    if(data.getHumidity()){
        uBit.display.scroll("H=",80);
        uBit.display.scroll(data.getHumidityString() + '%');

    }
    if(data.getPressure()){
        uBit.display.scroll("P=",80);
        uBit.display.scroll(data.getPressureString() + "Pa");

    }
    if(data.getLux()){
        uBit.display.scroll("lux=",80);
        uBit.display.scroll(data.getLuxString());
    }
    if(data.getCO2()){
        uBit.display.scroll("CO2=",80);
        uBit.display.scroll(data.getCO2String());
    }
    if(data.getVoltage()){
        uBit.display.scroll('V=',80);
        uBit.display.scroll(data.getVoltageString() + "mV");

    }
}


void ble_test_scan()
{

    
    uBit.display.setBrightness(100);

    uBit.display.scroll("Lightricity",90);
 

    uBit.ble->startScanning();

    // uBit.display.scroll('S');

    while(1){
        uBit.display.print("s");
        uBit.sleep(250);
        uBit.display.clear();
        bool scan_flag;
        scan_flag = uBit.ble->getFlag();
        if(scan_flag){
            displayAll(uBit.ble->getScanResults());
        }
        uBit.sleep(250);
    }
    
}

