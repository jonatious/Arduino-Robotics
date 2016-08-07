int l,r,m;
int w,x,y,z;
void setup()
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
}
void loop()
{
  r=digitalRead(4);
  m=digitalRead(3);
  l=digitalRead(2);
  if((r==0 && l==0 && m==0)||(l==0 && r==0 && m==1)||(l==1 && m==0 && r==0)||(l==1 && m==1 && r==0))
  {
   w=z=1;x=y=0;//right turn 
  }
  else if((l==0 && m==0 && r==1)||(l==1 && m==0 && r==1))
  {
    w=y=1;x=z=0;//straight
  }
  else if(l==0 && m==1 && r==1)
  {
    w=z=0;x=y=1;//left
    
   }
//if(l==1 && m==1 && r==1)
{delay(500);//check if its a discontinuity or a break
while(l==1 && m==1 && r==1)
{w=z=1;x=y=0;//turn around 180 degrees
digitalWrite(10,w);
digitalWrite(11,x);
digitalWrite(12,y);
digitalWrite(13,z);
delay(100);
w=y=1;x=z=0;//move forward to catch line again
digitalWrite(10,w);
digitalWrite(11,x);
digitalWrite(12,y);
digitalWrite(13,z);
delay(200);
}}    
digitalWrite(10,w);    
digitalWrite(11,x);
digitalWrite(12,y);
digitalWrite(13,z);
}
    

