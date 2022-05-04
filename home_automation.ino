#include<Servo.h>
Servo servo1;
Servo servo2;
int pos=0;
String text;

void setup() {
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600);
servo1.attach(10);
servo2.attach(11);

}

void loop() {
  while(Serial.available())
  {
    char c = Serial.read();
    text += c ;
    delay(10);
  }
  if(text.length()>0)
  {
    if(text == "fon" ){
     digitalWrite(7,HIGH); 
    }
    if(text == "foff" ){
     digitalWrite(7,LOW); 
    }
    if(text == "lon" ){
     digitalWrite(8,HIGH); 
    }
    if(text == "loff" ){
     digitalWrite(8,LOW); 
    }
    if(text == "don" ){
     for(pos=0;pos<=90;pos++)
     {
      servo1.write(pos); 
     }
    }
    if(text == "doff" ){
      for(pos=90;pos>=0;pos--)
     {
      servo1.write(pos); 
     }
    }
      if(text == "won" ){
     for(pos=0;pos<=90;pos++)
     {
      servo2.write(pos); 
     }
    }
    if(text == "woff" ){
      for(pos=90;pos>=0;pos--)
     {
      servo2.write(pos); 
     }
    }  
  }
  

}
