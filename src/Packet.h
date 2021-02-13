#ifndef KOTODORI_GATEWAY_MBED_PACKET_H
#define KOTODORI_GATEWAY_MBED_PACKET_H

#include <vector>

class Packet {
public:
    static std::pair<Packet, bool> decode(const std::vector<unsigned char> &raw);

    Packet();
    Packet(bool sync, bool ack, std::vector<unsigned char> data);

    bool isSync() const;

    bool isAck() const;

    const std::vector<unsigned char> &getData() const;

private:
    bool sync;
    bool ack;
    std::vector<unsigned char> data;
};


#endif //KOTODORI_GATEWAY_MBED_PACKET_H
