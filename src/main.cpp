#include <mbed.h>

InterruptIn button(USER_BUTTON);
DigitalOut out(LED2);

void flip() {
    out = !out;
}

int main() {
    //BufferedSerial pc(USBTX, USBRX);
    //auto buffer = "hogehoge";

    button.rise(&flip);
    while (true) {
       // out = !out;
        //pc.write(buffer, sizeof(buffer));
    }
}
