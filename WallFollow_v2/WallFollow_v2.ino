int PIN1M2 = 3;
int PIN2M2 = 5;
int PIN1M1 = 6;
int PIN2M1 = 9;
#define IRpin A0
#define IRpin2 A1

void setup() {
  //setari pini
  pinMode(PIN1M1, OUTPUT);
  pinMode(PIN2M1, OUTPUT);
  pinMode(PIN1M2, OUTPUT);
  pinMode(PIN2M2, OUTPUT);
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  //senzori analogici - sursa formula: http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
  float volts = analogRead(IRpin)*0.0048828125;
  float distance = 65*pow(volts, -1.10);
  //senzori digitali 
  bool sinD = digitalRead(7);
  bool sinS = digitalRead(4);
  if(sinS)
  {
    go(50,80); 
  }
   else
   {
    go(80,50);
   }
   if(distance < 30){
      go(80,-40);
    }
  
  
}
//functie de control a motoarelor - sursa robofun
void go(int speedLeft, int speedRight) {
  if (speedLeft >= 0) {
    analogWrite(PIN1M1, speedLeft);
    analogWrite(PIN2M1, 0);
  } 
  else {
    analogWrite(PIN1M1, 0);
    analogWrite(PIN2M1, -speedLeft);
  }
 
  if (speedRight >= 0) {
    analogWrite(PIN1M2, speedRight);
    analogWrite(PIN2M2, 0);
  }else {
    analogWrite(PIN1M2, 0);
    analogWrite(PIN2M2, -speedRight);
  }
}

