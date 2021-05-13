#include "bst.hpp"

/*
void printBST (Bst_Node const& node, FILE* file) {
    fprintf(file, "digraph BST { \n");
    fprintf(file, "    node [fontname=\"Arial\"]; \n");
    fprintf(file, "    graph [ordering="out"]; \n");

    if (node.value == NIL) {
        fprintf(file, "\n");
    }
    else if (node.rightchild == NIL && node.leftchild == NIL) {
        fprintf(stream, "    %d; \n", node.value);
    }
    else {
        print_node(node, file);
    }
    fprintf(file, "}");
}

void print_node (Bst_Node const& node, FILE* file) {
    static int nil = 0;

    if (node.leftchild != NIL) {
        fprintf(file, "    %d -> %d; \n", node.value, node.leftchild.value);
        print_node(node.leftchild, file);
    }
    else {
        print_null(node.value, nil++, file);
    }

    if (node.rightchild != NIL) {
        fprintf(file, "    %d -> %d; \n", node.value, node.rightchild.value);
        print_node(node.rightchild, file);
    }
    else {
        print_null(node.value, nil++, file);
    }
}

void print_nil(int key, int nilcount, FILE* file)
{
    fprintf(file, "    nil%d [shape=point]; \n", nilcount);
    fprintf(file, "    %d -> nil%d; \n", key, nilcount);
}
*/

int main()
{
  //printBST()
  return 1;
}