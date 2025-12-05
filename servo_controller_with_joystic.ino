#include <Servo.h>

Servo myServo;

int joyX = A0;   // Joystick X-axis pin
int pos = 0;     // Servo position

void setup() {
  myServo.attach(9);   // Servo signal pin
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(joyX);              // Read joystick
  pos = map(xValue, 0, 1023, 0, 180);         // Convert to servo angle

  pos = constrain(pos, 0, 180);               // Limit movement
  myServo.write(pos);                         // Move servo

  delay(10); // Smooth operation
}
