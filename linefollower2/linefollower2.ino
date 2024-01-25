// Define motor pins for L298N
int leftMotor1 = 9;
int leftMotor2 = 10;
int rightMotor1 = 7;
int rightMotor2 = 8;
int enableRightMotor = 6;
int enableLeftMotor = 7;

// Define IR sensor pins
int leftIR = 11;
int rightIR = 12;


void setup() {
  // Initialize motor pins as outputs
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  // Initialize IR sensor pins as inputs
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = digitalRead(leftIR);
  int rightSensorValue = digitalRead(rightIR);

  // Adjust the threshold based on your sensor readings
  int threshold = 500;

  // Determine the movement based on sensor readings
  if (leftSensorValue > threshold && rightSensorValue > threshold) {
    // Both sensors are on the line, move forward
    moveForward();
  } else if (leftSensorValue > threshold) {
    // Only left sensor is on the line, turn right
    turnRight();
  } else if (rightSensorValue > threshold) {
    // Only right sensor is on the line, turn left
    turnLeft();
  } else {
    // Both sensors are off the line, stop
    stopMotors();
  }
}

// Motor control functions for L298N
void moveForward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void stopMotors() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}
