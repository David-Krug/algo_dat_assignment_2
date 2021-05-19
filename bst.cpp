#include "bst.hpp"
#include <iostream>

//Bst
Bst_Node* Bst::search(int key_value, Bst_Node* node) const		//returns the node if it exists in the tree, otherwise returns NULL
{
  std::cout << node->data_ << std::endl;
  std::cout << key_value << std::endl;
  if (node == nullptr) {
    return nullptr;
  }
  if (node->data_ == key_value){
	return node;
  }
  if (node->data_ > key_value) {
	node = node->left_child_;
	std::cout << "ha" << std::endl;
	search(key_value, node);
  }
  if (node->data_ > key_value) {
	node = node->right_child_;
	std::cout << "ha" << std::endl;
	search(key_value, node);
  }
}


Bst_Node* Bst::minimum(Bst_Node* root) const					//returns the node that is the farthest to the left
{
  auto minimum = root;
  while (minimum->left_child_ != nullptr) {
	minimum = minimum->left_child_;
  }
  return minimum;
}

Bst_Node* Bst::maximum(Bst_Node* root) const					//returns the node that is the farthest to the right
{
  auto maximum = root;
  while (maximum->right_child_ != nullptr) {
	maximum = maximum->right_child_;
  }
  return maximum;
}

Bst_Node* Bst::successor(Bst_Node* node) const
{
  if (node->right_child_ != nullptr) {
	return minimum(node->right_child_);
  }
  else {
	auto parent = node->parent_;
	auto child = node;
	while (parent != nullptr && child == parent->right_child_) {
	  child = parent;
	  parent = parent->parent_;
	}
	return parent;
  }
}

Bst_Node* Bst::predecessor(Bst_Node* node) const
{
  if (node->left_child_ != nullptr) {
	return maximum(node->left_child_);
  }
  else {
	auto parent = node->parent_;
	auto child = node;
	while (parent != nullptr && child == parent->left_child_) {
	  child = parent;
	  parent = parent->parent_;
	}
	return parent;
  }
}

void Bst::add_node(int node_value)							//adds a node to the tree
{
  Bst_Node* node = new Bst_Node( node_value );
  //check if the tree has a root
  if (root_ == nullptr) {
	root_ = node;
	return;
  }

  //help pointers for the current and the parent node
  auto position = root_;
  Bst_Node* parent = nullptr;

  //traverse the tree until the position is at a leaf
  while (position != nullptr) {
	parent = position;
	if (position->data_ > node->data_) {
	  position = position->left_child_;
	}
	else if (position->data_ < node->data_) {
	  position = position->right_child_;
	}
	else if (position->data_ == node->data_) {
	  std::cout << node->data_ << " could not be added to the tree because it already exists. \n";
	  return;
	}
  }

  //add the links to the parent and child
  node->parent_ = parent;
  if (parent->data_ < node_value) {
	parent->right_child_ = node;
  }
  else {
	parent->left_child_ = node;
  }
}

Bst_Node* Bst::remove_node(Bst_Node* node)
{
  //remove leaf
  if (node->left_child_ == nullptr && node->right_child_ == nullptr) {
	delete node;
	node = nullptr;
  }
  //remove node with only right child
  else if (node->left_child_ == nullptr) {
	auto temp = node;
	node = node->right_child_;
	delete temp;
  }
  //remove node with only left child
  else if (node->right_child_ == nullptr) {
	auto temp = node;
	node = node->left_child_;
	delete temp;
  }
  //remove node with two childs
  else {
	auto temp = minimum(node);
	node->data_ = temp->data_;
	node->right_child_ = remove_node(node->right_child_);
  }
  return node;
}

void Bst::in_order(Bst_Node* node) {					//sorts the tree in order and prints to the terminal
  if (node == nullptr) {
	return;
  }
  in_order(node->left_child_);
  std::cout << node->data_ << " ";
  in_order(node->right_child_);
}

//Bst_Node

//constructor
Bst_Node::Bst_Node(int data, struct Bst_Node* parent, struct Bst_Node* left_child, struct Bst_Node* right_child) :
  data_{data},
  parent_{parent},
  left_child_{left_child},
  right_child_{right_child}
{}
