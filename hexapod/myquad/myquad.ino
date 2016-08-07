#include <Servo.h>
#include "angles.h"
#include "pins.h"

/*
values 
2=129
4=131
6=133
8=135
Prog + =144
Prog - =145
*/
Servo servo[12]; 
int i=0;

void setup()
{
  pinMode(14,INPUT);
  for(int i=0;i<12;i++)
    servo[i].attach(servo_pin[i]);
  stand_up();
  delay(3000);
  get_ready();
  delay(3000);
}
int flag=0;
void loop()
{
  int val=0;
  if(pulseIn(14,LOW)>2000)
  {
    for(int i=0;i<8;i++)
    {
      if(pulseIn(14,LOW)>1000)
      val+=1<<i;
    }
    delay(50);
  }
  if(val==144)
  flag=0;//normal mode
  if(val==145)
  flag=1;// octo mode
  if(flag==0)
    switch(val)
    {
      case 129:
      forward();
      break;
      case 131:
      turn_left();
      break;
      case 133:
      turn_right();
      break;
      case 135:
      backward();
      break;
    }
  else
    switch(val)
    {
      case 129:
      spider_forward();
      break;
      case 131:
      turn_left();
      break;
      case 133:
      turn_right();
      break;
      case 135:
      spider_backward();
      break;
    }
}

void stand_up()
{
  for(int i=0;i<12;i++)
    servo[i].write(stand_position[i]);  // Set the positions of the servos to the postions in the "angles.h" file
}

void get_ready()
{
  for(int i=0;i<12;i++)
    servo[i].write(moving_position[i]);  // Set the positions of the servos to the postions in the "angles.h" file
}

void forward()
{
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs forward
  {
    move_servo(6,-1);
    move_servo(8,+1);
    move_servo(10,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Raise the Right Front and Left Rear legs
  {    
    move_servo(1,-1);
    move_servo(3,-1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs back &
  {                                 
    move_servo(6,+1);
    move_servo(8,-1);
    move_servo(10,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(7,-1);
    move_servo(9,+1);
    move_servo(11,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(7,+1);
    move_servo(9,-1);
    move_servo(11,+1);
    delay(delay_time); 
  } 
 get_ready(); 
}

void backward()
{
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs forward
  {
    move_servo(6,+1);
    move_servo(8,-1);
    move_servo(10,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Raise the Right Front and Left Rear legs
  {    
    move_servo(1,-1);
    move_servo(3,-1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs back &
  {                                 
    move_servo(6,-1);
    move_servo(8,+1);
    move_servo(10,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(7,+1);
    move_servo(9,-1);
    move_servo(11,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(7,-1);
    move_servo(9,+1);
    move_servo(11,-1);
    delay(delay_time); 
  } 
 get_ready(); 
}

void turn_right()
{
  stand_up();
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs forward
  {
    move_servo(6,+1);
    move_servo(8,+1);
    move_servo(10,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Raise the Right Front and Left Rear legs
  {    
    move_servo(1,-1);
    move_servo(3,-1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs back &
  {                                 
    move_servo(6,-1);
    move_servo(8,-1);
    move_servo(10,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(7,+1);
    move_servo(9,+1);
    move_servo(11,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(7,-1);
    move_servo(9,-1);
    move_servo(11,-1);
    delay(delay_time); 
  }  
 get_ready(); 
}

void turn_left()
{
  stand_up();
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs forward
  {
    move_servo(6,-1);
    move_servo(8,-1);
    move_servo(10,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Raise the Right Front and Left Rear legs
  {    
    move_servo(1,-1);
    move_servo(3,-1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs back &
  {                                 
    move_servo(6,+1);
    move_servo(8,+1);
    move_servo(10,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(7,-1);
    move_servo(9,-1);
    move_servo(11,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(7,+1);
    move_servo(9,+1);
    move_servo(11,+1);
    delay(delay_time); 
  }   
  get_ready();
}
void move_servo(int x,int y)
{
  servo[x].write(servo[x].read()+y); // Read the current position of Servo 'x' and move it by 'y' degrees
}


void spider_forward()
{
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(1,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(7,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(1,+1);
    move_servo(0,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(6,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(11,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(8,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(2,+1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(9,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(3,+1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(10,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(6,+1);
    move_servo(7,+1);
    move_servo(8,-1);
    move_servo(9,-1);
    move_servo(10,-1);
    move_servo(11,+1);
    delay(delay_time); 
  }
  get_ready();
}
void spider_backward()
{
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(1,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(7,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(1,+1);
    move_servo(0,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(6,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(5,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(11,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(5,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(8,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(2,+1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(9,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(3,+1);
    move_servo(4,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(10,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(4,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(6,-1);
    move_servo(7,-1);
    move_servo(8,+1);
    move_servo(9,+1);
    move_servo(10,+1);
    move_servo(11,-1);
    delay(delay_time); 
  }
 get_ready(); 
}

