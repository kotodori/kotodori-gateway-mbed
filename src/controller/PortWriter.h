#ifndef KOTODORI_GATEWAY_MBED_CONTROLLER_PORTWRITER_H
#define KOTODORI_GATEWAY_MBED_CONTROLLER_PORTWRITER_H

#include <vector>

#include <mbed.h>

namespace controller {
    class PortWriter {
    public:
        PortWriter(InterruptIn &clockIn, InterruptIn &latchIn, DigitalIn &dataIn, DigitalOut &dataOut);

        void write(const std::vector<unsigned char> &data);
    private:
        InterruptIn &clockIn;
        InterruptIn &latchIn;
        DigitalIn &dataIn;
        DigitalOut &dataOut;

        volatile bool done;

        void onLatch();

        void onClock();
    };
}


#endif //KOTODORI_GATEWAY_MBED_CONTROLLER_PORTWRITER_H
