#include "MicroBit.h"
#include "Tests.h"
#include <string>

extern MicroBit uBit;

void display_number(uint8_t n){
    if(n>25)
        n = 25;
    for(uint8_t i=0;i<n;i++){
        uBit.display.image.setPixelValue(i%5,i/5,200);
    }
}


void ble_test_scan()
{

    bool scan_flag;
    uBit.display.setBrightness(70);

    uBit.display.scroll("B");

    uBit.ble->initializeScan();

    uBit.ble->startScanning();

    uBit.display.scroll('S');



    while(1){
        uBit.display.print("s");
        uBit.sleep(250);
        uBit.display.clear();
        scan_flag = uBit.ble->getFlag();
        if(scan_flag){

            LightricityData data = uBit.ble->getScanResults();
            unsigned int lux = data.getLux();
            // if(lux)               
            //     while(1)
            //         uBit.display.scroll(std::to_string(lux));
        }
        uBit.sleep(250);
    }
    
}

