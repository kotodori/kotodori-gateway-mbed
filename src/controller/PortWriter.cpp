#include <functional>

#include "PortWriter.h"

controller::PortWriter::PortWriter(InterruptIn &clockIn, InterruptIn &latchIn, DigitalIn &dataIn, DigitalOut &dataOut) :
        clockIn(clockIn), latchIn(latchIn), dataIn(dataIn), dataOut(dataOut) {}

void controller::PortWriter::write(const vector<unsigned char> &data) {
    clockIn.rise(std::bind(std::mem_fn(&controller::PortWriter::onClock), this));
    latchIn.rise(std::bind(std::mem_fn(&controller::PortWriter::onLatch), this));
    done = false;
    while (!done);
}

void controller::PortWriter::onLatch() {

}

void controller::PortWriter::onClock() {

}
