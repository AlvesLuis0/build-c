#include <stdio.h>
#include <string.h>
#include "include/fileManager.h"


int main(int argc, char *argv[]) {
  char text[999999];

  callBuilder(text, argc, argv);

  return 1;
}
