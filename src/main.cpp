#include <mbed.h>

int main() {
    DigitalOut out(PA_6);
    BufferedSerial pc(USBTX, USBRX);
    auto buffer = "hogehoge";

    while (true) {
        out = !out;
        pc.write(buffer, sizeof(buffer));
    }
}
