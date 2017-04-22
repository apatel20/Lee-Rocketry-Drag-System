#ifndef FLAP_INTERFACE_H
#define FLAP_INTERFACE_H

#include <Arduino.h>

class FlapInterface
{
    public:

        FlapInterface(uint8_t pospin, uint8_t negpin, uint8_t maxstate)
        {
            this->pospin = pospin;
            this->negpin = negpin;
            this->maxstate = maxstate;
            state = 0;
            pinMode(pospin, OUTPUT);
            pinMode(negpin, OUTPUT);
            kill();
        }

        void deploy()
        {
            if (state == maxstate) kill();
            else
            {
                state++;
                digitalWrite(negpin, LOW);
                digitalWrite(pospin, HIGH);
            }
        }

        void retract()
        {
            if (state == 0) kill();
            else
            {
                state--;
                digitalWrite(pospin, LOW);
                digitalWrite(negpin, HIGH);
            }
        }

        void kill()
        {
            digitalWrite(pospin, LOW);
            digitalWrite(negpin, LOW);
        }

    private:

        uint8_t state;
        uint8_t maxstate;
        uint8_t pospin;
        uint8_t negpin;
};

#endif
