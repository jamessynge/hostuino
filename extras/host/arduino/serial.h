#ifndef ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_SERIAL_H_
#define ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_SERIAL_H_

// Provides a fake version of the Serial instance that is used in some of these
// demo sketches. There is no attempt to support input; it just outputs to
// std::cout.

#include <ostream>

#include "extras/host/arduino/print.h"  // IWYU pragma: export

class FakeSerial : public Print {
 public:
  FakeSerial();
  explicit FakeSerial(bool);

  void begin(int) {}
  operator bool() const {  // NOLINT
    return true;
  }

  size_t write(uint8_t b) override;
  size_t write(const uint8_t* buffer, size_t size) override;

  // Pull in the other variants of write; otherwise, only the above two are
  // visible.
  using Print::write;

  void flush() override;

 private:
  std::ostream& out_;
};

extern FakeSerial Serial;    // NOLINT
extern FakeSerial ToStdErr;  // NOLINT

#endif  // ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_SERIAL_H_
