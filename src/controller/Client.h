#ifndef KOTODORI_GATEWAY_MBED_CONTROLLER_CLIENT_H
#define KOTODORI_GATEWAY_MBED_CONTROLLER_CLIENT_H

#include <queue>
#include <vector>
#include <array>
#include <cstdint>

namespace controller {
    class Client {
    public:
        void writeData(const std::vector<unsigned char> &data);

    private:
        /**
         * @return ack が返された場合は true
         */
        static bool writePacket(const std::vector<unsigned char> &packet);

        static std::vector<unsigned char> buildPacket(bool syn, bool ack, const std::vector<unsigned char> &data);
    };
}


#endif //KOTODORI_GATEWAY_MBED_CONTROLLER_CLIENT_H
