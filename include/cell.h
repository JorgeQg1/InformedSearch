#pragma once
#include <iostream>
#include "../include/position.h"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";

const std::string EMPTY = " ";
const std::string VISITED = GREEN + "#" + RESET;
const std::string CAR = RED + "C" + RESET;

const std::string START = BLUE + "S" + RESET;
const std::string END = CYAN + "X" + RESET;


class Cell {
  private:
    Position pos_;
    std::string value_;

    size_t g_;
    double h_;
  public:
    Cell();
    Cell(Position pos);
    Cell(Position pos, std::string value);
    Position getPosition();
    std::string getValue();

    void setG(size_t cost);
    void calcManhattanHeu(Position endPos);
    void calcEuclideanHeu(Position endPos);
    double getF();

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
      os << cell.value_;
      return os;
    }
};