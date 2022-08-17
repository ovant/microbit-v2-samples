#include "MicroBit.h"
#include "Tests.h"
#include <string>

extern MicroBit uBit;

void ble_test_scan()
{

    bool pfoai;
    uBit.display.setBrightness(70);

    uBit.display.scroll("B");

    uBit.ble->initializeScan();

    uBit.ble->startScanning();

    uBit.display.scroll('S');


    while(1){
        uBit.display.print("s");
        uBit.sleep(500);
        uBit.display.clear();
        uBit.sleep(500);
        pfoai = uBit.ble->getFlag();
        // if(uBit.buttonA.isPressed())
        //     uBit.ble->setFlag(true);
        if(pfoai){
            uBit.display.scroll("yey");
        }
    }
    
}

