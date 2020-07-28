char disp[16];

void display_data() {
  lcd.print(get_display_time());
  lcd.setCursor(0, 1);
  sprintf(disp, "Sensor: %4d", query_sensor());
  lcd.print(disp);
  lcd.home();
}

String get_display_time() {
  long omega = delta - millis() + start;
  int s = omega / 1000 % 60;
  int m = omega / 60000 % 60;
  int h = omega / 3600000;
  sprintf(disp, "%02d:%02d:%02d", h, m, s);
  return disp;
}
