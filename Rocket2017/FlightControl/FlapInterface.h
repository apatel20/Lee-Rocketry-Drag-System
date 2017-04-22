#ifndef FLAP_INTERFACE_H
#define FLAP_INTERFACE_H

class FlapInterface
{
    public:
    
        FlapInterface(uint8_t pospin, uint8_t negpin, uint8_t maxstate)
        {
            this->pospin = pospin;
            this->negpin = negpin;
            this->maxstate = maxstate;
            state = 0;
            pinmode(pospin, OUT);
            pinmode(negpin, OUT);
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
    
        void FlapControl::kill()
        {
            digitalWrite(pospin, LOW);
            digitalWrite(negpin, HIGH);
        }
        
    private:
    	
        uint8_t state;
        uint8_t maxstate;
        uint8_t pospin;
        uint8_t negpin;
};

#endif
