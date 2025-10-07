#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int sensorPin = A0;
int LED = 13;
int buzzer = 12;

// Create LCD object at I2C address 0x27 (change to 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 columns, 2 rows

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();         // Initialize LCD
  lcd.backlight();     // Turn on backlight
  lcd.clear();         // Clear screen
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  Serial.print("Moisture Level: ");
  Serial.println(sensorValue);

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(sensorValue);
  lcd.print("   ");  // Clear remaining digits

  if (sensorValue < 400) {
    Serial.println("Soil is WET");
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Wet     ");
  } else {
    Serial.println("Soil is DRY");
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: Dry     ");
  }

  delay(1000);
}
