#include <Servo.h>
Servo servo;

void setup() {
  // initialize serial:
  Serial.begin(9600); //set serial monitor baud rate to match
  servo.write(90);
  servo.attach(9);
  
  prntIt();
}

void loop() {

    int pos = 0;
    pos = constrain(pos, 0, 2400);
    servo.write(0);
  
    prntIt();
  }
void prntIt()
{
  Serial.print("  degrees = ");
  Serial.print(servo.read());
  Serial.print("\t");
  Serial.print("microseconds =  ");
  Serial.println(servo.readMicroseconds());
}
