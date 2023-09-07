#include <Servo.h>

Servo myServo; // create servo object
int servoPosition = 90; // initial servo position

const int irSensorPin = 2; // input pin for IR speed sensor

unsigned long startTime; // variable to store start time
unsigned long elapsedTime; // variable to store elapsed time
float speed; // variable to store speed in RPM
float minSpeed = 0.0; // minimum speed for servo to turn
float maxSpeed = 10.0; // maximum speed for servo to turn
float speedRange = maxSpeed - minSpeed; // range of valid speeds

void setup() {
  myServo.attach(9); // attach servo to pin 9
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  // read IR sensor value
  int irSensorValue = digitalRead(irSensorPin);
  
  if (irSensorValue == HIGH) {
    // start timer when IR sensor detects object
    startTime = millis();
  } else {
    // stop timer when IR sensor no longer detects object
    elapsedTime = millis() - startTime;
  }
  
  // calculate speed in RPM
  if (elapsedTime > 0) {
    speed = 60000.0 / (float)elapsedTime;
  } else {
    speed = 0.0;
  }
  
  // map speed to servo position
  if (speed < minSpeed) {
    servoPosition = 0; // servo stops
  } else if (speed > maxSpeed) {
    servoPosition = 180; // servo goes to maximum position
  } else {
    float speedPercentage = (speed - minSpeed) / speedRange;
    servoPosition = (int)(speedPercentage * 180.0);
  }
  
  // set servo position
  myServo.write(servoPosition);
  
  // print speed and servo position to serial monitor
  Serial.print("Speed (RPM): ");
  Serial.print(speed);
  Serial.print(", Servo Position: ");
  Serial.println(servoPosition);
  
  // delay for a short period to reduce noise
  delay(1000);
}