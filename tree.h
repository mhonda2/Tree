#include <stdio.h>
#include <stdbool.h>

#ifndef TREE_H
#define TREE_H


//-------------------------------------------------------------------------
typedef struct tnode tnode;
struct tnode {
  const char* word;
  int count;
  tnode* left;
  tnode* right;
};

//-------------------------------------------------------------------------
typedef struct tree tree;
struct tree {
  tnode* root;
  size_t size;
};

//-------------------------------------------------------------------------
tree* get_input(int argc, const char* argv[]);
void console_input(tree* t, int argc, const char* argv[]);
void file_input(tree* t, const char* filename);

//-------------------------------------------------------------------------
tnode* tnode_create(const char* word);
void tnode_delete(tnode* t);

//-------------------------------------------------------------------------
tree* tree_create();
static void tree_deletenodes(tree* t, tnode* p);
void tree_delete(tree* t);

//-------------------------------------------------------------------------
bool tree_empty(tree* t);
size_t tree_size(tree* t);

//-------------------------------------------------------------------------
static tnode* tree_addnode(tree* t, tnode** p, const char* w);
tnode* tree_add(tree* t, const char* word);

//-------------------------------------------------------------------------
void tree_clear(tree* t);
void tree_print(tnode* p);

//-------------------------------------------------------------------------
static void tree_printnodes_inorder(tree* t, tnode* p);
void tree_print_inorder(tree* t);

//-------------------------------------------------------------------------
static void tree_printnodes_preorder(tree* t, tnode* p);
void tree_print_preorder(tree* t);

//-------------------------------------------------------------------------
static void tree_printnodes_postorder(tree* t, tnode* p);
void tree_print_postorder(tree* t);

//-------------------------------------------------------------------------
void tree_print_levelorder(tree* t);

//-------------------------------------------------------------------------
void tree_test_hardcode();
void tree_test_console_file();

#endif
