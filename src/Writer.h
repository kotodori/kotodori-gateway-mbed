#ifndef KOTODORI_GATEWAY_MBED_WRITER_H
#define KOTODORI_GATEWAY_MBED_WRITER_H

class Writer {
public:
    virtual ~Writer() = 0;
    virtual void write(const void *data, size_t length) = 0;
};

#endif //KOTODORI_GATEWAY_MBED_WRITER_H
