/************************************************************
 * Project Title : Gesture-Controlled Robot Car
 * Author: DiaaEldin Elabsy and Suchi Chowdhury
 * Date: Spring 2025
 *
 * Description:
 * This sketch is used to configure and pair HM-10 Bluetooth
 * modules using AT commands. It allows setting the module
 * role (Master or Slave), baud rate, and device name through
 * the Serial Monitor.
 *
 ************************************************************/

#include <SoftwareSerial.h>

// RX, TX for HM-10 Bluetooth module
SoftwareSerial BT(10, 11);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Enter AT commands:");
}

void loop() {
  // Forward data from Bluetooth to Serial Monitor
  if (BT.available()) {
    Serial.write(BT.read());
  }

  // Forward data from Serial Monitor to Bluetooth
  if (Serial.available()) {
    BT.write(Serial.read());
  }
}
