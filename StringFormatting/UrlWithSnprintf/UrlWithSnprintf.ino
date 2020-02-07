void setup() {
  Serial.begin(9600);
  while (!Serial);

  const char* appid = "f5668a976be3969f9c7f43f24d0986ff";
  double latitude = 48.8534;
  double longitude = 2.3488;
  const char* lang = "fr";
  const char* units = "metric";

  char url[150];
  snprintf_P(url, sizeof(url), PSTR("http://api.openweathermap.org/data/2.5/weather?lat=%.4f&lon=%.4f&units=%s&lang=%s&appid=%s"), latitude, longitude, lang, units, appid);
  Serial.println(url);
}

void loop() {
  // not used
}
