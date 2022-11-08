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

void World::AStarAlgorithm(size_t option) {
  while(car_.getPosition() != end_.getPosition()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    system("clear");

    std::cout << *this << std::endl;

    std::vector<double> values = std::vector<double>(4, 999999999.9);
    Position aux = car_.getPosition();
    if (aux.getXCoord() + 1 < mSize_) {//Move down can be done
      world_[aux.getXCoord() + 1][aux.getYCoord()].setG(car_.getMoves() + 1);
      if (option == 0) {
        world_[aux.getXCoord() + 1][aux.getYCoord()].calcManhattanHeu(end_.getPosition());
      } else {
        world_[aux.getXCoord() + 1][aux.getYCoord()].calcEuclideanHeu(end_.getPosition());
      }
      values[0] = world_[aux.getXCoord() + 1][aux.getYCoord()].getF();
    }
    if (aux.getYCoord() != 0) {//Move left can be done
      world_[aux.getXCoord()][aux.getYCoord() - 1].setG(car_.getMoves() + 1);
      if (option == 0) {
        world_[aux.getXCoord()][aux.getYCoord() - 1].calcManhattanHeu(end_.getPosition());
      } else {
        world_[aux.getXCoord()][aux.getYCoord() - 1].calcEuclideanHeu(end_.getPosition());
      }
      values[1] = world_[aux.getXCoord()][aux.getYCoord() - 1].getF();
    }
    if (aux.getXCoord() != 0) {//Move up can be done
      world_[aux.getXCoord() - 1][aux.getYCoord()].setG(car_.getMoves() + 1);
      if (option == 0) {
        world_[aux.getXCoord() - 1][aux.getYCoord()].calcManhattanHeu(end_.getPosition());
      } else {
        world_[aux.getXCoord() - 1][aux.getYCoord()].calcEuclideanHeu(end_.getPosition());
      }
      values[2] = world_[aux.getXCoord() - 1][aux.getYCoord()].getF();
    }
    if (aux.getYCoord() + 1 < nSize_) {//Move right can be done
      world_[aux.getXCoord()][aux.getYCoord() + 1].setG(car_.getMoves() + 1);
      if (option == 0) {
        world_[aux.getXCoord()][aux.getYCoord() + 1].calcManhattanHeu(end_.getPosition());
      } else {
        world_[aux.getXCoord()][aux.getYCoord() + 1].calcEuclideanHeu(end_.getPosition());
      }
      values[3] = world_[aux.getXCoord()][aux.getYCoord() + 1].getF();
    }

    int betterPosition = -1;
    double minimum = 99999999.9;
    for (size_t i = 0; i < values.size(); i++) {
      if (values[i] < minimum) {
        minimum = values[i];
        betterPosition = i;
      }
    }

    if (betterPosition == 0) {//Moving down
      car_ = Car(Position(car_.getPosition().getXCoord() + 1, car_.getPosition().getYCoord()));
      car_.setMoves(car_.getMoves() + 1);
      world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    } else if (betterPosition == 1) {//Moving left
      car_ = Car(Position(car_.getPosition().getXCoord(), car_.getPosition().getYCoord() - 1));
      car_.setMoves(car_.getMoves() + 1);
      world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    } else if (betterPosition == 2) {//Moving up
      car_ = Car(Position(car_.getPosition().getXCoord() - 1, car_.getPosition().getYCoord()));
      car_.setMoves(car_.getMoves() + 1);
      world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    } else if (betterPosition == 3) {//Moving right
      car_ = Car(Position(car_.getPosition().getXCoord(), car_.getPosition().getYCoord() + 1));
      car_.setMoves(car_.getMoves() + 1);
      world_[car_.getPosition().getXCoord()][car_.getPosition().getYCoord()] = Cell(car_.getPosition(), VISITED);
    }
  }
  system("clear");
  std::cout << *this << std::endl;
}