#include "../include/car.h"

Car::Car() {
  pos_ = Position();
}

Car::Car(Position pos) {
  pos_ = pos;
}

Position Car::getPosition() {
  return pos_;
}