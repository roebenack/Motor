/*
  Test of Motor Library
  Created 2015, 2019 by Klaus Röbenack
*/

#include <Motor.h>

// Create instance of Motor class
Motor motor(12, 13, 3, 11);

// Initialization
void setup()
{
  motor.begin();
}

int V=200; // PWM values
int T=500; // Time in ms

void loop()
{
  // forward
  motor.write ( V, V); delay(T);
  // right
  motor.write ( V,-V); delay(T);
  // backward
  motor.write (-V,-V); delay(T);
  // left
  motor.write (-V, V); delay(T);
}
