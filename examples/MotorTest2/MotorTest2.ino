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

int T=500; // Time in ms

void loop()
{
  // forward
  motor.forward();   delay(T);
  // right
  motor.right();     delay(T);
  // backward
  motor.backward();  delay(T);
  // left
  motor.left();      delay(T);
}
