#include <Servo.h>
#include <Encoder.h>
#include <MINDSi.h>

const int pingL = 11; 
const int pingR = 9;
const int pingC = 10;

const int motorPin = 4;
const int frontSteerPin = 5;
const int backSteerPin = 6;

const int stopDist = 2000;

Servo frontSteer;
Servo backSteer;
Servo drive;

void setup() 
{
 frontSteer.attach(frontSteerPin);
 backSteer.attach(backSteerPin);
 drive.attach(motorPin); 

 frontSteer.write(90);
 backSteer.write(90);
}

void loop() 
{
  if(getPing(pingC) <= stopDist)
  {    
    drive.write(0);
    drive.write(90);
    frontSteer.write(135);
    backSteer.write(45);
    drive.write(110);
    delay(1500);
    drive.write(0);    
    frontSteer.write(45);
    backSteer.write(135);
    drive.write(90);
    drive.write(70);
    delay(500);    
  }
  else
  {
    drive.write(90);
    frontSteer.write(90);
    backSteer.write(90);
    drive.write(70);
  }
}
