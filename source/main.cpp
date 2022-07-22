#include "MicroBit.h"
#include "Tests.h"

MicroBit uBit;



void pressedA(MicroBitEvent)
{
    uBit.display.print("Aa");
}

void pressedB(MicroBitEvent)
{
    uBit.display.print("Bb");
}

void pressedAB(MicroBitEvent)
{
    uBit.display.print("Cc");
}

void buttons(){
    uBit.messageBus.listen(DEVICE_ID_BUTTON_A, DEVICE_BUTTON_EVT_CLICK, pressedA);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_B, DEVICE_BUTTON_EVT_CLICK, pressedB);
    uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, pressedAB);

    while(1)
        uBit.sleep(1000);
}

int 
main()
{
    uBit.init();
    // buttons();
    ble_test();

}