

#include <Servo.h>

Servo rightServo, leftServo, rotationServo, gripperServo;

int posR,posL,posG,posRO;  // variable to store the servo position


void setup() {
  Serial.begin(9600);
  pinMode(4,INPUT);
  rightServo.attach(11); 
  leftServo.attach(10);
  gripperServo.attach(9);
  rotationServo.attach(6);
  leftServo.write(110);
  rightServo.write(180);
  gripperServo.write(100);
  rotationServo.write(0);
}


void loop() { 
  Serial.println(digitalRead(4));
  if(digitalRead(4) == LOW){
    rightDown();
    delay(2000);
    gripperServo.write(100);
    delay(500);
    leftDown();
    delay(5000);
    gripper_close();
    delay(2000);
    leftUP();
    delay(2000);
    rightUP();
    delay(5000);
    rotate_to_rightside();
    delay(3000);
    rightDown();
    delay(2000);
    leftDown();
    delay(5000);
    gripper_open();
    delay(3000);
    leftUP();
    delay(2000);
     gripper_close();
    delay(2000);
    rightUP();
    delay(5000);
    rotate_to_leftside();
    delay(3000);
  }

  

//  // put your main code here, to run repeatedly:
//  for (posR = 180,posL = 110; posR >= 120 && posL <= 160; posR--,posL++) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    rightServo.write(posR);
////    leftServo.write(posL);// tell servo to go to position in variable 'pos'
//    delay(20);                       // waits 15 ms for the servo to reach the position
//  }
//  delay(100);
//  for (posR = 120,posL = 160; posR <= 180 && posL >= 110; posR ++,posL--) { // goes from 180 degrees to 0 degrees
//    rightServo.write(posR);
////    leftServo.write(posL);// tell servo to go to position in variable 'pos'
//    delay(20);                       // waits 15 ms for the servo to reach the position
//  }

}

void rightDown(){
  for (posR = 180; posR >= 120; posR--) { 
    rightServo.write(posR);
    delay(20);
  }
}

void leftDown(){
   for (posL = 110;posL <= 147;posL++) { 
    // in steps of 1 degree
    leftServo.write(posL);
    delay(20);                      
  }
}

void rightUP(){
   for (posR = 120; posR <= 180; posR ++) { // goes from 180 degrees to 0 degrees
    rightServo.write(posR);
    delay(20);                       // waits 15 ms for the servo to reach the position
  }
}

void leftUP(){
  for (posL = 147; posL >= 110;posL--) { // goes from 180 degrees to 0 degrees
    leftServo.write(posL);// tell servo to go to position in variable 'pos'
    delay(20);                      // waits 15 ms for the servo to reach the position
  }
}

void gripper_close(){
  for(posG = 100; posG <= 150; posG ++){
    gripperServo.write(posG);
    delay(20);
  }
}

void gripper_open(){
  for(posG = 150; posG >= 100; posG --){
    gripperServo.write(posG);
    delay(20);
  }
}


void rotate_to_rightside() {
  for (posRO = 0; posRO <= 90; posRO += 1) { 
    // in steps of 1 degree
    rotationServo.write(posRO);              
    delay(20);                      
}
}

void rotate_to_leftside(){
  for (posRO = 90; posRO >= 0; posRO -= 1) { 
    rotationServo.write(posRO);              
    delay(20);                       
  }
}
