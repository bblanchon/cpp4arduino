// C++ for Arduino
// What is heap fragmentation?
// https://cpp4arduino.com/

#include "MemoryInfo.h"

#ifdef ARDUINO_ARCH_AVR
#include "Ports/MemoryInfo.Avr.cpp"
#else
#error Your microcontroller architecture is not supported
#endif