/************************************************************
 * Project Title : Gesture-Controlled Robot Car
 * Author: DiaaEldin Elabsy and Suchi Chowdhury
 * Date: Spring 2025
 *
 * Description:
 * Reads hand tilt gestures using the MPU6050 accelerometer,
 * converts tilt angles into movement commands, and transmits
 * them wirelessly to the robot car via Bluetooth.
 *
 ************************************************************/

#include <Wire.h>
#include <SoftwareSerial.h>

// RX, TX for HM-10 Bluetooth module
SoftwareSerial BT(10, 11);

// I2C address of MPU6050
const int MPU = 0x68;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Gesture Transmitter Ready");

  // Wake up MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  // Request accelerometer data
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  int16_t AcX = Wire.read() << 8 | Wire.read();
  int16_t AcY = Wire.read() << 8 | Wire.read();
  int16_t AcZ = Wire.read() << 8 | Wire.read();

  // Ignore invalid readings
  if (AcY == 0 && AcZ == 0) return;

  // Calculate tilt angles
  float angleX = atan2((float)AcY, (float)AcZ) * 180 / PI;
  float denom = sqrt((float)AcY * AcY + (float)AcZ * AcZ);
  if (denom == 0) denom = 1;
  float angleY = atan2(-(float)AcX, denom) * 180 / PI;

  char cmd = 'S'; // Default Stop

  if (angleY > 20) cmd = 'F';
  else if (angleY < -20) cmd = 'B';
  else if (angleX > 20) cmd = 'R';
  else if (angleX < -20) cmd = 'L';
  else cmd = 'S';

  // Send command via Bluetooth
  BT.write(cmd);

  Serial.print("Command Sent: ");
  Serial.println(cmd);

  delay(300);
}
