/*
 * This file is part of the Project "Carrinho BT"
 * It's entirely developed by Thiago Gomes Marçal Pereira.
 * 
 * CarHandler.hpp is a Handler for the commands received by the Android remote control
 * 
 * Commands must be in the format of <direction-power> pairs.
 * There may up to 2 pairs at the same time, indicating that the car is going forward/backwards and turning in any direction.
 * Forward / Backward may not be handled at the same time.
 * Right / Left turns may not be handled at the sama time.
 * 
 * e.g.
 * f-60:r-30
 * b-95:l-45
 */
#include "Constants.h"

#ifndef CARHANDLER
#define CARHANDLER

class CarHandler {
  

  public:
    void init() {}
    void handle(String command) {
      if (command.length() <= 0)
        return;
        
      // First split the direction to then handle each one individually.
      int separator = command.indexOf(':');
      if (separator == -1) {
        // Just one direction or turn being handled
        bothDirections = false;
        actions[0] = command.charAt(0);
        actionPowers[0] = command.substring(2).toInt();
        
      } else {
        bothDirections = true;
        actions[0] = command.charAt(0);
        actionPowers[0] = command.substring(2, separator).toInt();

        actions[1] = command.charAt(separator + 1);
        actionPowers[1] = command.substring(separator+3).toInt();
      }

      executeAll();
    }

  private:
     char actions[2];
     int actionPowers[2];
     boolean bothDirections = false;
    // This method will execute read actions
    void executeAll() {
      // Execute first action
      executeAction(actions[0], actionPowers[0]);

      if (bothDirections) {
        //Execute second action
        executeAction(actions[1], actionPowers[1]);
      }
      
    }

    // This method is called to execute each action individually
    void executeAction(char action, int power) {
      switch (action) {
        case 'f':
          go(FORWARD, power);
          break;
          
        case 'b':
          go(BACKWARDS, power);
          break;

        case 'r':
          turn(RIGHT, power);
          break;

        case 'l':
          turn(LEFT, power);
          break;

        default:
          // Do nothing - Should never hit here
          break;
      }
    }

    // Hanldes Forward / Backward Movements
    void go(int direction, int power) {
      if (direction == FORWARD) {
        digitalWrite(REAR_MOTOR_IN1, HIGH);
        digitalWrite(REAR_MOTOR_IN2, LOW);
      } else {
        digitalWrite(REAR_MOTOR_IN1, LOW);
        digitalWrite(REAR_MOTOR_IN2, HIGH);
      }

      analogWrite(REAR_MOTOR_EN, map(power, 0, 100, 80, 255));
    }

    // Handles Right / Left turns
    void turn(int direction, int power) {
      if (direction == RIGHT) {
        digitalWrite(FRONT_MOTOR_IN1, HIGH);
        digitalWrite(FRONT_MOTOR_IN2, LOW);
      } else {
        digitalWrite(FRONT_MOTOR_IN1, LOW);
        digitalWrite(FRONT_MOTOR_IN2, HIGH);
      }

      analogWrite(FRONT_MOTOR_EN, map(power, 0, 100, 80, 255));
    }
};

#endif
