void setup()
{
  attachInterrupt(0,temp,RISING);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
}
void loop()
{
}
void temp()
{
  int val=0;
  for(int i=0;i<4;i++)
  val+=digitalRead(i+8)<<i;
  Serial.print("value=");
  Serial.println(val);
}
