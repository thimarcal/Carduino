/*
 * This file is part of the Project "Carrinho BT"
 * It's entirely developed by Thiago Gomes Marçal Pereira.
 * 
 * Constants.h is a file containing all pertinent constants to be used by the code
 * 
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H
 
// Default Baud Rate for Serial Communication
#define BAUD_RATE           9600

// Pins connected to BT Adapter HC06
#define BT_TX               6
#define BT_RX               7

// Pins connected to H-Bridge L298N
#define FRONT_MOTOR_EN      3
#define FRONT_MOTOR_IN1     4
#define FRONT_MOTOR_IN2     5

#define REAR_MOTOR_EN       8
#define REAR_MOTOR_IN1      9
#define REAR_MOTOR_IN2      10

// If decide to use LED Lamps, defines go here
//#define LED_LAMPS         12

// Constants to define direction
#define FORWARD             0
#define BACKWARDS           1
#define LEFT                2
#define RIGHT               3

// Time constants for motor functioning in milliseconds
#define DURATION            100


#endif
