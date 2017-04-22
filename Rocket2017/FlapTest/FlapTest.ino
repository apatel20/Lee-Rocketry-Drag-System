#define MOTOR_POSITIVE 9
#define MOTOR_NEGATIVE 10

namespace flaps
{
    void deploy()
    {
        digitalWrite(MOTOR_POSITIVE, LOW);
        digitalWrite(MOTOR_NEGATIVE, HIGH);
    }

    void retract()
    {
        digitalWrite(MOTOR_NEGATIVE, LOW);
        digitalWrite(MOTOR_POSITIVE, HIGH);
    }

    void kill()
    {
        digitalWrite(MOTOR_NEGATIVE, LOW);
        digitalWrite(MOTOR_POSITIVE, LOW);
    }
}

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting motor test.");

    pinMode(MOTOR_POSITIVE, OUTPUT);
    pinMode(MOTOR_NEGATIVE, OUTPUT);
}

void loop()
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

    flaps::kill();
    delay(3000);

    // cyclic stress testing by very fast deployment cycles
    Serial.println("Stress testing flap deployment cycle.");
    for (int i = 0; i < 10; i++)
    {
        cycle(50);
        delay(50);
    }

    flaps::kill();
}

void cycle(uint16_t millis)
{
    flaps::deploy();
    delay(millis);
    flaps::retract();
}
