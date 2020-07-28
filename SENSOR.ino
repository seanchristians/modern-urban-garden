long lastSensorQuery = 0;
int sensorQueryDelay = 1000;

int query_sensor() {
  if (abs(millis() - lastSensorQuery) >= sensorQueryDelay) {
    lastSensorQuery = millis();
    
    digitalWrite(SEN_E, HIGH);
    delayMicroseconds(2);
    moisture = analogRead(SEN_R);
    digitalWrite(SEN_E, LOW);
  }

  return moisture;
}
