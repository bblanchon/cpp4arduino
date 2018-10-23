// String interning in action
//
// This program displays the addresses of string so you can see the effect of
// string interning
//
// cpp4arduino.com

const char *a1 = "hello";
const char *a2 = "hello";

const char b1[] = "hello";
const char b2[] = "hello";

const char c1[] PROGMEM = "hello";
const char c2[] PROGMEM = "hello";

String d1 = "hello";
String d2 = "hello";

void showAddresses(const char *title, const void *s1, const void *s2) {
  Serial.println(title);
  Serial.print(" s1 = ");
  Serial.println((intptr_t)s1);
  Serial.print(" s2 = ");
  Serial.println((intptr_t)s2);
}

void setup() {
  Serial.begin(9600);
  while (!Serial)
    continue;

  showAddresses("const char*", a1, a2);
  showAddresses("char[]", b1, b2);
  showAddresses("char[] PROGMEM", c1, c2);
  showAddresses("F()", F("hello"), F("hello"));
  showAddresses("String", d1.c_str(), d2.c_str());
}

void loop() {}
