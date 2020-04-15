#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

//-------------------------------------------------------------------------
tree* get_input(int argc, const char* argv[]) {
  tree* t = tree_create();

  if (argc == 1) {
    fprintf(stderr, "Usage: ./program file/keyboard input\n");
    exit(1);
  }

  if (argc == 2) {
    const char* filename = argv[1];
    file_input(t, filename);
  }

  if (argc > 2) {
    console_input(t, argc, argv);
  }
  return t;
}

//-------------------------------------------------------------------------
void console_input(tree* t, int argc, const char* argv[]) {
  int i = 1;
  char* p = strtok((char*)argv[i++], ",. !");
  tree_add(t, p);

  while (p != NULL && i < argc) {
    p = strtok((char*)argv[i], ", .!");
    tree_add(t, p);
    ++i;
  }
}

//-------------------------------------------------------------------------
void file_input(tree* t, const char* filename) {
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    fclose(f);
    exit(1);
  }

  char line[BUFSIZ];
  memset(line, 0, BUFSIZ);

  while (fgets(line, BUFSIZ, f) != NULL) {
    if (*line == '\n') { continue; }
    char* p = strtok(line, ",. !\n");
    tree_add(t, p);

    while (p != NULL) {
      p = strtok(NULL, ",. !\n");
      if (p == NULL) { continue; }
      tree_add(t, p);
    }
  }

  fclose(f);
}

//-------------------------------------------------------------------------
tnode* tnode_create(const char* word) {
  tnode* p = (tnode*)malloc(sizeof(tnode));
  p->word = strdup(word);   //copy of word allocated on heap
  p->count = 1;
  p->left = NULL;
  p->right = NULL;
  return p;
}

//-------------------------------------------------------------------------
void tnode_delete(tnode* t) {
  free((void*)t->word);
  free(t);
}

//-------------------------------------------------------------------------
tree* tree_create() {
  tree* p = (tree*)malloc(sizeof(tree));
  p->root = NULL;
  p->size = 0;
  return p;
}

//-------------------------------------------------------------------------
static void tree_deletenodes(tree* t, tnode* p) {
  if ( p == NULL) { return; }

  tree_deletenodes(t, p->left);
  tree_deletenodes(t, p->right);
  tnode_delete(p);
  t->size--;
}

//-------------------------------------------------------------------------
void tree_delete(tree* t) { tree_deletenodes(t, t->root); }

//-------------------------------------------------------------------------
bool tree_empty(tree* t) { return t->size == 0; }

//-------------------------------------------------------------------------
size_t tree_size(tree* t) { return t->size; }

//-------------------------------------------------------------------------
static tnode* tree_addnode(tree* t, tnode** p, const char* w) {
  int compare;

  if (*p == NULL) {
    *p = tnode_create(w);
    t->size++;
  } else if ((compare = strcmp(w, (*p)->word)) == 0) {
    (*p)->count++;
  } else if (compare < 0) { tree_addnode(t, &(*p)->left, w);
  } else {
    tree_addnode(t, &(*p)->right, w);
  }

  return *p;
}

//-------------------------------------------------------------------------
tnode* tree_add(tree* t, const char* word) {
  tnode* p = tree_addnode(t, &(t->root), word);
  return p;
}

//-------------------------------------------------------------------------
void tree_clear(tree* t) {
  tree_delete(t);
  t->root = NULL;
  t->size = 0;
}

//-------------------------------------------------------------------------
void tree_print(tnode* p) {
  printf("%s -- %d  (%p, %p)\n", p->word, p->count, p->left, p->right);
}

//-------------------------------------------------------------------------
static void tree_printnodes_inorder(tree* t, tnode* p) {
  if (p == NULL) { return; }

  tree_printnodes_inorder(t, p->left);
  tree_print(p);
  tree_printnodes_inorder(t, p->right);
}

//-------------------------------------------------------------------------
void tree_print_inorder(tree* t) {
  tree_printnodes_inorder(t, t->root);
}

//-------------------------------------------------------------------------
static void tree_printnodes_preorder(tree* t, tnode* p) {
  if (p == NULL) { return; }

  tree_print(p);
  tree_printnodes_preorder(t, p->left);
  tree_printnodes_preorder(t, p->right);
}

//-------------------------------------------------------------------------
void tree_print_preorder(tree* t) {
  tree_printnodes_preorder(t, t->root);
}

//-------------------------------------------------------------------------
static void tree_printnodes_postorder(tree* t, tnode* p) {
  if (p == NULL) { return; }

  tree_printnodes_postorder(t, p->left);
  tree_printnodes_postorder(t, p->right);
  tree_print(p);
}

//-------------------------------------------------------------------------
void tree_print_postorder(tree* t) {
  tree_printnodes_postorder(t, t->root);
}
