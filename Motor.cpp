/*
  Motor.cpp - Library for motor control
  Created by Klaus Röbenack, 2015, 2019
*/

#include "Arduino.h"
#include "Motor.h"

// Constructor

Motor::Motor (byte pinDIRA, byte pinDIRB,
              byte pinPWMA, byte pinPWMB)
: DIRA(pinDIRA), DIRB(pinDIRB),
  PWMA(pinPWMA), PWMB(pinPWMB)
{
   digitalWrite (PWMA, 0);
   digitalWrite (PWMB, 0);
}

// Initialization
void Motor::begin()
{
  pinMode (DIRA, OUTPUT);
  pinMode (DIRB, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (PWMB, OUTPUT);
}

// Internal function
void Motor::setValues (byte pinDir, byte pinPwm, int speed)
{
  // Direction
  digitalWrite (pinDir, speed>=0 ? LOW : HIGH );
  // Speed (PWM value)
  speed=abs(speed);
  speed=min(speed,VMAX);
  if (speed<VMIN) speed=0; 
  analogWrite(pinPwm, speed);  
}

// Speed for both motors
void Motor::write (int speedA, int speedB)
{
   writeA(speedA);
   writeB(speedB);
}

