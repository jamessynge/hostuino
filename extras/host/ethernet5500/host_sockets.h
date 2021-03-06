#ifndef ARDUINO_HOSTUINO_EXTRAS_HOST_ETHERNET5500_HOST_SOCKETS_H_
#define ARDUINO_HOSTUINO_EXTRAS_HOST_ETHERNET5500_HOST_SOCKETS_H_

// Methods to hide the differences between the Berkley Socket API (on Linux) and
// the API exposed by the various Ethernet libraries for Arduino.
//
// Author: james.synge@gmail.com

// TODO(jamessynge): Consider implementing Ethernet5500/src/utility/socket.*
// using the *nix Socket API, along with relevant portions of utility/w5500.*
// needed by EthernetClient, then using Ethernet5500/src/EthernetClient.*
// (approximately) as is.

#include "extras/host/ethernet5500/ethernet_config.h"

namespace alpaca {
struct HostSockets {
  // Set socket 'sock_num' to listen for new TCP connections on port 'tcp_port',
  // regardless of what that socket is doing now. Returns true if able to do so;
  // false if not (e.g. if sock_num or tcp_port is invalid).
  static bool InitializeTcpListenerSocket(int sock_num, uint16_t tcp_port);

  // Find an unused socket and start it listening for new TCP connections on
  // port 'tcp_port', regardless of what that socket is doing now. Returns the
  // socket number picked if able to do so, or -1 if not (e.g. if tcp_port is
  // invalid or non-are available).
  static int InitializeTcpListenerSocket(uint16_t tcp_port);

  // If socket 'sock_num' is listening for TCP connections, and is not already
  // connected to a client, and a new connection is available, accept it.
  static bool AcceptConnection(int sock_num);

  // Returns true if socket 'sock_num' is connected to a peer.
  static bool IsConnected(int sock_num);

  // Tell the peer that we're done writing to the connection.
  static bool Disconnect(int sock_num);

  // SnSR::CLOSE_WAIT && no data available to read.
  static bool IsClientDone(int sock_num);

  // Is the connection open for writing (i.e. this end hasn't closed or
  // half-closed it)?
  static bool IsOpenForWriting(int sock_num);

  // Returns true if the socket is completely closed (not in use for any
  // purpose).
  static bool SocketIsClosed(int sock_num);

  // Returns an SnSR value.
  static uint8_t SocketStatus(int sock_num);

  // Returns the number of bytes available for reading, or 0 if there is an
  // error reading that info.
  static int AvailableBytes(int sock_num);
};
}  // namespace alpaca

#endif  // ARDUINO_HOSTUINO_EXTRAS_HOST_ETHERNET5500_HOST_SOCKETS_H_
