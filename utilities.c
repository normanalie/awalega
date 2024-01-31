#include "utilities.h"



void refreshTerminal(void) {
  system("clear");
  return;
}


int randInt(int min, int max) {
  int number = (rand() % (max - min + 1)) + min;
  return number;
}
