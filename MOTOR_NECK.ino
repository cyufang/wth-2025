#include <AFMotor.h>

AF_DCMotor motor1(3); // M1 port
AF_DCMotor motor2(2);

void setup() {
  motor1.setSpeed(200); // max 
  motor2.setSpeed(200);
}

void loop() {
  int n = 2000;
  motor1.run(BACKWARD);
//  motor2.run(FORWARD);
  delay(n);
  
//  motor1.run(RELEASE); 
//  motor2.run(RELEASE); 
//  delay(1000);
//  
//  motor1.run(FORWARD); 
//  motor2.run(BACKWARD); 
//  delay(n);
}
