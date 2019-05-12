#include <Servo.h>

Servo servos[6];

void setup() 
{
  servos[0].attach(11);
  servos[1].attach(3);
  servos[2].attach(5);
  servos[3].attach(6);
  servos[4].attach(9);
  servos[5].attach(10);
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() 
{
  // set the servo position
  for(int i = 0; i < 6; i++)
  {
    String input = Serial.readStringUntil(',');
    int angle = input.toInt();
    servos[i].write(angle);
  }
  
  // wait for the servo to get there
  delay(15);
}
