#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NB: This sketch assumes 32 bit addresses

static long int address = 0x66996699L;  // So that's 0x0066996699
const int tries = 10;
RF24 rf(/*ce*/ 8, /*cs*/ 10);

void setup() {
    rf.begin();
    rf.setRetries(15, 15);
    rf.enableDynamicPayloads();
    rf.openWritingPipe(address);
}

void loop() {
    char buf[8] = "\x04" "SKIP";
    if (rf.write(&buf, 5)) delay(200);
}


// vim: ft=cpp
