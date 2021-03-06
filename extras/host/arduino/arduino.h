#ifndef ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_ARDUINO_H_
#define ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_ARDUINO_H_

// This provides just (?) enough of Arduino.h for my needs when testing on host.
//
// As of mid-April 2021, I'm starting to write code that needs to read and write
// pins, so may need to add some more support for fake hardware (e.g. a
// mock-able class).

// These standard libraries are included directly or indirectly by Arduino.h.

#include <ctype.h>    // IWYU pragma: export
#include <math.h>     // IWYU pragma: export
#include <stdbool.h>  // IWYU pragma: export
#include <stdlib.h>   // IWYU pragma: export
#include <string.h>   // IWYU pragma: export
// #include <inttypes.h>  // Handled via int_types.h below, which provides the
// subset I use.

// These AVR specific libraries are included directly or indirectly by
// Arduino.h.

#include "extras/host/arduino/avr_io.h"    // IWYU pragma: export
#include "extras/host/arduino/pgmspace.h"  // IWYU pragma: export

// #include avr/interrupt  // Not needed on host.

// These Arduino specific libraries are included directly or indirectly by
// Arduino.h.

// #include "Binary.h"  // Not needed in my code.

// #include "WCharacter.h" provides wrappers around <ctype.h>, so I should use
// those directly. On the other hand, the ctype impl is a bunch of assembly
// language code rather than a lookup table. IFF short on flash, consider
// whether it would be smaller if I wrote my own for the few functions I need
// while decoding a request.
#include "extras/host/arduino/character.h"  // IWYU pragma: export
#include "extras/host/arduino/int_types.h"  // IWYU pragma: export
#include "extras/host/arduino/wstring.h"    // IWYU pragma: export

// Arduino's HardwareSerial.h includes Stream.h, which in turn includes Print.h.
// I'm explicitly including them here to make it easier to work with IWYU.
#include "extras/host/arduino/print.h"   // IWYU pragma: export
#include "extras/host/arduino/random.h"  // IWYU pragma: export
#include "extras/host/arduino/serial.h"  // IWYU pragma: export
#include "extras/host/arduino/stream.h"  // IWYU pragma: export

uint32_t millis();
uint32_t micros();

void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);

#define INPUT 97
#define INPUT_PULLUP 98
#define OUTPUT 99
#define pinMode(pin_number, pin_mode)

#define LOW 0
#define HIGH 1
inline void digitalWrite(uint8_t pin_number, uint8_t value) {}
inline int digitalRead(uint8_t pin_number) { return HIGH; }
inline void analogWrite(uint8_t pin_number, int value) {}
inline int analogRead(uint8_t pin_number) { return 0; }

inline void noInterrupts() {}
inline void interrupts() {}
inline void attachInterrupt(uint8_t interruptNum, void (*userFunc)(),
                            int mode) {}
inline void detachInterrupt(uint8_t interruptNum) {}

#define CHANGE 7
#define FALLING 8
#define RISING 9

#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) \
  ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#define F_CPU 16000000

#endif  // ARDUINO_HOSTUINO_EXTRAS_HOST_ARDUINO_ARDUINO_H_
