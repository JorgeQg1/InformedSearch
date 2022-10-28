#include "../include/world.h"

World::World() {
  mSize_ = 0;
  nSize_ = 0;
  start_ = Cell();
  end_ = Cell();
  car_ = Cell();
  world_ = std::vector<std::vector<Cell>>();
}

World::World(size_t mSize, size_t nSize, Cell start, Cell end) {
  mSize_ = mSize;
  nSize_ = nSize;
  start_ = start;
  end_ = end;
  car_ = Cell(start_.getXCoord(), start_.getYCoord(), CAR);
  for (size_t i = 0; i < mSize_; i++) {
    std::vector<Cell> aux;
    for (size_t j = 0; j < nSize_; j++) {
      if ((i == start.getXCoord()) && (j == start.getYCoord())) {
        aux.push_back(start_);
      } else if ((i == end.getXCoord()) && (j == end.getYCoord())) {
        aux.push_back(end_);
      } else {
        aux.push_back(Cell(i,j));
      }
    }
    world_.push_back(aux);
  }
}

size_t World::getMSize() {
  return mSize_;
}

size_t World::getNSize() {
  return nSize_;
}

Cell World::getStartCell() {
  return start_;
}

Cell World::getEndCell() {
  return end_;
}

void World::moveDefect() {
  if (car_.getXCoord() < mSize_ - 1) {
    car_ = Cell(car_.getXCoord() + 1, car_.getYCoord(), CAR);
  } else if (car_.getYCoord() < nSize_ - 1) {
    car_ = Cell(car_.getXCoord(), car_.getYCoord() + 1, CAR);
  }

  world_[car_.getXCoord()][car_.getYCoord()] = Cell(car_.getXCoord(), car_.getYCoord(), VISITED);
}