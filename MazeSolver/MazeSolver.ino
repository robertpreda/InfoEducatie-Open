int PIN1M2 = 3;
int PIN2M2 = 5;
int PIN1M1 = 6;
int PIN2M1 = 9;

#define IRpin A0

  void setup() {
  //setari pini
  pinMode(PIN1M1, OUTPUT);
  pinMode(PIN2M1, OUTPUT);
  pinMode(PIN1M2, OUTPUT);
  pinMode(PIN2M2, OUTPUT);
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
  while(digitalRead(7));
}
  //functia principala
  void loop() {
  bool sinS = digitalRead(4);
  if(sinS)
   {
     go(50,80); 
   }
   else
   {
      go(80,50);
   }
  
   float volts = analogRead(IRpin)*0.0048828125;
   float distance = 65*pow(volts, -1.10);
   
   if(distance < 40)
   {
      go(140,0);
      delay(250);
   }
    if(distance <35 && !sinS)
    {
        go(140,-140);
        delay(450); //ales aleatoriu 
    }
}
  //functie de control al motoarelor - sursa: robofun;
  void go(int speedLeft, int speedRight) {
  if (speedLeft >= 0) 
    {
    analogWrite(PIN1M1, speedLeft);
    analogWrite(PIN2M1, 0);
    } 
  else 
  {
    analogWrite(PIN1M1, 0);
    analogWrite(PIN2M1, -speedLeft);
  }
 
  if (speedRight >= 0) 
  {
    analogWrite(PIN1M2, speedRight);
    analogWrite(PIN2M2, 0);
  }else 
  {
    analogWrite(PIN1M2, 0);
    analogWrite(PIN2M2, -speedRight);
  }
}
