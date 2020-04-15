#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//-------------------------------------------------------------------------
int main(int argc, const char* argv[]) {

  tree_test_console_file(argc, argv);

  tree_test_hardcode();

  return 0;
}
