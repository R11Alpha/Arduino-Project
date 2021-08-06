#include <Servo.h>

Servo servo1;

int PINSERVO = 3;
int PULSOMIN = 1000;
int PULSOMAX = 2000;

void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(180);
  delay(1000);
}
