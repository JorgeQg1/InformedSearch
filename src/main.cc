#include "../include/userInput.h"
#include "../include/world.h"


int main(int argc, char *argv[]) {
  size_t mValue = UserInput::askForMValue();
  size_t nValue = UserInput::askForNValue();
  Cell start = UserInput::askForStartPoint(mValue, nValue);
  Cell end = UserInput::askForEndPoint(mValue, nValue);

  World world = World(mValue, nValue, start, end);

  unsigned var1 =clock();
  world.AStarAlgorithm(UserInput::askForHeuristic());
  unsigned var2 =clock();

  double time = (double(var2 - var1) / CLOCKS_PER_SEC);

  std::cout << "Total segundos: " << time << std::endl;

  return 0;
}