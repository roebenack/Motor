# Motor Library for Arduino

## Summary

This library is intended to control motor shields in the [Arduino](https://www.arduino.cc) environment. We assume that the shields are based on the driver circuits L293 or L298 such as the [Arduino Motor Shield Rev3](https://store.arduino.cc/arduino-motor-shield-rev3) or the [Velleman Motor & Power Shield VMA03](https://www.velleman.eu/products/view/?id=412538). The library can control two DC motors. For the application in mobile robotics, Motor A and Motor B are assumed to be mounted on the left and right hand side, respectively, of the robot's chassis.

## References

The implementation of the library is based on the following books, but has been developed further. The books describe several applications.

* Röbenack, Klaus: [*Mobile Robotics with Arduino: Design and Programming*](https://www.amazon.de/dp/1726432335). \[English Edition\]  
  CreateSpace Independent Publishing Platform. 2018.
* Röbenack, Klaus: [*Mobiler Eigenbauroboter mit Arduino: Aufbau und Programmierung*](https://www.amazon.de/dp/1730747892). \[German Edition\]  
  Independently published, 2nd Edition, 2018.

## Usage of the Library

### Preparation

To use the Motor Library you have to include the header file ```Motor.h``` first:

```#include <Motor.h>```

Then, you create an instance ```motor``` of the class ```Motor```. No arguments are needed if you use the [Arduino Motor Shield Rev3](https://store.arduino.cc/arduino-motor-shield-rev3):

```Motor motor;```

However, you could specify the digital pins for the directs and the PWM signals. The constructor without arguments corresponds to

```Motor motor(12, 13, 3, 11);```

The first two arguments specify the directions for the two motors, the last two arguments the associated PWM pins. With this constructor, you could also specify different digital pins. 

The above used pins will be configured are output pins with the method ```Motor::begin```. This method is called once in the function ```setup```:

```void setup () 
{
    motor.begin();
}
```

### Standard Methods

The following functions control motor A, motor B, or both motors simultaneousely. For a 8 bit PWM, the speed values have the range -255...+255. The sign of the value indicated the direction (forward or backward).

Set speed and direction of motor A:

```motor.writeA (int speed)```

Set speed and direction of motor A:

```motor.writeB (int speed)```

Set speed and direction of both motors:

```motor.write (int speedA, int speedB))```


