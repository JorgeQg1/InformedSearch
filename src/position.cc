#include "../include/position.h"

Position::Position() {
  xCoord_ = 0;
  yCoord_ = 0;
}

Position::Position(size_t xCoord, size_t yCoord) {
  xCoord_ = xCoord;
  yCoord_ = yCoord;
}

size_t Position::getXCoord() {
  return xCoord_; 
}

size_t Position::getYCoord() {
  return yCoord_;
}