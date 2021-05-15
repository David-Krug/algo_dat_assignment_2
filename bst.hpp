#ifndef BST_HPP
#define BST_HPP

//template <typename T>;
struct Bst_Node
{
  Bst_Node() = default;
  Bst_Node(int data_, struct Bst_Node* parent_ = nullptr, struct Bst_Node* left_child_ = nullptr, struct Bst_Node* right_child_ = nullptr);
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
  int* minimum() const;
  int* maximum() const;
  int* successor(Bst_Node const& node) const;
  int* predecessor(Bst_Node const& node) const;
  void add_node(int node_value);
  void remove_node(Bst_Node* node);
  //member variables
  struct Bst_Node* root_ = nullptr;
};

#endif // !BST_HPP