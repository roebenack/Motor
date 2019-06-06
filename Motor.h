/*
  Motor.h - Library for motor control
  Created by Klaus Röbenack, 2015, 2019
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

#ifndef VMAX
#define VMAX 255
#endif

#ifndef VMIN
#define VMIN  40
#endif

class Motor {
  protected:
  // Pins for direction
  byte DIRA, DIRB;
  // Pins for PWM
  byte PWMA, PWMB;
  public:
  // Constructor
  Motor (byte=12, byte=13, byte=3, byte=11);
  // Initialization
  void begin();
  // Motor A: left
  void writeA (int speed)
    { setValues (DIRA, PWMA, speed); };
  // Motor B: right
  void writeB (int speed) 
    { setValues (DIRB, PWMB, speed); };
  // Motor A and B
  void write (int, int);
  // Typical maneuvers
  void forward  (byte speed=VMAX) {write (+speed,+speed); };
  void backward (byte speed=VMAX) {write (-speed,-speed); };
  void right (byte speed=VMAX)    {write (+speed,-speed); };
  void left  (byte speed=VMAX)    {write (-speed,+speed); };
  void stop ()                    {write (0,0); };
  private:
  void setValues (byte, byte, int);
};

#endif
