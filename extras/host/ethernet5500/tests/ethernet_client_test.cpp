#include "extras/host/ethernet5500/ethernet_client.h"

#include "extras/test_tools/print_to_std_string.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace alpaca {
namespace test {
namespace {

TEST(EthernetClientTest, NoFixtureTest) {
  EthernetClient a(1);
  a = EthernetClient(2);
}

}  // namespace
}  // namespace test
}  // namespace alpaca
