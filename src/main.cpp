#include "mbed.h"

int main()
{
    DigitalOut out(PA_6);

    while (true)
    {
        out = !out;
    }
}
