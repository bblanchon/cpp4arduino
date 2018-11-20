#include "Polyfills.h" // adds move()
#include "WString.h"   // adds the instrumented String class

#define RESOURCE "outdoor_temp"
#define API_KEY "0123456789"

// We must work in the namespace cpp4arduino to use the instrumented String
namespace cpp4arduino {

// A function that takes a C-style string.
// Calling this function doesn't makes a copy
void passByPointer(const char *) {
  // (empty)
}

// A function that takes a string by value.
// Calling this function makes a copy of the String
void passByValue(String) {
  // (empty)
}

// A function that takes a string by referece.
// Calling this function doesn't makes a copy
void passByConstReference(const String &) {
  // (empty)
}

void example1() {
  Serial.println("#1: Initialize from RAM");

  String s = "example";
}

void example2() {
  Serial.println("#2: Initialize from Flash");

  String s = F("example");
}

void example3() {
  Serial.println(F("#3: toCharArray()"));

  String s = "example";
  char tmp[32];
  s.toCharArray(tmp, sizeof(tmp));
  passByPointer(tmp);
}

void example4() {
  Serial.println(F("#4: c_str()"));

  String s = "example";
  passByPointer(s.c_str());
}

void example5() {
  Serial.println(F("#5: Pass by value"));

  String s = "example";
  passByValue(s);
}

void example6() {
  Serial.println(F("#6: Pass by const reference"));

  String s = "example";
  passByConstReference(s);
}

void example7() {
  Serial.println(F("#7: Move instance"));

  String s = "example";
  passByValue(move(s));
}

void example8() {
  Serial.println(F("#8: Append temporaries"));

  // Construct "/api/outdoor_temp?key=0123456789"
  String path = String("/api/") + RESOURCE + "?key=" + API_KEY;

  passByConstReference(path);
}

void example9() {
  Serial.println(F("#9: Mutate instance"));

  // Construct "/api/outdoor_temp?key=0123456789"
  String path("/api/");
  path += RESOURCE;
  path += "?key=";
  path += API_KEY;

  passByConstReference(path);
}

void example10() {
  Serial.println(F("#10: Call reserve"));

  // Construct "/api/outdoor_temp?key=0123456789"
  String path;
  path.reserve(64);
  path += "/api/";
  path += RESOURCE;
  path += "?key=";
  path += API_KEY;

  passByConstReference(path);
}

void example11() {
  Serial.println(F("#11: Pass a null string to the constructor"));

  // Construct "/api/outdoor_temp?key=0123456789"
  String path((char *)0);
  path.reserve(64);
  path += "/api/";
  path += RESOURCE;
  path += "?key=";
  path += API_KEY;

  passByConstReference(path);
}

void example12() {
  Serial.println(F("#12: Concat at compile time"));

  // Construct "/api/outdoor_temp?key=0123456789"
  String path = "/api/" RESOURCE "?key=" API_KEY;

  passByConstReference(path);
}

} // namespace cpp4arduino

void setup() {
  Serial.begin(9600);
  while (!Serial)
    continue;

  cpp4arduino::example1();
  Serial.println();
  cpp4arduino::example2();
  Serial.println();
  cpp4arduino::example3();
  Serial.println();
  cpp4arduino::example4();
  Serial.println();
  cpp4arduino::example5();
  Serial.println();
  cpp4arduino::example6();
  Serial.println();
  cpp4arduino::example7();
  Serial.println();
  cpp4arduino::example8();
  Serial.println();
  cpp4arduino::example9();
  Serial.println();
  cpp4arduino::example10();
  Serial.println();
  cpp4arduino::example11();
  Serial.println();
  cpp4arduino::example12();
}

void loop() {}