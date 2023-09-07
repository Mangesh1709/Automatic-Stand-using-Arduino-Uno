const int irSensorPin = 2; // input pin for IR speed sensor

unsigned long startTime; // variable to store start time
unsigned long elapsedTime; // variable to store elapsed time
float speed; // variable to store speed in RPM

void setup() {
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
  
  // print speed to serial monitor
  Serial.print("Speed (RPM): ");
  Serial.println(speed);
  
  // delay for a short period to reduce noise
  delay(1000);
}