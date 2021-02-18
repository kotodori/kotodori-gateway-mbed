
#ifndef KOTODORI_GATEWAY_MBED_BITQUEUE_H
#define KOTODORI_GATEWAY_MBED_BITQUEUE_H

#include <vector>

class BitQueue {
public:
    BitQueue(const std::vector<unsigned char> &bits);

    bool pop();

    bool empty();

private:
    std::vector<bool> data;
    std::vector<bool>::iterator next;
};


#endif //KOTODORI_GATEWAY_MBED_BITQUEUE_H
