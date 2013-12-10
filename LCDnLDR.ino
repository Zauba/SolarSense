
#include <LiquidCrystal.h>

// LCD Pins
// LED+ : 5V
#define RS 22
#define EN 23
#define D4 24
#define D5 25
#define D6 26
#define D7 27
// #define Vo: Pin

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
int bright = 65;

// LDR Pins
#define LDRN_Pin A0 // LDR North
#define LDRS_Pin A1 // LDR South
#define LDRW_Pin A2 // LDR West
#define LDRE_Pin A3 // LDR East

void setup() {

  // Setup Serial connection
  Serial.begin(9600);
  
  // Setup LCD
  pinMode(9, OUTPUT);  
  lcd.begin(16,2);
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
  lcd.clear();
  lcd.print("LDR Sensors");  
  lcd.setCursor(0,1);
  lcd.print("Y: ");  
  lcd.print(LDRY);
  lcd.setCursor(8,1);
  lcd.print("X: ");
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
