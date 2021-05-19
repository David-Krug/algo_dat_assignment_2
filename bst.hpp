#ifndef BST_HPP
#define BST_HPP

//template <typename T>;
struct Bst_Node
{
  Bst_Node() = default;
  Bst_Node(int data, struct Bst_Node* parent = nullptr, struct Bst_Node* left_child = nullptr, struct Bst_Node* right_child = nullptr);
  //member variables
  int data_ = 0;
  struct Bst_Node* parent_ = nullptr;
  struct Bst_Node* left_child_ = nullptr;
  struct Bst_Node* right_child_ = nullptr;
};

struct Bst
{
  //member functions
  Bst_Node* search(int key_value, Bst_Node* node) const;
  Bst_Node* minimum(Bst_Node* node) const;
  Bst_Node* maximum(Bst_Node* node) const;
  Bst_Node* successor(Bst_Node* node) const;
  Bst_Node* predecessor(Bst_Node* node) const;
  void add_node(int node_value);
  Bst_Node* remove_node(Bst_Node* node);
  void in_order(Bst_Node* node);
  //member variables
  struct Bst_Node* root_ = nullptr;
};

#endif // !BST_HPP