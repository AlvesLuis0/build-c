#include <stdio.h>
#include <string.h>
#include "include/fileManager.h"


int main(int argc, char *args[]) {
  char text[999999];

  if(argc == 2)
    callBuilder(text, args[1]);

  callBuilder(text, "");

  return 1;
}
