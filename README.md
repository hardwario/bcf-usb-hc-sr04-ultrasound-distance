<a href="https://www.hardwario.com/"><img src="https://www.hardwario.com/ci/assets/hw-logo.svg" width="200" alt="HARDWARIO Logo" align="right"></a>

[![Travis](https://img.shields.io/travis/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance/master.svg)](https://travis-ci.org/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance)
[![Release](https://img.shields.io/github/release/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance.svg)](https://github.com/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance/releases)
[![License](https://img.shields.io/github/license/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance.svg)](https://github.com/bigclownprojects/bcf-usb-hc-sr04-ultrasound-distance/blob/master/LICENSE)
[![Twitter](https://img.shields.io/twitter/follow/hardwario_en.svg?style=social&label=Follow)](https://twitter.com/hardwario_en)

# HC-SR04 ultrasound distance sensor

## Power
If you use original HC-SR04 you need to power sensor with 5V.
On Core Module R2.3 and nwer you can use +5V contact on PCB near the BOOT pin.
The TRIG signal and ECHO signals doesn't need any level converter. Sensor is OK with 3V input and MCU is ok with 5V input.

If you use 3V variant of this sensor, you can power it from the VCC 3.3V pin on the Core Module

## Sensor connection
- P8 - ECHO
- P9 - TRIG

This repository contains firmware for [Core Module](https://shop.bigclown.com/core-module).

If you want to get more information about Core Module, firmware and how to work with it, please follow this link:

**https://developers.hardwario.com/firmware/basic-overview/**

User's application code (business logic) goes into `app/application.c`.
The default content works as a *Hello World* example.
When flashed into Core Module, it toggles LED state with each button press.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT/) - see the [LICENSE](LICENSE) file for details.

---

Made with &#x2764;&nbsp; by [**HARDWARIO s.r.o.**](https://www.hardwario.com/) in the heart of Europe.
