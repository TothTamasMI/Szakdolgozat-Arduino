#include <AFMotor.h>
#include <Servo.h>   

Servo servoMotor;

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int motorSpeed = 255;

char value;

void setup(){
  servoMotor.attach (10); 
  Serial.begin(9600);
  servoTurnMiddle();
}
 
void loop(){
  if (Serial.available() > 0) {
    value = Serial.read();
  }

  if(value == 'F'){
    goForwardStraight();
    setSpeedForMotors(motorSpeed);
  }

  else if(value == 'B'){
    goBackwardStraight();
    setSpeedForMotors(motorSpeed);
  }

  else if(value == 'D'){
    motorsRelase();
  }

  else if(value == 'L'){
    servoTurnLeft();
  }

  else if(value == 'R'){
    servoTurnRight();
  }

  else if(value == 'C'){
    goChoreography();
  }

  else if(value == 'M'){
    servoTurnMiddle();
  }
}

void goChoreography(){
  servoTurnRight();
  motorsRunForward();
  setSpeedForMotors(motorSpeed);
}

void goForwardStraight(){
  motorsRunForward();
  servoTurnMiddle();
}

void goBackwardStraight(){
  motorsRunBackward();
  servoTurnMiddle();
}

void motorsRunForward(){
  motor4.run(FORWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}

void motorsRunBackward(){
  motor4.run(BACKWARD);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}

void motorsRelase(){
  motor4.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE); 
}

void setSpeedForMotors(int speed){
  motor1.setSpeed(speed);
  motor4.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
}

void servoTurnLeft(){
  servoMotor.write(180);
}

void servoTurnRight(){
  servoMotor.write(0);
}

void servoTurnMiddle(){
  servoMotor.write(90);
}
