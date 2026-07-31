 

// three variables needed to control speed and rotation of each motor  

int motorLeftEnable = 9; 

int motorLeftForward = 12; 

int motorLeftBackward = 11; 

 

int motorRightEnable = 3; 

int motorRightForward = 8; 

int motorRightBackward = 7; 

 

void setup() { 

 

  // all six pins on the L298N module send signals to the motors 

  pinMode(motorLeftForward, OUTPUT); 

  pinMode(motorLeftBackward, OUTPUT); 

  pinMode(motorRightForward, OUTPUT); 

  pinMode(motorRightBackward, OUTPUT); 

 

  pinMode(motorLeftEnable, OUTPUT); 

  pinMode(motorRightEnable, OUTPUT); 

 

  // ensures all motors are off from the start 

  digitalWrite(motorLeftBackward, LOW); 

  digitalWrite(motorRightBackward, LOW); 

  digitalWrite(motorLeftForward, LOW); 

  digitalWrite(motorRightForward, LOW); 

   

} 

 

void loop() { 

 

  // set speed of DC motor - max is 255 

  // note that PWM pins used because the speed of each motor can be changed 

  analogWrite(motorLeftEnable, 255); 

  analogWrite(motorRightEnable, 255); 

 

  // move forward for 3 seconds 

  digitalWrite(motorLeftForward, HIGH); 

  digitalWrite(motorRightForward, HIGH); 

  delay(3000); 

 

  // turn right (by turning off right motor) for just under one second 

  digitalWrite(motorRightForward, LOW); 

  delay(900); 

 

  // lower speed of both motors 

  analogWrite(motorLeftEnable, 200); 

  analogWrite(motorRightEnable, 200); 

 

  // turn right motor back on (left motor still on from before) - for three seconds 

  digitalWrite(motorRightForward, HIGH); 

  delay(3000); 

 

  // turn right again for one second 

  digitalWrite(motorRightForward, LOW); 

  delay(1000); 

 

  // turn on right motor again 

  // both motors run for 3 seconds 

  digitalWrite(motorRightForward, HIGH); 

  delay(3000); 

 

  digitalWrite(motorRightForward, LOW); 

  delay(750); 

 

  digitalWrite(motorRightForward, HIGH); 

  delay(3000); 

 

  // stop both motors - car should be stationary for 5 seconds before repeating loop() code 

  digitalWrite(motorLeftForward, LOW); 

  digitalWrite(motorRightForward, LOW); 

  delay(5000); 

   

} 

 