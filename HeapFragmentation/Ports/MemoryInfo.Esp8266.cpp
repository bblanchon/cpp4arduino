// C++ for Arduino
// What is heap fragmentation?
// https://cpp4arduino.com/

// This source file captures the platform dependent code.
// This version was tested with ESP8266 core for Arduino version 3.0.2

#include <Esp.h>

size_t getTotalAvailableMemory() {
  return ESP.getFreeHeap();
}

size_t getLargestAvailableBlock() {
  return ESP.getMaxFreeBlockSize();
}

// NOTE: there is also an ESP.getHeapFragmentation() that gives the same results
