// Wrappers on top of the standard functions to log what happens.

#include <Arduino.h>

namespace cpp4arduino {

template <typename... Args>
inline void log(const __FlashStringHelper *fmt, Args... args) {
  char buffer[64];
  sprintf_P(buffer, (PGM_P)fmt, args...);
  Serial.println(buffer);
}

inline void *malloc(size_t n) {
  void *result = ::malloc(n);
  log(F("- malloc(%u) -> %p"), n, result);
  return result;
}

inline void *realloc(void *p, size_t n) {
  void *result = ::realloc(p, n);
  if (p == 0)
    log(F("- malloc(%u) -> %p"), n, result);
  else if (n == 0)
    log(F("- free(%p)"), p);
  else if (n && p)
    log(F("- realloc(%p, %u) -> %p"), p, n, result);
  return result;
}

inline void free(void *p) {
  ::free(p);
  log(F("- free(%p)"), p);
}

inline void memcpy(char *dst, const char *src, size_t n) {
  ::memcpy(dst, src, n);
  log(F("- memcpy(%p, %p, %u)"), dst, src, n);
}

inline void memmove(char *dst, const char *src, size_t n) {
  ::memmove(dst, src, n);
  log(F("- memmove(%p, %p, %u)"), dst, src, n);
}

inline void strcpy(char *dst, const char *src) {
  ::strcpy(dst, src);
  log(F("- strcpy(%p, %p) - %u bytes"), dst, src, ::strlen(src));
}

inline void strncpy(char *dst, const char *src, size_t n) {
  ::strncpy(dst, src, n);
  log(F("- strncpy(%p, %p, %u) - %u bytes"), dst, src, n,
      min(::strlen(src), n));
}

#ifndef strcpy_P
inline void strcpy_P(char *dst, const char *src) {
  ::strcpy_P(dst, src);
  log(F("- strcpy_P(%p, %p) - %u bytes"), dst, src, ::strlen_P(src));
}
#endif

#ifndef strncpy_P
inline void strncpy_P(char *dst, const char *src, size_t n) {
  ::strncpy_P(dst, src, n);
  log(F("- strncpy_P(%p, %p, %u) - %u bytes"), dst, src, n,
      min(::strlen(src), n));
}
#endif
} // namespace cpp4arduino