#include <MAX6675.h>
#include <LiquidCrystal.h>

/**
  * Declaring the Variables
  */

const int SensorIn = A0;
int Sensibl=0.066;
double AcsOffset=2.46;
float Courant;
double tension=0;
double Nrj=0;

const int soPin = 9;
const int csPin = 8;
const int sckPin =7;

MAX6675 TMP;
 
int rs=12;
int en=11;
int d4=5;
int d5=4;
int d6=3;
int d7=2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  for(int i=0; i<13; i++)
  pinMode(i, OUTPUT);
  pinMode(13, INPUT);
  
  Serial.begin(9600);
  TMP.begin(sckPin, csPin, soPin); 
  lcd.begin(20,4);
  
  lcd.print(" OFTY");
  delay(1000);
  lcd.clear();
  lcd.print(" GROX ");
  delay(1000);
  lcd.clear();
  
}

void loop() {
  
  

  int status = TMP.read();
  float temp = TMP.getTemperature();

double ValeurLue=analogRead(SensorIn);
  tension=(ValeurLue*5.0/1023);
  Courant=(tension-AcsOffset)/Sensibl;
  int Puissance=abs(Courant*230);
      Nrj=(Nrj+Puissance)/1000;


Serial.println("Courant :");
Serial.println(Courant);

 if (temp>35)
{
digitalWrite(38,HIGH);  
}
else {
digitalWrite(38,LOW);
}


   lcd.setCursor(0,1);
   lcd.print("Temp :");
   lcd.print(temp);
   lcd.setCursor(10,1);
   lcd.print(" degree C");
   lcd.setCursor(0,0);
   lcd.print("Curr :");
   lcd.print(Courant);
   lcd.print("amp");
   lcd.setCursor(0,2);
   lcd.print("E:");
   lcd.print(Nrj);
   lcd.print("KWh");
  Serial.println("Temp :");
  Serial.println(temp); 
  
  delay(1000);
  
}
