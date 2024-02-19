#include<dht.h>
dht DHT;
#define DHT11_PIN 5
#include<LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int Gas1=7;
int Gas2=6;
void setup() {
  lcd.begin(20,4);
  pinMode(Gas1, INPUT);
  pinMode(Gas2, INPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  
  int chk = DHT.read11(DHT11_PIN);
  if(digitalRead(Gas1) == HIGH){
    lcd.setCursor(0,0);
    lcd.print("LPG  GAS  LEAKAGE ;"); 
    digitalWrite(4 ,HIGH);    

  }
  else{
      lcd.setCursor(0,0);
      lcd.print("NO LPG GAS LEAKAGE ;");
      digitalWrite(4 ,LOW);
       }     
  if(digitalRead(Gas2) == HIGH){
        lcd.setCursor(0,1);
        lcd.print("CO LEAKAGE     "); 
        digitalWrite(4 ,HIGH);
      }
  else{
      lcd.setCursor(0,1);
      lcd.print("NO CO LEAKAGE");
      digitalWrite(4 ,LOW);
   }
  lcd.setCursor(0,2);
  lcd.print("Temperature ");
  lcd.print(DHT.temperature);
  lcd.setCursor(0,3);
  lcd.print("Humidity  ");
  lcd.print(DHT.humidity);
  lcd.print(" % ");
  
 
}
