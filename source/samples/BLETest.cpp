#include "MicroBit.h"
#include "Tests.h"

extern MicroBit uBit;
MicroBitUARTService *uart;

// we use events abd the 'connected' variable to keep track of the status of the Bluetooth connection
void onConnected(MicroBitEvent)
{
    uBit.display.print("C");
}

void onDisconnected(MicroBitEvent)
{
    uBit.display.print("D");
}

void onDelim(MicroBitEvent)
{
    ManagedString r = uart->readUntil("\r\n");
    uart->send(r);
}

void ble_test()
{

    uBit.display.scroll("BLE serv");

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
    
    uBit.messageBus.listen(MICROBIT_ID_BLE_UART, MICROBIT_UART_S_EVT_DELIM_MATCH, onDelim);

    new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);
    new MicroBitButtonService(*uBit.ble);
    new MicroBitIOPinService(*uBit.ble, uBit.io);
    new MicroBitLEDService(*uBit.ble, uBit.display);
    new MicroBitMagnetometerService(*uBit.ble, uBit.compass);
    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);

    uart = new MicroBitUARTService(*uBit.ble, 32, 32);
    uart->eventOn("\r\n");

    release_fiber();
}

