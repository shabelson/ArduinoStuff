#include <Servo.h>

int ang;
int delta;
const int servoPin = 9;
Servo servo_1;




void setup() {
Serial.begin(9600);
servo_1.attach(servoPin);
delta = 1;


}

void loop() {
  // put your main code here, to run repeatedly:
servo_1.write(0);
if (ang>180 || ang<0)
{
  delta = delta*(-1);
}
ang+=delta;
Serial.println(ang);


}
