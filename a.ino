#include <Servo.h>
int trig=10;
int echo=11;
Servo s;
Servo s1;
int w=A0;
void setup()
{
  pinMode(w,INPUT);
   pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  s.attach(8);
  s1.attach(5);
  Serial.begin(9600);
}
void loop() {
  int rain=analogRead(w);
 int duration, distance;
  digitalWrite (trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2) / 29.1;

      Serial.print(distance);   
      Serial.print("cm1");
      Serial.println();
if(distance<3){
  s.write(180);
    delay(1000); }
    if(distance<5){
    s.write(0);
    delay(2000); 
    }
    if(rain<800){
  s1.write(45);
    delay(1000); }
   else{
    s1.write(0);
    delay(30); 
    }
Serial.println(distance);
Serial.println(rain);
}
