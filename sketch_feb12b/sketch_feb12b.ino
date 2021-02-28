#include <string.h>

long t = 1.2;
double g = 2.2;
String s = "";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
s = String(g) + "," +String(t);
Serial.println(s);
}
