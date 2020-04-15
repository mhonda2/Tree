#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

//-------------------------------------------------------------------------
void tree_test_hardcode() {
  printf("=====================TESTING HARDCODE========================\n");

  tree* t = tree_create();
  tree_add(t, "now");
  tree_add(t, "is");
  tree_add(t, "the");
  tree_add(t, "time");
  tree_add(t, "for");
  tree_add(t, "everyone");
  tree_add(t, "to");
  tree_add(t, "take");
  tree_add(t, "action");
  tree_add(t, "and");
  tree_add(t, "help");
  tree_add(t, "the");
  tree_add(t, "people");
  tree_add(t, "in");
  tree_add(t, "need");

  tree_print_inorder(t);
  printf("Size is %zu\n", tree_size(t));
  printf("Is my tree empty? %s\n", tree_empty(t) ? "Yes" : "No");

  tree_clear(t);
  printf("Is my tree empty after clearing? %s\n", tree_empty(t) ? "Yes" : "No");
  printf("Size is %zu\n", tree_size(t));

  free(t);

  printf("=====================END TESTING=============================\n");
}

//-------------------------------------------------------------------------
void tree_test_console_file(int argc, const char* argv[]) {
  printf("===================TESTING CONSOLE/FILE======================\n");

  tree* t = get_input(argc, argv);

  tree_print_inorder(t);
  printf("\nIs my tree empty? %s\n", tree_empty(t) ? "Yes" : "No");
  printf("Size is %zu\n", tree_size(t));

  tree_clear(t);
  printf("Is my tree empty after clearing? %s\n", tree_empty(t) ? "Yes" : "No");
  printf("Size is %zu\n", tree_size(t));

  free(t);

  printf("=====================END TESTING=============================\n");
}
