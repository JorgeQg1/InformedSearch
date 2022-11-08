#include "../include/userInput.h"
#include "../include/world.h"

int main(int argc, char *argv[]) {
  size_t mValue = UserInput::askForMValue();
  size_t nValue = UserInput::askForNValue();
  Cell start = UserInput::askForStartPoint(mValue, nValue);
  Cell end = UserInput::askForEndPoint(mValue, nValue);

  World world = World(mValue, nValue, start, end);
  world.AStarAlgorithm();

  return 0;
}