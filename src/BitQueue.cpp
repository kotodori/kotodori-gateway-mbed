
#include "BitQueue.h"

BitQueue::BitQueue(const std::vector<unsigned char> &bits)  {
    for (const auto d: bits) {
        auto tmp = d;
        for (size_t i = 0; i < sizeof(d) * 8; i++) {
            data.emplace_back(tmp >> 7);
            tmp <<= 1;
        }
    }

    next = data.begin();
}

bool BitQueue::pop() {
    const auto res = *next;
    next++;
    return res;
}

bool BitQueue::empty() {
    return data.end() == next;
}
