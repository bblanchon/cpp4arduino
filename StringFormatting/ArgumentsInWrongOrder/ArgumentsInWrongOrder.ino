void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  const char* name = "Bart";
  int age = 10;

  char s[32];
  snprintf(s, sizeof(s), "%s is %i years old", age, name);

  Serial.println(s);
}

void loop() {
  // not used in this example
}
