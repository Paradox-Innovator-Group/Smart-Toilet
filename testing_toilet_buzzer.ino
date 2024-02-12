#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<Servo.h>
Servo myservo;
int buzzer = 9;
int button = 10;
int prevbuttonstate = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
int ldrpin = A0;
int led = 13;
int green = 12;
int motorFwd = 7;
int motorRev = 8;
int jet = 6;
int limiting = 600;
int value;
int ldrstate;
void setup() {
  Serial.begin(9600);
   lcd.init();
    lcd.backlight();
    lcd.clear();
      lcd.print("Smart Toilet");
    lcd.setCursor(0,1);
   lcd.print("Indian Railways");
  pinMode(led, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(motorFwd, OUTPUT);
  pinMode(motorRev, OUTPUT);
  pinMode(jet , OUTPUT);
  digitalWrite(jet , HIGH);
  digitalWrite(motorFwd, HIGH);
  digitalWrite(motorRev, HIGH);
  digitalWrite(ldrstate, LOW); 
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  pinMode(button, INPUT_PULLUP);
  //myservo.attach(9);
}

void loop() { 
  
  
  
  Serial.println("");
  Serial.print("value  of LDR last =");
  Serial.print(value);
 
 value = analogRead(ldrpin);
 
  Serial.println("");
  Serial.print("value  of LDR =");
  Serial.print(value);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
if(value > limiting)
{ digitalWrite(green, HIGH);
  lcd.clear();
      lcd.print("Smart Toilet");
    lcd.setCursor(0,1);
   lcd.print("VACCANT !!!");
  }
 

 
if (value < limiting)
{value = analogRead(ldrpin); 
  
if(value >= limiting)
{if(ldrstate = HIGH)
{


lcd.setCursor(0,0);
lcd.print("PleaseWaitToilet");
lcd.setCursor(0,1);
lcd.print("is Cleaning ");

delay(500);
myservo.write(180);
delay(500);
  
digitalWrite(motorFwd, LOW);
delay(10000);
digitalWrite(motorFwd, HIGH);
digitalWrite(jet, LOW);
delay(10000);
digitalWrite(jet, HIGH);
digitalWrite(motorRev, LOW);
delay(1000);
digitalWrite(motorRev, HIGH);
digitalWrite(led, LOW);
myservo.write(0);
 delay(100);
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print("Toilet is Ready ");
lcd.setCursor(0,1);
lcd.print("to USE");
delay(1000);
}
value = 100;
ldrstate = LOW;

}
else
  { Serial.println("");
  Serial.print("Wait, Toilet is occupied");
  value = analogRead(ldrpin);
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Wait, Toilet is ");
lcd.setCursor(0,1);
lcd.print(" Occupied!!");
digitalWrite(led, HIGH);
digitalWrite(green, LOW);
Serial.println();
Serial.print("Value =");
Serial.print(value);
  }
}
 
  
}
