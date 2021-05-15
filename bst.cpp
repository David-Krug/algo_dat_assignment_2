#include "bst.hpp"

//Bst
Bst_Node* Bst::search(int key_value, Bst_Node* node) const		//Should return pointer to node (?) 
{
  if (node->data_ == key_value){
	return node;
  }
  else if (node->data_ > key_value) {
    //if ()
  }
  else if (node->data_ > key_value) {
    
  }
  //if nodeX.value == key_value, return (pointer to) node X
	
  //else if nodeX.value > key_value, check nodeX.leftchild,
	//if NIL, then key_value doesn't exist within tree
	//if not NIL, jump back to first if (recursive function?)

  //else if nodeX.value < key_value, check nodeX.rightchild, 
	//if NIL, then key_value doesn't exist within tree
	//if not NIL, jump back to first if (recursive function?)
}


int* Bst::minimum() const				//Needs node as parameter to know where to start (important for successor & predecessor functions)
{
	//while nodeX.leftchild != NIL:
		//nodeX = nodeX.leftchild
		
	//return nodeX or nodeX.value;
  return nullptr;
}

int* Bst::maximum() const				//Needs node as parameter to know where to start (important for successor & predecessor functions)
{
	//while nodeX.rightchild != NIL:
		//nodeX = nodeX.rightchild
		
	//return nodeX or nodeX.value;
	return nullptr;
}

int* Bst::successor(Bst_Node const& node) const
{
	//if nodeX.rightchild != NIL:
		//get minimum of right subtree

	//else:
		//(find first ancestor reached from the left)
		//check if NodeX is parent's left child:
			//if true, then parent is successor
			//if false, go further up
	return nullptr;
}

int* Bst::predecessor(Bst_Node const& node) const
{
	//if nodeX.leftchild != NIL:
		  //get maximum of left subtree

	//else:
		//find first ancestor reached from the right
		//check if NodeX is parent's right child:
			//if true, then parent is successor
			//if false, go further up
	return nullptr;
}

void Bst::add_node(int node_value)
{
  Bst_Node* node = new Bst_Node( node_value );
  if (root_ == nullptr) {
	root_ = node;
  }
  else {
	bool r;
	auto position = root_;
	auto parent = position;
	while (position != nullptr) {
	  if (position->data_ > node->data_) {
		auto parent = position;
		bool r = false;
		position = position->left_child_;
	  }
	  if (position->data_ < node->data_) {
		auto parent = position;
		bool r = true;
		position = position->right_child_;
	  }
	}
	node->parent_ = parent;
	if (r) {
	  parent->right_child_ = node;
	}
	else {
	  parent->left_child_ = node;
	}
  }

	//while nodeX.value != NIL:
		//if nodeX.value > node.value:
			//nodeX = nodeX.leftchild;
		//if nodeX.value < node.value:
			//nodeX = nodeX.rightchild;

	//insert node at place nodeX
	//(after while-loop, nodeX is empty child of a node)
}

void Bst::remove_node(Bst_Node* node)
{
	//if node.leftchild == NIL and node.rightchild == NIL:
		//replace node with NIL

	//if (node.leftchild != NIL and node.leftchild == NIL) OR (node.leftchild == NIL and node.leftchild != NIL):
		//check if node's child has children and so forth
		//if not: 
			//replace node with node's child 
			//replace node's child with NIL

	//if node.leftchild != NIL and node.rightchild != NIL:
		//if node.rightchild.leftchild == NIL:
			//replace node with node.rightchild
			//replace node.rightchild with NIL
		//else:
			//find and store successor nodeY of node
			//remove_node(nodeY)
			//replace node with nodeY's value
}

//Bst_Node

Bst_Node::Bst_Node(int data_, struct Bst_Node* parent_, struct Bst_Node* left_child_, struct Bst_Node* right_child_)
{}
