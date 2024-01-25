// Define pin numbers
const int touchSensorPin = 2;  // Connect the touch sensor to digital pin 2
const int motor1Pin1 = 3;      // Motor 1 control pin 1
const int motor1Pin2 = 4;      // Motor 1 control pin 2
const int motor2Pin1 = 5;      // Motor 2 control pin 1
const int motor2Pin2 = 6;      // Motor 2 control pin 2

void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set touch sensor pin as INPUT
  pinMode(touchSensorPin, INPUT);
}

void loop() {


   digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  // Check if the touch sensor is HIGH (touched)
  // if (digitalRead(touchSensorPin) == HIGH) {
  //   // Activate the motors
  //   activateMotors();
  // } else {
  //   // Turn off the motors
  //   stopMotors();
  // }
}

void activateMotors() {
  // Run both motors forward
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  // Stop both motors
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
