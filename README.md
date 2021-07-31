# About Hostuino

I find that I can develop software (think, code, compile/link, test/debug,
think) much faster by iterating on a host (Linux box, in my case), rather than
re-uploading to the target Arduino for each test/debug phase. Therefore I've
recreated (including copying of APIs) just enough of the Arduino API, and
relevant libraries (e.g. EEPROM), to enable this.

## See Also

Others have explored the topic of host based unit testing of Arduino libraries,
and also supporting embedded unit testing of Arduino code:

*   https://github.com/bxparks/EpoxyDuino
*   https://github.com/mmurdoch/arduinounit
*   https://github.com/bxparks/AUnit

I've written most of my tests based on googletest, a C++ Unit Testing framework
from Google. I use it at work and really appreciate what it provides.

*   https://github.com/google/googletest/
