void setup()  
{
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  Serial1.begin(38400);
  // Send test message to other device
  Serial1.println("Hello from Arduino");
  //Serial1.println("1"); // Send "Online"
  //delay(2000);
}
char a; // stores incoming character from other device
void loop() 
{
  if (Serial1.available())
  // if text arrived in from Serial1 serial...
  {
    a = (Serial1.read());
    if (a=='1')
    {
      digitalWrite(13, HIGH); 
      Serial1.print('2');
    }
    if (a=='2')
    {
      digitalWrite(13, LOW);
      Serial1.println('1');
    }
    if (a=='?')
    {
      Serial1.println("Send '1' to turn LED on");
      Serial1.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}
