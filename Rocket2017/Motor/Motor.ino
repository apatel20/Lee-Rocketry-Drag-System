// Basic sketch for trying out the Adafruit DRV8871 Breakout

#define MOTOR_IN1 9
#define MOTOR_IN2 10

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {
    digitalWrite(MOTOR_IN1, HIGH);
    delay(1000);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    delay(1000);
    digitalWrite(MOTOR_IN2, LOW);
}
