#include "../include/cell.h"

Cell::Cell() {
  xCoord_ = 0;
  yCoord_ = 0;
  value_ = EMPTY;
}

Cell::Cell(size_t xCoord, size_t yCoord) {
  xCoord_ = xCoord;
  yCoord_ = yCoord;
  value_ = EMPTY;
}

Cell::Cell(size_t xCoord, size_t yCoord, std::string value) {
  xCoord_ = xCoord;
  yCoord_ = yCoord;
  value_ = value;
}

size_t Cell::getXCoord() {
  return xCoord_; 
}

size_t Cell::getYCoord() {
  return yCoord_;
}