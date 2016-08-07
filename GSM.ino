void setup()
{
  pinMode(7,INPUT);
  digitalWrite(7,1);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
}

void loop()
{
  if (digitalRead(7)==0)
  { 
    int a=digitalRead(7);
    digitalWrite(13,1);
    Serial.println("AT+CMGF=1"); // Set the Mode as Text Mode
    delay(50);
    Serial.println("AT+CMGS=\"+918870669966\"");  // Specify the Destination number in international format
    delay(50);
    Serial.print("Message Received"); // Enter your message 
    delay(50);
    Serial.write((byte)0x1A);                                // End of message character 0x1A : Equivalent to Ctrl+z refer internet to find the hex value for other escape seq
    delay(50);
    Serial.println();
    delay(1000);
    digitalWrite(13,0);
  }
}
  
