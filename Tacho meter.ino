#include <LiquidCrystal.h>
const int rs=12, en=11,d4=5,d5=4,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
float REV=0;
int RPM_VALUE;
int PREVIOUS = 0;
int TIME ;
void INTERRUPT()
{
REV++;
}
void setup() {
lcd.begin(16,2);
// put your setup code here, to run once:
Serial.begin(9600);
attachInterrupt(1,INTERRUPT,RISING);
}
void loop() {
delay(1000);
detachInterrupt(0);
TIME = millis()-PREVIOUS;
RPM_VALUE = (REV/TIME) * 6000;
PREVIOUS=millis();
REV=0;
Serial.println(RPM_VALUE);
lcd.print(RPM_VALUE);
delay(500);
lcd.clear();
delay(500);
attachInterrupt(1,INTERRUPT,RISING);

// put your main code here, to run repeatedly:
}
