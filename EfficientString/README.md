How to use the `String` class efficiently
=========================================

This program demonstrate how you can improve the efficient of your code when using the `String` class:

* reduce copying
* reduce allocations
* reduce fragmentation

To show the effect of each calls, I modified the original `String` class from the [Arduino Core for AVR](https://github.com/arduino/ArduinoCore-avr/blob/2663be17272e19f00c55f3f2d8f1ebfac47158d6/cores/arduino/WString.h):

* I added calls to `Serial.println()`, so that we can see what happens in the Serial Monitor.
* I removed the platform dependent features, so that we can run this program on other platforms.

The modified class is in a different namespace, to avoid the name clash.

Results
-------

Here is the serial output of this program with the Arduino Core for AVR version 1.6.22:

```
#1: Initialize from RAM
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- free(0x23c)

#2: Initialize from Flash
- malloc(8) -> 0x23c
- strcpy_P(0x23c, 0xe3) - 7 bytes
- free(0x23c)

#3: toCharArray()
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- strncpy(0x8d6, 0x23c, 7) - 7 bytes
- free(0x23c)

#4: c_str()
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- free(0x23c)

#5: Pass by value
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- malloc(8) -> 0x246
- strcpy(0x246, 0x23c) - 7 bytes
- free(0x246)
- free(0x23c)

#6: Pass by const reference
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- free(0x23c)

#7: Move instance
- malloc(8) -> 0x23c
- strcpy(0x23c, 0x133) - 7 bytes
- free(0x23c)
- free(0)

#8: Append temporaries
- malloc(6) -> 0x23c
- strcpy(0x23c, 0x155) - 5 bytes
- malloc(6) -> 0x244
- strcpy(0x244, 0x23c) - 5 bytes
- realloc(0x244, 18) -> 0x244
- strcpy(0x249, 0x15b) - 12 bytes
- realloc(0x244, 23) -> 0x244
- strcpy(0x255, 0x168) - 5 bytes
- realloc(0x244, 33) -> 0x244
- strcpy(0x25a, 0x184) - 10 bytes
- malloc(33) -> 0x267
- strcpy(0x267, 0x244) - 32 bytes
- free(0x244)
- free(0x23c)
- free(0x267)

#9: Mutate instance
- malloc(6) -> 0x23c
- strcpy(0x23c, 0x155) - 5 bytes
- realloc(0x23c, 18) -> 0x23c
- strcpy(0x241, 0x15b) - 12 bytes
- realloc(0x23c, 23) -> 0x23c
- strcpy(0x24d, 0x168) - 5 bytes
- realloc(0x23c, 33) -> 0x23c
- strcpy(0x252, 0x184) - 10 bytes
- free(0x23c)

#10: Call reserve
- malloc(1) -> 0x23c
- strcpy(0x23c, 0x11a) - 0 bytes
- realloc(0x23c, 65) -> 0x23c
- strcpy(0x23c, 0x155) - 5 bytes
- strcpy(0x241, 0x15b) - 12 bytes
- strcpy(0x24d, 0x168) - 5 bytes
- strcpy(0x252, 0x184) - 10 bytes
- free(0x23c)

#11: Pass a null string to the constructor
- malloc(65) -> 0x23c
- strcpy(0x23c, 0x155) - 5 bytes
- strcpy(0x241, 0x15b) - 12 bytes
- strcpy(0x24d, 0x168) - 5 bytes
- strcpy(0x252, 0x184) - 10 bytes
- free(0x23c)

#12: Concat at compile time
- malloc(33) -> 0x23c
- strcpy(0x23c, 0x16e) - 32 bytes
- free(0x23c)
```