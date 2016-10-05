#include <Arduino.h>

/*
 * This file is part of the Project "Carrinho BT"
 * It's entirely developed by Thiago Gomes Marçal Pereira.
 * 
 * Carduino.ino is the main file for the Arduino project
 * 
 */

#include "Constants.h"
#include "CarHandler.hpp"
#include <SoftwareSerial.h>


// Serial Communication for BT Device
SoftwareSerial BTSerial (6,7); //RX, TX

void setup() {
  // Start BT Communication
  BTSerial.begin(BAUD_RATE);

  //Initialize H-Bridge Pins
  pinMode(FRONT_MOTOR_EN, OUTPUT);
  pinMode(FRONT_MOTOR_IN1,OUTPUT);
  pinMode(FRONT_MOTOR_IN2,OUTPUT);

  pinMode(REAR_MOTOR_EN, OUTPUT);
  pinMode(REAR_MOTOR_IN1, OUTPUT);
  pinMode(REAR_MOTOR_IN2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Read data until it finds a ; to identify that the command reached an end.
  // So, calls CarHandler, to detect the desired movement
  String command = "";
  CarHandler handler;

  while (BTSerial.available()) {
      char c = BTSerial.read();

      if (c != ';') {
        command += c;
      } else {
        handler.handle(command);
        command = "";
      }
    }
}
