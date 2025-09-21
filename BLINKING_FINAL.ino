#include <Servo.h>

Servo serv1; 
Servo serv2;

int pos = 0;   

//BLINK EYEBALL
//DO NOT EIDT


void setup() {
  serv1.attach(9);
  serv2.attach(10);
  serv1.write(90);    
  serv2.write(90);    
}

void loop() {
  
  int angle_max = 170;
  int angle_min = 50;

  int angle_mid = 100;

  
  for (pos = angle_min; pos <= angle_max; pos += 1) {
    // in steps of 1 degree
    serv1.write(pos-25);    
    serv2.write(180-pos);    
    delay(4);                     
  }

  for (pos = angle_max; pos >= angle_mid; pos -= 1) {
    // in steps of 1 degree
    serv1.write(pos-25);    
    serv2.write(180-pos);    
    delay(5);                     
  }

  for (pos = angle_mid; pos >= angle_min; pos -= 1) {
    // in steps of 1 degree
    serv1.write(pos-25);    
    serv2.write(180-pos);    
    delay(20);                     
  }
  delay(1000);


  
  
//  serv1.write(0); 
//  serv2.write(0); 
//  delay(500);
//
//  serv1.write(180); 
//  serv2.write(180); 
//  delay(2000);

}
