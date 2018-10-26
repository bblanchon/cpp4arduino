// C++ for Arduino
// Why C++ programmers don't use NULL?
//
// Read the article:
// https://cpp4arduino.com/2018/10/26/why-cpp-programmers-dont-use-null.html

template <typename T>
void printValue(T value);

template <>
void printValue<int>(int value) {
  Serial.print("Integer: ");
  Serial.println(value, DEC);
}

template <>
void printValue<void *>(void *value) {
  Serial.print("Pointer: 0x");
  Serial.println((intptr_t)value, HEX);
}

void setup() {
  Serial.begin(9600);
  while (!Serial)
    continue;

  const char *color = NULL;
  String colorStr1(color);
  String colorStr2(NULL);

  if (colorStr1 == colorStr2) {
    Serial.println("colorStr1 == colorStr2");
  } else {
    Serial.println("colorStr1 != colorStr2");
  }

  Serial.print("colorStr1 = ");
  Serial.println(colorStr1);
  Serial.print("colorStr2 = ");
  Serial.println(colorStr2);

  printValue(42);
  printValue((void *)0x101);
  printValue(NULL);
}

void loop() {}
