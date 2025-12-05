// L298N Motor Driver Pins
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;

// Joystick Pins
int VRx = A0;
int VRy = A1;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(VRx); // Left / Right
  int yValue = analogRead(VRy); // Forward / Backward

  int speedX = map(xValue, 0, 1023, -255, 255);
  int speedY = map(yValue, 0, 1023, -255, 255);

  // Motor control logic
  int leftMotor = speedY + speedX;
  int rightMotor = speedY - speedX;

  leftMotor = constrain(leftMotor, -255, 255);
  rightMotor = constrain(rightMotor, -255, 255);

  // Apply motor speeds
  setMotor(IN1, IN2, leftMotor);
  setMotor(IN3, IN4, rightMotor);

  delay(10);
}

void setMotor(int pin1, int pin2, int speed) {
  if (speed > 0) {
    analogWrite(pin1, speed);
    analogWrite(pin2, 0);
  } else if (speed < 0) {
    analogWrite(pin1, 0);
    analogWrite(pin2, -speed);
  } else {
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
  }
}
