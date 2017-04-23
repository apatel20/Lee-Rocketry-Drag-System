#include <FlapInterface.h>

#define FLAP_POSITIVE 9
#define FLAP_NEGATIVE 10

FlapInterface flaps(FLAP_POSITIVE, FLAP_NEGATIVE, 5);

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting motor test.");
}

void loop()
{
    flaps.deploy();
    delay(3000);
    flaps.kill();
}

void test1()
{
    // test deploy/retract cycle with decreasing periods between
    for (uint16_t millis = 2000; millis > 50; millis /= 2)
    {
        Serial.print("Testing deploy/retract with period: ");
        Serial.print(millis);
        Serial.println(" milliseconds");
        cycle(millis);
        delay(1000);
    }

    flaps.kill();
}

void test2()
{
    // cyclic stress testing by very fast deployment cycles
    Serial.println("Stress testing flap deployment cycle.");
    for (int i = 0; i < 10; i++)
    {
        cycle(50);
        delay(50);
    }

    flaps.kill();
}

void cycle(uint16_t millis)
{
    flaps.deploy();
    delay(millis);
    flaps.retract();
}
