#include "../include/userInput.h"

size_t UserInput::askForMValue() {
  size_t mValue;
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

  return mValue;
}

size_t UserInput::askForNValue() {
  size_t nValue;
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
  std::cout << std::endl;
  return nValue;
}

Cell UserInput::askForStartPoint(size_t mValue, size_t nValue) {
  size_t xCoord;
  size_t yCoord;

  std::string option = "";
  while (option.empty()) {
    std::cout << "Please introduce x coordinate value for the start point less or equal than " << mValue << ": ";
    std::cin >> option;
    if (!StringUtils::isStringNumber(option)) {
      option = "";
    } else {
      xCoord = std::atoi(option.c_str());
      if ((xCoord > mValue) || (xCoord == 0)) {
        option = "";
      }
    }
  }
  option = "";
  while (option.empty()) {
    std::cout << "Please introduce y coordinate value for the start point less or equal than " << nValue << ": ";
    std::cin >> option;
    if (!StringUtils::isStringNumber(option)) {
      option = "";
    } else {
      yCoord = std::atoi(option.c_str());
      if ((yCoord > nValue) || (yCoord == 0)) {
        option = "";
      }
    }
  }
  std::cout << std::endl;
  return Cell(Position(xCoord - 1, yCoord - 1), START);
}

Cell UserInput::askForEndPoint(size_t mValue, size_t nValue) {
  size_t xCoord;
  size_t yCoord;

  std::string option = "";
  while (option.empty()) {
    std::cout << "Please introduce x coordinate value for the end point less or equal than " << mValue << ": ";
    std::cin >> option;
    if (!StringUtils::isStringNumber(option)) {
      option = "";
    } else {
      xCoord = std::atoi(option.c_str());
      if ((xCoord > mValue) || (xCoord == 0)) {
        option = "";
      }
    }
  }
  option = "";
  while (option.empty()) {
    std::cout << "Please introduce y coordinate value for the end point less or equal than " << nValue << ": ";
    std::cin >> option;
    if (!StringUtils::isStringNumber(option)) {
      option = "";
    } else {
      yCoord = std::atoi(option.c_str());
      if ((yCoord > nValue) || (yCoord == 0)) {
        option = "";
      }
    }
  }
  std::cout << std::endl;
  return Cell(Position(xCoord - 1, yCoord - 1), END);
}

size_t UserInput::askForHeuristic() {
  size_t nValue;
  std::string option = "";
  while (option.empty()) {
    std::cout << "Please introduce type of heuristic (0 Manhattan/1 Euclidean): ";
    std::cin >> option;
    if (!StringUtils::isStringNumber(option)) {
      option = "";
    } else {
      nValue = std::atoi(option.c_str());
      if ((nValue != 0) && (nValue != 1)) {
        option = "";
      }
    }
  }
  std::cout << std::endl;
  return nValue;
}