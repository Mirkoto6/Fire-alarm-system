#include<LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int Smoke = 0;
int r =0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop()
{
  Smoke = analogRead(A0);
  Serial.println(analogRead(A0));
  if (Smoke >=25) 
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    tone(13, 523);
    lcd.setCursor(0,0);
         lcd.print("Emergency exit is right to the elevator!");
         delay(100);
         lcd.setCursor(0,1);
         lcd.print("Leave the building immediately!");
         lcd.setCursor(1,0);
    
    
    for(r=0;r<30;r++)
     {
         
      lcd.scrollDisplayLeft();
         delay(70);
     }
     
  }
  
  else 
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    lcd.clear();
    noTone(13);
    lcd.setCursor(6,0);
    lcd.print("GOOD");
    lcd.setCursor(6,1);
    lcd.print("MORNING");
    delay(1000);
  }
  delay(10); 
}