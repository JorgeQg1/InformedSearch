#include <ctime>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include "../include/stringUtils.h"
#include "../include/cell.h"
#include "../include/world.h"

int main(int argc, char *argv[]) {
  size_t mValue;
  size_t nValue;
  Cell start;
  Cell end;

  {
    std::string option = "";
    while (option.empty()) {
      std::cout << "Please introduce M value for the map bigger than 0: ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        mValue = std::atoi(option.c_str());
        if (mValue == 0) {
          option = "";
        }
      }
    }
  }

  {
    std::string option = "";
    while (option.empty()) {
      std::cout << "Please introduce N value for the map bigger than 0: ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        nValue = std::atoi(option.c_str());
        if (nValue == 0) {
          option = "";
        }
      }
    }
  }

  std::cout << std::endl;

  {
    size_t xCoord;
    size_t yCoord;

    std::string option = "";
    while (option.empty()) {
      std::cout << "Please introduce x coordinate value for the start point less than " << nValue << ": ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        xCoord = std::atoi(option.c_str());
        if ((xCoord > nValue) || (xCoord == 0)) {
          option = "";
        }
      }
    }

    option = "";
    while (option.empty()) {
      std::cout << "Please introduce y coordinate value for the start point less than " << mValue << ": ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        yCoord = std::atoi(option.c_str());
        if ((yCoord > mValue) || (yCoord == 0)) {
          option = "";
        }
      }
    }
    start = Cell(xCoord - 1, yCoord - 1, START);
  }

  std::cout << std::endl;

  {
    size_t xCoord;
    size_t yCoord;

    std::string option = "";
    while (option.empty()) {
      std::cout << "Please introduce x coordinate value for the start point less than " << nValue << ": ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        xCoord = std::atoi(option.c_str());
        if ((xCoord > nValue) || (xCoord == 0)) {
          option = "";
        }
      }
    }

    option = "";
    while (option.empty()) {
      std::cout << "Please introduce y coordinate value for the start point less than " << mValue << ": ";
      std::cin >> option;
      if (!StringUtils::isStringNumber(option)) {
        option = "";
      } else {
        yCoord = std::atoi(option.c_str());
        if ((yCoord > mValue) || (yCoord == 0)) {
          option = "";
        }
      }
    }
    end = Cell(xCoord - 1, yCoord - 1, END);
  }

  std::cout << std::endl;

  World world = World(mValue, nValue, start, end);

  while (true) {
    system("clear");
    std::cout << world << std::endl;
    world.moveDefect();
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }

  return 0;
}