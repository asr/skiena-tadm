
/*      tree.h

        Header file for binary search tree implementation

        by: Steven Skiena
*/

/*
Copyright 2003 by Steven S. Skiena; all rights reserved.

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/

/*typedef int item_type;*/

#include "item.h"

/* [[[ struct_tree_cut */
typedef struct tree
{
  item_type item;               /* data item */
  struct tree *parent;          /* pointer to parent */
  struct tree *left;            /* pointer to left child */
  struct tree *right;           /* pointer to right child */
} tree;
/* ]]] */
