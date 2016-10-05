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
#include <Arduino.h>
#include "Constants.h"

#ifndef CARHANDLER
#define CARHANDLER

class CarHandler {


  public:
    void init();
    void handle(String command);

  private:
     char actions[2];
     int actionPowers[2];
     boolean bothDirections = false;
    // This method will execute read actions
    void executeAll();

    // This method is called to execute each action individually
    void executeAction(char action, int power);

    // Hanldes Forward / Backward Movements
    void go(int direction, int power);

    // Handles Right / Left turns
    void turn(int direction, int power);
};

#endif
