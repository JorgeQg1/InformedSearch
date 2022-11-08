#pragma once
#include <iostream>
#include "../include/position.h"

class Car {
  private:
    Position pos_;
  public:
    Car();
    Car(Position pos);
    Position getPosition();
};