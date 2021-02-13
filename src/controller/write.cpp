#include "write.h"
#include "../BitQueue.h"


static InterruptIn clockIn(PA_5);
static InterruptIn latchIn(PA_6);
static DigitalIn dataIn(PA_7);
static DigitalOut dataOut(PB_6);

static volatile bool writing = false;
static BitQueue *bufferToWrite;

static inline void writeBit() {
    dataOut.write(bufferToWrite->pop());

    if (bufferToWrite->empty()) {
        writing = false;
    }
}

static void onLatch() {
    writeBit();
}

static void onClock() {
    writeBit();
}

void controller::port::write(const vector<unsigned char> &data) {
    latchIn.rise(nullptr);
    clockIn.rise(nullptr);

    writing = true;
    BitQueue buffer(data);
    bufferToWrite = &buffer;

    latchIn.rise(onLatch);
    clockIn.rise(onClock);

    while (writing);

    bufferToWrite = nullptr;
}
