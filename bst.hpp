#ifndef BST_HPP
#define BST_HPP

struct Bst()
{
  //member functions
  int* search(int key_value) const;
  int* minimum() const;
  int* maximum() const;
  int* successor(Bst_Node const& node) const;
  int* predecessor(Bst_Node const& node) const;
  void add_node(Bst_Node const& node);
  void remove_node(Bst_Node const& node);
}

template <typename T>
struct Bst_Node()
{
  //member variables
  T data_;
  struct Bst_Node* left_child_;
  struct Bst_Node* right_child_;
}

#endif // !BST_HPP