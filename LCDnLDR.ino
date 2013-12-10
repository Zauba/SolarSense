/* LCD Pins
 * RS: Pin 22
 * EN: Pin 23
 * D4: Pin 24
 * D5: Pin 25
 * D6: Pin 26
 * D7: Pin 27
 * Vo: Pin
 * LED+ : 5V
 */
 
#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);
int bright = 65;

 // LDR Setup
 int LDRN_Pin = A0; // LDR North
 int LDRS_Pin = A1; // LDR South
 int LDRW_Pin = A2; // LDR West
 int LDRE_Pin = A3; // LDR East

void setup() {

  // Setup Serial connection
  Serial.begin(9600);
  
  // Setup LCD
  pinMode(9, OUTPUT);  
  lcd.begin(16,2);
  lcd.print("LDR Sensors");
  analogWrite(9, bright);

}

void loop() {
  
  // Read LDR Values
  int LDRN = analogRead(LDRN_Pin); 
  int LDRS = analogRead(LDRS_Pin);
  int LDRW = analogRead(LDRW_Pin);
  int LDRE = analogRead(LDRE_Pin);
  
  int LDRY = LDRN - LDRS ;
  int LDRX = LDRW - LDRE ;
 
  // Display values on LCD   
  lcd.setCursor(0,1);  
  lcd.print(LDRY);
  lcd.setCursor(8,1);
  lcd.print(LDRX);

  // Serial output of values  
  Serial.println(LDRN);
  Serial.println(LDRS);
  Serial.println(LDRY);
  Serial.println(LDRW);
  Serial.println(LDRE);
  Serial.println(LDRX);
  delay(1000);  
  
}