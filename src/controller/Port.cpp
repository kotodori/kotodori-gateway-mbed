#include "Port.h"

controller::Port::Port() : clockIn(PA_5), latchIn(PA_6), dataIn(PA_7), dataOut(PB_6) {

}

void controller::Port::write(const std::vector<unsigned char> &data) {

}
