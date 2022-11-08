#pragma once
#include <string>
#include <iostream>
#include "../include/stringUtils.h"
#include "../include/cell.h"

class UserInput {
  public:
    static size_t askForMValue();
    static size_t askForNValue();
    static Cell askForStartPoint(size_t mValue, size_t nValue);
    static Cell askForEndPoint(size_t mValue, size_t nValue);
    static size_t askForHeuristic();
};