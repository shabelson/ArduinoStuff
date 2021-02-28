int ind;
bool test;
int delta;
long noise;
String y;
void setup() {
Serial.begin(9600);
ind = 0;
delta = 1;
test = true;
}

void loop() {
  
 if (test ==true){
  ind+=delta;
 }
 else{
  ind-=delta;
   }
 
if (ind>20){test =false;}
else if(ind<1){test=true;}
noise = random(0,)+ind*100;

Serial.print(noise);
Serial.print(",");

}
