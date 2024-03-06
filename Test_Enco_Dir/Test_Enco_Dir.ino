////// Testing Encoder Direction //////////////////////////// 
#include <LiquidCrystal.h>
#define outputA 12
#define outputB 11
LiquidCrystal lcd (3,4,5,6,7,8);
int counter = 0;
int currentStateA;
int lastStateA;
String currentDir ="";
void setup() {
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lastStateA = digitalRead(outputA);
}
void loop() {
  currentStateA = digitalRead(outputA);
  if (currentStateA != lastStateA  && currentStateA == 1){
    if (digitalRead(outputB) != currentStateA) {
      counter ++;
      currentDir ="CW";
    } else {
      counter --;
      currentDir ="ACW";
    }
    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
    lcd.setCursor(0, 0);
    lcd.print("Position: ");
    lcd.setCursor(10, 0);
    lcd.print(counter);
    lcd.setCursor(0, 1);
    lcd.print("Dir: ");
    lcd.setCursor(5, 1);
    lcd.print(currentDir);
  }
  lastStateA = currentStateA;
  delay(1);
}