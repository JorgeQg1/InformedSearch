#pragma once
#include <iostream>

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