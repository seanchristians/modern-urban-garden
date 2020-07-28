// --------------------------------- Instructions ---------------------------------
// Unplug the sensor (pin 0, orange) and the pump (pin 1, yellow)
// Plug the pump (yellow) into pin 13
// Remove the blue indicator LED

#define PMP 13
#define SKP A5

bool go = false;
long start;

void setup() {
  // put your setup code here, to run once:
  pinMode(PMP, OUTPUT);
  pinMode(SKP, INPUT);

  digitalWrite(PMP, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(SKP) >= 600 and not go) {
    go = true;
    start = millis();
    digitalWrite(PMP, HIGH);
    while (analogRead(SKP) >= 600) {};
  } else if (analogRead(SKP) >= 600 and go) {
    go = false;
    digitalWrite(PMP, LOW);
    Serial.println(millis() - start);
    while (analogRead(SKP) >= 600) {};
  }
}
