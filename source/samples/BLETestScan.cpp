#include "MicroBit.h"
#include "Tests.h"

extern MicroBit uBit;

void ble_test_scan()
{

    uBit.display.scroll("B");

    uBit.ble->startScanning();

    uBit.display.scroll('S');

    
}

