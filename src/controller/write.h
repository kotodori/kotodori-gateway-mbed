#ifndef KOTODORI_GATEWAY_MBED_CONTROLLER_WRITE_H
#define KOTODORI_GATEWAY_MBED_CONTROLLER_WRITE_H

#include <vector>

#include <mbed.h>

namespace controller {
    namespace port {
        void write(const std::vector<unsigned char> &data);
    }
}


#endif //KOTODORI_GATEWAY_MBED_CONTROLLER_WRITE_H
