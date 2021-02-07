#ifndef KOTODORI_GATEWAY_MBED_CONTROLLER_PORT_H
#define KOTODORI_GATEWAY_MBED_CONTROLLER_PORT_H

#include <vector>

#include <mbed.h>

namespace controller {
    class Port {
    public:
        Port();

        void write(const std::vector<unsigned char> &data);

    private:
        InterruptIn clockIn;
        InterruptIn latchIn;
        DigitalIn dataIn;
        DigitalOut dataOut;
    };
}


#endif //KOTODORI_GATEWAY_MBED_CONTROLLER_PORT_H
