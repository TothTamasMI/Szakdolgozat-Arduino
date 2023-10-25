#include <AFMotor.h>
#include <Servo.h>   

int servo_position = 0;
Servo servoMotor;

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR34_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);

int delayTime = 5;
int motorRunTime = 2000;
int motorSpeed = 230;

//Value from the android device
char value;

void setup(){
  servoMotor.attach (10); 

  Serial.begin(9600);
  servoTurnMiddle();
}
 
void loop(){
  //Read the value from the bluetooth connection
  if (Serial.available() > 0) {
    value = Serial.read();
  }

  if(value == 'F'){
    goForwardStraight();
    setSpeedForMotors(255);
  }

  else if(value == 'B'){
    goBackwardStraight();
    setSpeedForMotors(255);
  }

  else if(value == 'D'){
    motorsRelase();
    servoTurnMiddle();
  }

  else if(value == 'L'){
    servoTurnLeft();
  }

  else if(value == 'R'){
    servoTurnRight();
  }
}

void servoTest(){
  servoTurnMiddle();
  delay(motorRunTime);

  servoTurnRight();
  delay(motorRunTime);

  servoTurnMiddle();
  delay(motorRunTime);

  servoTurnLeft();
  delay(motorRunTime);

  servoTurnMiddle();
  delay(motorRunTime);
}

void motorTestForward(){
  goForwardStraight();

  setSpeedForMotors(63);
  delay(motorRunTime);

  setSpeedForMotors(127);
  delay(motorRunTime);

  setSpeedForMotors(191);
  delay(motorRunTime);

  setSpeedForMotors(255);
  delay(motorRunTime);

  motorsRelase();
  delay(motorRunTime);
}

void motorTestBackward(){
  goBackwardStraight();

  setSpeedForMotors(63);
  delay(motorRunTime);

  setSpeedForMotors(127);
  delay(motorRunTime);

  setSpeedForMotors(191);
  delay(motorRunTime);

  setSpeedForMotors(255);
  delay(motorRunTime);

  motorsRelase();
  delay(motorRunTime);
}

void goForwardStraight(){
  motorsRunForward();
  delay(delayTime);
  servoTurnMiddle();
}

void goBackwardStraight(){
  motorsRunBackward();
  delay(delayTime);
  servoTurnMiddle();
}

void goForwardRight(){
  motorsRunForward();
  delay(delayTime);
  servoTurnRight();
}

void goForwardLeft(){
  motorsRunForward();
  delay(delayTime);
  servoTurnLeft();
}

void goBackwardRight(){
  motorsRunBackward();
  delay(delayTime);
  servoTurnRight();
}

void goBackwardLeft(){
  motorsRunBackward();
  delay(delayTime);
  servoTurnLeft();
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
  servoMotor.write(0);
}

void servoTurnRight(){
  servoMotor.write(180);
}

void servoTurnMiddle(){
  servoMotor.write(90);
}
