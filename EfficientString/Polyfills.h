// Standard C++ functions missing in Arduino
// cpp4arduino.com

#pragma once

namespace cpp4arduino {

template <class T>
struct remove_reference {
  typedef T type;
};
template <class T>
struct remove_reference<T &> {
  typedef T type;
};
template <class T>
struct remove_reference<T &&> {
  typedef T type;
};

template <typename T>
constexpr typename remove_reference<T>::type &&move(T &&x) noexcept {
  return static_cast<typename remove_reference<T>::type &&>(x);
}
} // namespace cpp4arduino