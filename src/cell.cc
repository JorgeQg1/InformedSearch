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

void Cell::calcManhattanHeu(Position endPos) {//TODO
  h_ = 1;
}

void Cell::calcEuclideanHeu(Position endPos) {//TODO
  h_ = 1;
}

double Cell::getF() {
  return g_ + h_;
}