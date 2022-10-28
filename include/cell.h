#pragma once
#include <iostream>

const std::string VISITED = "#";
const std::string CAR = "C";
const std::string START = "S";
const std::string END = "X";
const std::string EMPTY = " ";

class Cell {
  private:
    size_t xCoord_;
    size_t yCoord_;
    std::string value_;
  public:
    Cell();
    Cell(size_t xCoord, size_t yCoord);
    Cell(size_t xCoord, size_t yCoord, std::string value);
    size_t getXCoord();
    size_t getYCoord();

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
      os << cell.value_;
      return os;
    }
};