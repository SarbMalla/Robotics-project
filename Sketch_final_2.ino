
#include <NewPing.h>
#define TRIGGER_PIN 7
#define ECHO_PIN 6
#define MAX_DISTANCE 150
#define CW 0
#define CCW 1
#define MOTOR_A 0
#define MOTOR_B 1

const byte PWMA = 3; // PWM control (speed) for motor A
const byte PWMB = 11; // PWM control (speed) for motor B
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B

int qreLeft = 0; //connected to Analog 2 
int qreRight = 2; //connected to Analog 0
int croLeft = 5; //diagonal left
int croRight= 1; //diagonal right
byte spd = 150; // forward speed
int threshold = 1000;// threshold for line sensor values. Greater than this means on the line (dark)
// less than this means the sensor is off the line (light)
// The threshold must be determined experimentally for each surface and track as done in the 
// lineSensorChk sketch

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
  setupArdumoto();
}
void loop()
{
  int QRE_Left = analogRead(qreLeft); // Analog output from left sensor 
  int QRE_Right = analogRead(qreRight); // Analog output from right sensor
  int CRO_Left = analogRead(croLeft); // Analog output from diagol left sensor 
  int CRO_Right = analogRead(croRight); // Analog output from diagonal right sensor
  
  delay(50);
  unsigned int uS = sonar.ping();
if(uS / US_ROUNDTRIP_CM > 25 || uS / US_ROUNDTRIP_CM == 0) ////If no object is ahead and both sensors are on the floor, move forward 
{
 
  if (QRE_Left > threshold && QRE_Right > threshold && CRO_Left> threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  ////150);
  stopArdumoto;
  delay(500);
  backRight(150);
}
if (QRE_Left > threshold && QRE_Right < threshold && CRO_Left> threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left > threshold && QRE_Right > threshold && CRO_Left < threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left > threshold && QRE_Right > threshold && CRO_Left> threshold && CRO_Right < threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left < threshold && QRE_Right > threshold && CRO_Left> threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left < threshold && QRE_Right < threshold && CRO_Left > threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left < threshold && QRE_Right > threshold && CRO_Left < threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  backRight(150);
}
if (QRE_Left < threshold && QRE_Right > threshold && CRO_Left > threshold && CRO_Right < threshold) //If both sensors are on the track, move forward
{
  //150);
  backRight(150);
}if (QRE_Left < threshold && QRE_Right < threshold && CRO_Left < threshold && CRO_Right > threshold) //If both sensors are on the track, move forward
{
  //150);
  backRight(150);
}if (QRE_Left < threshold && QRE_Right < threshold && CRO_Left > threshold && CRO_Right < threshold) //If both sensors are on the track, move forward
{
  //150);
  backRight(150);
}if (QRE_Left < threshold && QRE_Right > threshold && CRO_Left < threshold && CRO_Right < threshold) //If both sensors are on the track, move forward
{
  //back(150);
  backRight(150);
}if (QRE_Left < threshold && QRE_Right < threshold && CRO_Left < threshold && CRO_Right < threshold) //If both sensors are on the track, move forward
{
  forward(100);
}
  }
     else if (uS / US_ROUNDTRIP_CM < 50)
  {
    
    turnRight(150);
    delay(150);
  }
}


void driveArdumoto(byte motor, byte dir, byte spd)
{
  if(motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA,spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB,spd);
  }
}
void forward(byte spd)
{
  driveArdumoto(MOTOR_A, CW, spd);
  driveArdumoto(MOTOR_B, CW, spd);
}

void back(byte spd)
{
  driveArdumoto(MOTOR_A, CCW, spd);
  driveArdumoto(MOTOR_B, CCW, spd);
}

void turnRight(byte spd)
{
  stopArdumoto(MOTOR_B);
  driveArdumoto(MOTOR_A, CW, spd);
}

void backRight(byte spd)
{
  stopArdumoto(MOTOR_A);
  driveArdumoto(MOTOR_B, CCW, spd);
}

void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);// stops motor
}

// setupArdumoto initializes all pins 
void setupArdumoto()
{
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
