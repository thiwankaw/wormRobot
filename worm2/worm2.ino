#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

int leftpin = A1;
int rightpin = A0;

int leftPinVal = 0;
int rightPinVal = 0;

int ditected = 3;

Servo turnerServo;

int d = 400;
int x = 0;

void setup() {


  Serial.begin(9600);
  myservo1.attach(3);
  myservo2.attach(4);
  myservo3.attach(5);
  myservo4.attach(6);
  myservo5.attach(7);
  myservo6.attach(8);


  turnerServo.attach(9);
  initialize();
  delay(300);

}


void readSensors() {

  leftPinVal = analogRead(leftpin);
  rightPinVal = analogRead(rightpin);
  Serial.println(leftPinVal);
  Serial.println(rightPinVal);
  Serial.println("----");
}



void left() {
  turnerServo.write(80);

}

void right() {
  turnerServo.write(130);

}

void straight() {
  turnerServo.write(105);

}



void checkline() {
 
if ( leftPinVal < 80 && rightPinVal < 80) {
    ditected = 3;
    straight();
  }

  if ( leftPinVal > 80 && rightPinVal > 80) {
    ditected = 3;
    straight();
  }

  if ( leftPinVal > 80 && rightPinVal < 80) {
    ditected = 3;
    right();
  }

  if ( leftPinVal < 80 && rightPinVal > 80) {
    ditected = 3;
    left();
  }
}

void loop() {
  readSensors();
  checkline();

//  step1();
//  delay(d);
//  step2();
//  delay(d);
//
//  readSensors();
//  checkline();
//  
//  step3();
//  delay(d);
//  step4();
//  delay(d);
//  step5();
  delay(d);
}


void initialize() {
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(90);
  turnerServo.write(105);


}

void step1() {
  myservo1.write(135);
  myservo2.write(45);
  myservo3.write(45);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(90);

}

void step2() {
  myservo1.write(45);
  myservo2.write(45);
  myservo3.write(135);
  myservo4.write(135);
  myservo5.write(90);
  myservo6.write(90);
}


void step3() {
  myservo1.write(90);
  myservo2.write(135);
  myservo3.write(135);
  myservo4.write(45);
  myservo5.write(45);
  myservo6.write(90);
}
void step4() {
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(45);
  myservo4.write(45);
  myservo5.write(135);
  myservo6.write(135);
}

void step5() {
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(135);
  myservo5.write(135);
  myservo6.write(15);
}

