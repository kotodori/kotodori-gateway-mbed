#include "Client.h"

#include "../Packet.h"
#include "write.h"
#include "read.h"

void controller::Client::writeData(const std::vector<unsigned char> &data) {
    {
        const auto syncPacket = buildPacket(true, false, {});
        while (!writePacket(syncPacket));
    }

    {
        const auto packet = buildPacket(false, true, data);
        while (!writePacket(packet));
    }
}

bool controller::Client::writePacket(const std::vector<unsigned char> &packet) {
    controller::port::write(packet);

    const auto resp = controller::port::readOnePacket();
    const auto decoded = Packet::decode(resp);

    if (!decoded.second) {
        return false;
    }

    return decoded.first.isAck();
}

static std::array<unsigned char, 2>
buildPacketHeader(const bool syn, const bool ack, const std::vector<unsigned char> &data) {
    // 0b00sa'0000
    const unsigned char flags = ((syn ? 1 : 0) << 5) + ((ack ? 1 : 0) << 4);
    return {
            // 0b00sa'llll
            static_cast<unsigned char>(flags + ((data.size() >> 8) & 0b0000'1111)),
            // 0bllll'llll
            static_cast<unsigned char>(data.size() & 0b1111'1111),
    };
}

std::vector<unsigned char>
controller::Client::buildPacket(const bool syn, const bool ack, const std::vector<unsigned char> &data) {
    std::vector<unsigned char> packet;
    packet.reserve(2 + data.size());

    const auto header = buildPacketHeader(syn, ack, data);
    packet.emplace_back(header[0]);
    packet.emplace_back(header[1]);

    for (const auto b : data) {
        packet.emplace_back(b);
    }

    return packet;
}
