#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include "../include/cell.h"
#include "../include/car.h"

class World {
  private:
    size_t mSize_;
    size_t nSize_;
    Cell start_;
    Cell end_;

    Car car_;
    std::vector<std::vector<Cell>> world_;
  public:
    World();
    World(size_t mSize, size_t nSize, Cell start, Cell end);
    size_t getMSize();
    size_t getNSize();
    Cell getStartCell();
    Cell getEndCell();

    void AStarAlgorithm(size_t option);

    friend std::ostream& operator<<(std::ostream& os, const World& world) {
      Car aux = world.car_;
      for (size_t i = 0; i < world.world_.size(); i++) {
        for (size_t j = 0; j < world.world_[i].size(); j++) {
          if ((i == aux.getPosition().getXCoord()) && (j == aux.getPosition().getYCoord())) {
            os << "|" << CAR;
          } else {
            os << "|" << world.world_[i][j];
          }
        }
        os << std::endl;
      }
      return os;
    }
};