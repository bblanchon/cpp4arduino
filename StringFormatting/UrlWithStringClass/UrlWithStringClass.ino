void setup() {
  Serial.begin(9600);
  while (!Serial);

  const char* appid = "f5668a976be3969f9c7f43f24d0986ff";
  double latitude = 48.8534;
  double longitude = 2.3488;
  const char* lang = "fr";
  const char* units = "metric";

  String url = String(F("http://api.openweathermap.org/data/2.5/weather?lat=")) + String(latitude, 4) + F("&lon=") + String(longitude, 4) + F("&units=") + units + F("&lang=") + lang + F("&appid=") + appid;

  Serial.println(url);
}

void loop() {
  // not used in this example
}
