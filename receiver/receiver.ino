/************************************************************
 * Project Title : Gesture-Controlled Robot Car
 *Author: DiaaEldin Elabsy and Suchi Chowdhury,
 * Date: Spring 2025
 *
 * Description:
 * Receives gesture commands via Bluetooth from the transmitter
 * and controls four DC motors through the L298N motor driver
 * to move the robot car in real time.
 *
 ************************************************************/

#include <SoftwareSerial.h>

// RX, TX for HM-10 Bluetooth module
SoftwareSerial BT(10, 11);

// Motor driver pins (L298N)
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 9;
int ENB = 8;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Receiver Ready");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set motor speed
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void loop() {
  if (BT.available()) {
    char cmd = BT.read();

    Serial.print("Received: ");
    Serial.println(cmd);

    if (cmd == 'F') forward();
    else if (cmd == 'B') backward();
    else if (cmd == 'L') left();
    else if (cmd == 'R') right();
    else stopMotors();
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("→ Forward");
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("→ Backward");
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("→ Left");
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("→ Right");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("→ Stop");
}
