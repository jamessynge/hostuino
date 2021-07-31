#ifndef ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_CASE_INSENSITIVE_LESS_H_
#define ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_CASE_INSENSITIVE_LESS_H_

#include <string>

namespace hostuino {

struct CaseInsensitiveLess {
  bool operator()(const std::string& lhs, const std::string& rhs) const;
};

}  // namespace hostuino

#endif  // ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_CASE_INSENSITIVE_LESS_H_
