#ifndef ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_MOCK_ETHERNET_CLIENT_H_
#define ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_MOCK_ETHERNET_CLIENT_H_

#include <stdint.h>

#include <cstddef>

#include "extras/host/arduino/ip_address.h"
#include "extras/host/ethernet5500/ethernet_client.h"
#include "gmock/gmock.h"

class MockEthernetClient : public EthernetClient {
 public:
  MOCK_METHOD(int, connect, (class IPAddress, uint16_t), (override));

  MOCK_METHOD(int, connect, (const char *, uint16_t), (override));

  MOCK_METHOD(size_t, write, (uint8_t), (override));

  MOCK_METHOD(size_t, write, (const uint8_t *, size_t), (override));

  MOCK_METHOD(int, available, (), (override));

  MOCK_METHOD(int, read, (), (override));

  MOCK_METHOD(int, read, (uint8_t *, size_t), (override));

  MOCK_METHOD(int, peek, (), (override));

  MOCK_METHOD(void, flush, (), (override));

  MOCK_METHOD(void, stop, (), (override));

  MOCK_METHOD(uint8_t, connected, (), (override));

  //  MOCK_METHOD(bool, operator bool, (), (override));

  MOCK_METHOD(uint8_t, status, (), (override));

  MOCK_METHOD(uint8_t, getSocketNumber, (), (const, override));
};

#endif  // ARDUINO_HOSTUINO_EXTRAS_TEST_TOOLS_MOCK_ETHERNET_CLIENT_H_
