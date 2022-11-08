#include "../include/car.h"

Car::Car() {
  pos_ = Position();
  nMoves_ = 0;
}

Car::Car(Position pos) {
  pos_ = pos;
  nMoves_ = 0;
}

Position Car::getPosition() {
  return pos_;
}

size_t Car::getMoves() {
  return nMoves_;
}

void Car::setMoves(size_t nMoves) {
  nMoves_ = nMoves;
}