# Gesture-Controlled Robot Car

This project is a gesture-controlled Arduino robot car operated using hand tilt movements.
An MPU6050 accelerometer mounted on a glove detects gestures and sends commands wirelessly via Bluetooth to control the car in real time.

## Features
- Gesture-based control using hand tilt
- Moves forward, backward, left, right, and stops
- Wireless communication using Bluetooth (HM-10)
- Real-time motor response
- Modular transmitter–receiver system
- Assistive technology–style interaction

## Hardware Used
- Arduino Nano (Transmitter)
- Arduino UNO (Receiver)
- MPU6050 Accelerometer
- HM-10 Bluetooth Modules(2) (Master & Slave)
- L298N Motor Driver
- DC Motors (4)
- Robot Car Chassis
- 9V Battery and 18650 Li-ion Batteries
- Breadboard, Jumper Wires, Glove

## Libraries Used
- Wire
- SoftwareSerial
