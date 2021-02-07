#ifndef KOTODORI_GATEWAY_MBED_CLIENT_H
#define KOTODORI_GATEWAY_MBED_CLIENT_H

#include <queue>
#include <vector>
#include <array>
#include <cstdint>

template<class Writer>
class Client {
public:
    Client(Writer writer) : writer(writer) {
    }

    void enqueueDataToWrite(const std::vector<unsigned char> data) {
        writeQueue.emplace(data);
    }

    void flush() {
        while (!syncToWritePacket());
    }

private:
    Writer writer;
    std::queue<const std::vector<unsigned char>> writeQueue;

    /**
     * @return ack が返された場合は true
     */
    bool syncToWritePacket() {
        const auto syncPacket = buildPacket(true, false, {});
        writer.write(syncPacket);
    }

    std::vector<unsigned char> &&buildPacket(const bool syn, const bool ack, const std::vector<unsigned char> &data) {
        std::vector<unsigned char> packet;
        packet.reserve(2 + data.size());

        const auto header = buildPacketHeader(syn, ack, data);
        packet.emplace_back(header[0]);
        packet.emplace_back(header[1]);

        for (const auto b : data) {
            packet.emplace_back(b);
        }

        return std::move(packet);
    }

    std::array<unsigned char, 2> &&
    buildPacketHeader(const bool syn, const bool ack, const std::vector<unsigned char> &data) {
        // 0b00sa'0000
        const unsigned char flags = ((syn ? 1 : 0) << 5) + ((ack ? 1 : 0) << 4);
        return {
                // 0b00sa'llll
                flags + ((data.size() >> 8) & 0b0000'1111),
                // 0bllll'llll
                unsigned char(data.size() & 0b1111'1111),
        };
    }
};


#endif //KOTODORI_GATEWAY_MBED_CLIENT_H
