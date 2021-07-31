#ifndef ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_SAMPLE_PRINTABLE_H_
#define ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_SAMPLE_PRINTABLE_H_

// SamplePrintable supports testing APIs that accept a Printable.
//
// Author: james.synge@gmail.com

#include <stddef.h>

#include <string>

#include "extras/host/arduino/print.h"

namespace hostuino {

struct SamplePrintable : public ::Printable {
  SamplePrintable() {}
  explicit SamplePrintable(const std::string& value) : str(value) {}

  size_t printTo(::Print& p) const override {
    return p.write(str.data(), str.size());
  }

  std::string str;
};

}  // namespace hostuino

#endif  // ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_SAMPLE_PRINTABLE_H_
