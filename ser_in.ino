int sw=A0;
int sw1=7;

int ledstate=1;
int buttonstate=0;
int lastbuttonstate=0;
unsigned long lastdetime=0;
unsigned long dedelay=50;

int x = A1;
int value = 0;
int y = A2;
int value1 = 0;
int value3=0;
void setup() {
  
Serial.begin(9600);
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(sw,INPUT);
pinMode(sw1,INPUT);
}

void loop() {
  int ledstate1=digitalRead(sw1);
    int reading = analogRead(sw);
    if(reading<100)
    {
      reading=0;
      }
      if(reading>100)
      {
        reading=1;
        }
    if(reading!=lastbuttonstate)
    {
      lastdetime=millis();
      
      }
      if((millis()-lastdetime)> dedelay)
      {
        if (reading!=buttonstate)
        {
          buttonstate=reading;


        if(buttonstate==1)
        {
          ledstate= !ledstate;
          }
          
          }
        }
   lastbuttonstate=reading;
   value = analogRead(x);
   value =map(value,0,1023,0,255);
   value1 = analogRead(y);
   value1 =map(value1,0,1023,0,255);
   
 
   
  
   Serial.print(value);
   Serial.print(",");
   Serial.print(value1);
   Serial.print(",");
   Serial.print(ledstate);
   Serial.print(",");
   Serial.println(ledstate1);
   
   
   delay(100);
   
}
