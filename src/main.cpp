#include <mbed.h>

#include "controller/Client.h"

controller::Client client;
DigitalOut led(LED2);

int main() {
    const auto hello = "Hello, world!";

    client.writeData(std::vector<unsigned char>(hello, hello + std::strlen(hello)));

    while (true) {
        led = !led;
        ThisThread::sleep_for(std::chrono::milliseconds(500));
    }
}
