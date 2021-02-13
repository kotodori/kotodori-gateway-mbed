#include <mbed.h>

#include "controller/Client.h"

controller::Client client;
DigitalOut out(LED2);

int main() {
    const auto hello = "Hello, world!";

    client.writeData(std::vector<unsigned char>(hello, hello + std::strlen(hello)));

    while (true) {
        out = !out;
        ThisThread::sleep_for(std::chrono::milliseconds(500));
    }
}
