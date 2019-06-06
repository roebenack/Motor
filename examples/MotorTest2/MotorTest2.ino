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
  motor.forward();   delay(T);
  motor.right();     delay(T);
  motor.backward();  delay(T);
  motor.left();      delay(T);
}
