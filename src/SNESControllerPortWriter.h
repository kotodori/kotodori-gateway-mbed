#ifndef KOTODORI_GATEWAY_MBED_SNESCONTROLLERPORTWRITER_H
#define KOTODORI_GATEWAY_MBED_SNESCONTROLLERPORTWRITER_H

#include <vector>

class SNESControllerPortWriter {
    void write(const std::vector<unsigned char> &data);
};


#endif //KOTODORI_GATEWAY_MBED_SNESCONTROLLERPORTWRITER_H
