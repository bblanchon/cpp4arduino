8 tips to use the String class efficiently
==========================================

This project contains the code samples for the article ["8 tips to use the String class efficiently" on cpp4arduino.com](https://cpp4arduino.com/2018/11/21/eight-tips-to-use-the-string-class-efficiently.html)

Results
-------

## On AVR

Here is output with the Arduino Core for AVR version 1.6.22:

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
- malloc(64) -> 0x23c
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

## On ESP8266

Here is the output with the Arduino Core for ESP8266 version 2.4.2:

```
#1: Initialize from RAM
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- free(0x3ffef3fc)

#2: Initialize from Flash
- malloc(8) -> 0x3ffef3fc
- strncpy_P(0x3ffef3fc, 0x40235704, 2147483647) - 7 bytes
- free(0x3ffef3fc)

#3: toCharArray()
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- strncpy(0x3fffff70, 0x3ffef3fc, 7) - 7 bytes
- free(0x3ffef3fc)

#4: c_str()
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- free(0x3ffef3fc)

#5: Pass by value
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- malloc(8) -> 0x3ffef40c
- strcpy(0x3ffef40c, 0x3ffef3fc) - 7 bytes
- free(0x3ffef40c)
- free(0x3ffef3fc)

#6: Pass by const reference
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- free(0x3ffef3fc)

#7: Move instance
- malloc(8) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe8878) - 7 bytes
- free(0x3ffef3fc)
- free(0)

#8: Append temporaries
- malloc(6) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe889c) - 5 bytes
- malloc(6) -> 0x3ffef40c
- strcpy(0x3ffef40c, 0x3ffef3fc) - 5 bytes
- realloc(0x3ffef40c, 18) -> 0x3ffef40c
- strcpy(0x3ffef411, 0x3ffe88a4) - 12 bytes
- realloc(0x3ffef40c, 23) -> 0x3ffef40c
- strcpy(0x3ffef41d, 0x3ffe88b4) - 5 bytes
- realloc(0x3ffef40c, 33) -> 0x3ffef40c
- strcpy(0x3ffef422, 0x3ffe88bc) - 10 bytes
- malloc(33) -> 0x3ffef434
- strcpy(0x3ffef434, 0x3ffef40c) - 32 bytes
- free(0x3ffef40c)
- free(0x3ffef3fc)
- free(0x3ffef434)

#9: Mutate instance
- malloc(6) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe889c) - 5 bytes
- realloc(0x3ffef3fc, 18) -> 0x3ffef3fc
- strcpy(0x3ffef401, 0x3ffe88a4) - 12 bytes
- realloc(0x3ffef3fc, 23) -> 0x3ffef3fc
- strcpy(0x3ffef40d, 0x3ffe88b4) - 5 bytes
- realloc(0x3ffef3fc, 33) -> 0x3ffef3fc
- strcpy(0x3ffef412, 0x3ffe88bc) - 10 bytes
- free(0x3ffef3fc)

#10: Call reserve
- malloc(1) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe88e8) - 0 bytes
- realloc(0x3ffef3fc, 65) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe889c) - 5 bytes
- strcpy(0x3ffef401, 0x3ffe88a4) - 12 bytes
- strcpy(0x3ffef40d, 0x3ffe88b4) - 5 bytes
- strcpy(0x3ffef412, 0x3ffe88bc) - 10 bytes
- free(0x3ffef3fc)

#11: Pass a null string to the constructor
- malloc(65) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe889c) - 5 bytes
- strcpy(0x3ffef401, 0x3ffe88a4) - 12 bytes
- strcpy(0x3ffef40d, 0x3ffe88b4) - 5 bytes
- strcpy(0x3ffef412, 0x3ffe88bc) - 10 bytes
- free(0x3ffef3fc)

#12: Concat at compile time
- malloc(33) -> 0x3ffef3fc
- strcpy(0x3ffef3fc, 0x3ffe88c8) - 32 bytes
- free(0x3ffef3fc)
```

## On SAMD

Here is the output with the Arduino Core for SAMD version 1.6.19:

```
#1: Initialize from RAM
- malloc(8) -> 0x20000a80
- strcpy(0x20000a80, 0x8638) - 7 bytes
- free(0x20000a80)

#2: Initialize from Flash
- malloc(8) -> 0x20000a80
- strcpy(0x20000a80, 0x8638) - 7 bytes
- free(0x20000a80)

#3: toCharArray()
- malloc(8) -> 0x20000a80
- strcpy(0x20000a80, 0x8638) - 7 bytes
- strncpy(0x20007fb8, 0x20000a80, 7) - 7 bytes
- free(0x20000a80)

#4: c_str()
- malloc(8) -> 0x20000a80
- strcpy(0x20000a80, 0x8638) - 7 bytes
- free(0x20000a80)

#5: Pass by value
- malloc(8) -> 0x20000a80
- strcpy(0x20000a80, 0x8638) - 7 bytes
- malloc(8) -> 0x20000a90
- strcpy(0x20000a90, 0x20000a80) - 7 bytes
- free(0x20000a90)
- free(0x20000a80)

#6: Pass by const reference
- malloc(8) -> 0x20000a90
- strcpy(0x20000a90, 0x8638) - 7 bytes
- free(0x20000a90)

#7: Move instance
- malloc(8) -> 0x20000a90
- strcpy(0x20000a90, 0x8638) - 7 bytes
- free(0x20000a90)
- free(0)

#8: Append temporaries
- malloc(6) -> 0x20000a90
- strcpy(0x20000a90, 0x86cf) - 5 bytes
- malloc(6) -> 0x20000a80
- strcpy(0x20000a80, 0x20000a90) - 5 bytes
- realloc(0x20000a80, 18) -> 0x20000aa0
- strcpy(0x20000aa5, 0x86d5) - 12 bytes
- realloc(0x20000aa0, 23) -> 0x20000ab8
- strcpy(0x20000ac9, 0x86e2) - 5 bytes
- realloc(0x20000ab8, 33) -> 0x20000ad8
- strcpy(0x20000aee, 0x876b) - 10 bytes
- malloc(33) -> 0x20000ab0
- strcpy(0x20000ab0, 0x20000ad8) - 32 bytes
- free(0x20000ad8)
- free(0x20000a90)
- free(0x20000ab0)

#9: Mutate instance
- malloc(6) -> 0x20000af8
- strcpy(0x20000af8, 0x86cf) - 5 bytes
- realloc(0x20000af8, 18) -> 0x20000ad8
- strcpy(0x20000add, 0x86d5) - 12 bytes
- realloc(0x20000ad8, 23) -> 0x20000ad8
- strcpy(0x20000ae9, 0x86e2) - 5 bytes
- realloc(0x20000ad8, 33) -> 0x20000ab0
- strcpy(0x20000ac6, 0x876b) - 10 bytes
- free(0x20000ab0)

#10: Call reserve
- malloc(1) -> 0x20000af8
- strcpy(0x20000af8, 0x8b76) - 0 bytes
- realloc(0x20000af8, 65) -> 0x20000ab0
- strcpy(0x20000ab0, 0x86cf) - 5 bytes
- strcpy(0x20000ab5, 0x86d5) - 12 bytes
- strcpy(0x20000ac1, 0x86e2) - 5 bytes
- strcpy(0x20000ac6, 0x876b) - 10 bytes
- free(0x20000ab0)

#11: Pass a null string to the constructor
- malloc(64) -> 0x20000ab8
- strcpy(0x20000ab8, 0x86cf) - 5 bytes
- strcpy(0x20000abd, 0x86d5) - 12 bytes
- strcpy(0x20000ac9, 0x86e2) - 5 bytes
- strcpy(0x20000ace, 0x876b) - 10 bytes
- free(0x20000ab8)

#12: Concat at compile time
- malloc(33) -> 0x20000ad8
- strcpy(0x20000ad8, 0x8755) - 32 bytes
- free(0x20000ad8)
```

In #2 we can see that this board doesn't support Flash strings.