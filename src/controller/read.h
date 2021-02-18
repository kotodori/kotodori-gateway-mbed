#ifndef KOTODORI_GATEWAY_MBED_PORT_READ_H
#define KOTODORI_GATEWAY_MBED_PORT_READ_H

#include <vector>

namespace controller {
    namespace port {
        void startAutoReading();

        void stopAutoReading();

        /**
         * コントロールポートからパケットを1つ読み取るまでブロックし、読み取られたパケットを返す。
         * stopAutoReading を呼んだ後に呼ばれることを期待している。
         * @return パケット
         */
        std::vector<unsigned char> readOnePacket();
    }
}

#endif //KOTODORI_GATEWAY_MBED_PORT_READ_H
