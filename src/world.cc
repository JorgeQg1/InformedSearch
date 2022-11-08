#include "../include/world.h"

World::World() {
  mSize_ = 0;
  nSize_ = 0;

  start_ = Cell();
  end_ = Cell();

  car_ = Car();

  world_ = std::vector<std::vector<Cell>>();
}

World::World(size_t mSize, size_t nSize, Cell start, Cell end) {
  mSize_ = mSize;
  nSize_ = nSize;

  start_ = start;
  end_ = end;

  car_ = Car(start_.getPosition());

  for (size_t i = 0; i < mSize_; i++) {
    std::vector<Cell> aux;
    for (size_t j = 0; j < nSize_; j++) {
      if (start.getPosition() == Position(i,j)) {
        aux.push_back(start_);
      } else if (end.getPosition() == Position(i,j)) {
        aux.push_back(end_);
      } else {
        aux.push_back(Cell(Position(i,j)));
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

bool World::moveDefect() {
  if (car_.getPosition().getXCoord() < mSize_ - 1) {
    car_ = Car(Position(car_.getPosition().getXCoord() + 1, car_.getPosition().getYCoord()));
    world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    return true;
  } else if (car_.getPosition().getYCoord() < nSize_ - 1) {
    car_ = Car(Position(car_.getPosition().getXCoord(), car_.getPosition().getYCoord() + 1));
    world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    return true;
  }
  return false;
}

void World::drawPath() {
  bool canMove = true;
  while (canMove) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    system("clear");

    std::cout << *this << std::endl;
    canMove = this->moveDefect();
  }
}