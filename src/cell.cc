#include "../include/cell.h"

Cell::Cell() {
  pos_ = Position(0,0);
  value_ = EMPTY;
}

Cell::Cell(Position pos) {
  pos_ = pos;
  value_ = EMPTY;
}

Cell::Cell(Position pos, std::string value) {
  pos_ = pos;
  value_ = value;
}

Position Cell::getPosition() {
  return pos_;
}

std::string Cell::getValue() {
  return value_;
}

void Cell::setG(size_t cost) {
  g_ = cost;
}

void Cell::calcManhattanHeu(Position endPos) {
  int x1 = pos_.getXCoord();
  int y1 = pos_.getYCoord();
  int x2 = endPos.getXCoord();
  int y2 = endPos.getYCoord();
  h_ = std::abs(x1 - x2) + std::abs(y1 - y2);
}

void Cell::calcEuclideanHeu(Position endPos) {
  int x1 = pos_.getXCoord();
  int y1 = pos_.getYCoord();
  int x2 = endPos.getXCoord();
  int y2 = endPos.getYCoord();
  h_ = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

double Cell::getF() {
  return g_ + h_;
}