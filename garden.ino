#define PMP 1// relay
#define SEN_E 0// Turn on the sensor
#define SEN_R A0// Read sensor values
#define SKP A5// Button press skips a cycle
#define IND 13// Show when a cycle is being skipped

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 6, 5);
#define LCD_E A4// Turn on the display

int moisture;// global variable for the last seen value from SEN_R
int threshold = 600;// moisture threshold: dry if moisture <= threshold

long start = 0;// timer
long delta = 43200000;// 12 hrs in millis
int pause = 121970;// 7L in millis
bool skip = false;

void setup() {
  // put your setup code here, to run once:
  // Main Function
  pinMode(PMP, OUTPUT);
  pinMode(SEN_E, OUTPUT);
  pinMode(SEN_R, INPUT);
  pinMode(SKP, INPUT);
  pinMode(IND, OUTPUT);

  // LCD Display
  lcd.begin(16, 2);
  lcd.clear();

  // Defaults
  digitalWrite(PMP, LOW);
  digitalWrite(SEN_E, LOW);
  digitalWrite(IND, LOW);

  // Serial monitor cannot be used because pins 1 and 0 are in use
}

void loop() {
  // put your main code here, to run repeatedly

  // skip button
  if (analogRead(SKP) >= 600) {
    skip = not skip;
    while (analogRead(SKP) >= 600) {}
  }

  // pump timer
  if (timer() > delta) {
    start = millis();
    skip = query_sensor() > threshold or skip;
  }

  // lcd enable
  if (analogRead(LCD_E) >= 600) {
    display_data();
  } else {
    lcd.clear();
  }

  digitalWrite(IND, skip);
  digitalWrite(PMP, timer() < pause and not skip);
}
