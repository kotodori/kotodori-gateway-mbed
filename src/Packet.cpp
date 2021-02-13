#include "Packet.h"

std::pair<Packet, bool> Packet::decode(const std::vector<unsigned char> &raw) {
    if (raw.size() < 2) {
        return std::make_pair(Packet(), false);
    }

    const auto flags = raw[0];
    const bool sync = flags & 0b0010'0000;
    const bool ack = flags & 0b0001'0000;

    return std::make_pair(
            Packet(sync, ack, std::vector<unsigned char>(raw.begin() + 2, raw.end())),
            true
    );
}

Packet::Packet() = default;

Packet::Packet(bool sync, bool ack, std::vector<unsigned char> data) : sync(sync), ack(ack), data(std::move(data)) {}


bool Packet::isSync() const {
    return sync;
}

bool Packet::isAck() const {
    return ack;
}

const std::vector<unsigned char> &Packet::getData() const {
    return data;
}
