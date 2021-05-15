#include "bst.hpp"

//Bst
int* search(int key_value, Bst_Node const* node) const		//Should return pointer to node (?) 
{
  if (node->data_ == key_value){
	return node;
  }
  else if (node->data_ > key_value) {
    if ()
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


int* minimum() const				//Needs node as parameter to know where to start (important for successor & predecessor functions)
{
	//while nodeX.leftchild != NIL:
		//nodeX = nodeX.leftchild
		
	//return nodeX or nodeX.value;
  return nullptr;
}

int* maximum() const				//Needs node as parameter to know where to start (important for successor & predecessor functions)
{
	//while nodeX.rightchild != NIL:
		//nodeX = nodeX.rightchild
		
	//return nodeX or nodeX.value;
}

int* successor(Bst_Node const& node) const
{
	//if nodeX.rightchild != NIL:
		//get minimum of right subtree

	//else:
		//(find first ancestor reached from the left)
		//check if NodeX is parent's left child:
			//if true, then parent is successor
			//if false, go further up
}

int* predecessor(Bst_Node const& node) const
{
	//if nodeX.leftchild != NIL:
		  //get maximum of left subtree

	//else:
		//find first ancestor reached from the right
		//check if NodeX is parent's right child:
			//if true, then parent is successor
			//if false, go further up
}

void add_node(Bst_Node const& node)
{
	//while nodeX.value != NIL:
		//if nodeX.value > node.value:
			//nodeX = nodeX.leftchild;
		//if nodeX.value < node.value:
			//nodeX = nodeX.rightchild;

	//insert node at place nodeX
	//(after while-loop, nodeX is empty child of a node)
}

void remove_node(Bst_Node const& node)
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
