#include <Servo.h>

const int servoPin = 9;   // Servo motor signal pin

Servo servoMotor;

void setup() {
  servoMotor.attach(servoPin);  // Attach the servo motor to the specified pin
}

void loop() {
  // Rotate the servo motor to 90 degrees (retracted position)
  servoMotor.write(90);
  delay(2000);  // Wait for 2 seconds
  
  // Rotate the servo motor to 180 degrees (extended position)
  servoMotor.write(180);
  delay(2000);  // Wait for 2 seconds
}
