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


void ble_test_scan()
{

    
    uBit.display.setBrightness(70);

    uBit.display.scroll("B");

    uBit.ble->startScanning();

    // uBit.display.scroll('S');

    while(1){
        uBit.display.print("s");
        uBit.sleep(250);
        uBit.display.clear();
        bool scan_flag;
        scan_flag = uBit.ble->getFlag();
        if(scan_flag){
            LightricityData data = uBit.ble->getScanResults();
            if(data.getTemp())               
                while(1){
                    uBit.display.scroll(data.getTempString());
                    uBit.display.scroll(data.getButton());
                }
        }
        uBit.sleep(250);
    }
    
}

