#pragma once
#include <iostream>
#include "../include/position.h"

class Car {
  private:
    Position pos_;
    size_t nMoves_;
  public:
    Car();
    Car(Position pos);
    Position getPosition();

    size_t getMoves();
    void setMoves(size_t nMoves);
};