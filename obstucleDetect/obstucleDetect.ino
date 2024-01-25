// Define motor control pins
int motor1Pin1 = 2;  // Motor 1 control pin 1
int motor1Pin2 = 3;  // Motor 1 control pin 2
int motor2Pin1 = 4;  // Motor 2 control pin 1
int motor2Pin2 = 5;  // Motor 2 control pin 2

// Define IR sensor pins
int irSensorPin = 6;  // IR sensor output pin
int irSensor2 = 7;    // Second IR sensor output pin
int touchPin = 8;

void setup() {
  // Set motor control pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set IR sensor pins as input
  pinMode(irSensorPin, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(touchPin, INPUT);

  // Initialize serial communication for debugging
  // Serial.begin(9600);
}

void loop() {
  // Read IR sensor values
  int obstacleDetected = digitalRead(irSensorPin);
  int obstacleDetected2 = digitalRead(irSensor2);
  int whenTouch = digitalRead(touchPin);

  // Debugging output
  // Serial.println(obstacleDetected);

  // If both sensors are off, move forward
  // if (obstacleDetected == HIGH && obstacleDetected2 == HIGH) {
  //   moveForward();
  // }

  if (obstacleDetected == HIGH && obstacleDetected2 == HIGH && whenTouch == HIGH) {
    moveForward();
  }
  // If right sensor is active, move right
  else if (obstacleDetected == LOW && obstacleDetected2 == HIGH) {
    moveRight();
  }
  // If left sensor is active, move left
  else if (obstacleDetected == HIGH && obstacleDetected2 == LOW) {
    moveLeft();
  }
   else {
    // If both sensors are active or no sensors are active, stop
    stopAll();
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void moveLeft() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void moveRight() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stopAll() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
