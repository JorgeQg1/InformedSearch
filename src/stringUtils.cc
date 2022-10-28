#include "../include/stringUtils.h"

/**
 * @brief   Static method used to check if a string is a natural number
 * @param   str  The string to be checked
 * @return  True if it is a number, false if not
 */
bool StringUtils::isStringNumber(std::string str) {
  if (str.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  }

  return true;
}