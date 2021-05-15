//#include "bst.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/*
void printBST(Bst_Node const& node) {
    std::cout << "yeaaahhhh!!! \n";
    std::ofstream Graphfile("Graph3.txt");
    Graphfile << "digraph BST { \n";
    Graphfile << "    node [fontname=\"Arial\"]; \n";
    Graphfile << "    graph [ordering=\"out\"]; \n";

    if (!node.data_) {
        Graphfile << "\n";
    }
    else if (!node.rightchild && !node.leftchild) {
        Graphfile << "    " << node.data_ << "; \n";
    }
    else {
        print_node(Graphfile, file);
    }

    Graphfile << "}";
    Graphfile.close();
}

void print_node (Bst_Node const& node, FILE* file) {
    static int nil = 0;

    if (node.leftchild != NIL) {
        fprintf(file, "    %d -> %d; \n", node.data_, node.leftchild.data_);
        print_node(node.leftchild, file);
    }
    else {
        print_null(node.data_, nil++, file);
    }

    if (node.rightchild != NIL) {
        fprintf(file, "    %d -> %d; \n", node.data_, node.rightchild.data_);
        print_node(node.rightchild, file);
    }
    else {
        print_null(node.data_, nil++, file);
    }
}

void print_nil(int key, int nilcount, FILE* file)
{
    fprintf(file, "    nil%d [shape=point]; \n", nilcount);
    fprintf(file, "    %d -> nil%d; \n", key, nilcount);
}*/

std::vector<int> str_to_vector(std::string input)
{
    std::stringstream ss(input);

    std::vector<int> sequence;
    for (int i; ss >> i;) {
        sequence.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
    return sequence;
}

int main()
{
    std::cout << "Please type in the elements of the tree separated by comma (Integers only):\n";
    std::string arrstr;
    std::cin >> arrstr;
    std::vector<int> sequence = str_to_vector(arrstr);

    std::cout << "\nBuilding a tree containing the following integers: \n";
    //Bst bstmain;
    for (int i : sequence) {
        //bstmain.add_node_(i);
        std::cout << i << " ";
    }

    std::string input2 = "start", input3 = "start"; 
    //Bst_Node* found;

    while (input2 != "quit") {

        std::cout << "\n \n Which function of the tree would you like to execute? (enter 'quit' to exit) \n"
                    << "- Find maximum or minimum - Enter 'max' or 'min' \n"
                    << "- Search the tree for a specific value - Enter 'search' \n"
                    << "- Find the pre- or successor of a node - Enter 'pre' or 'suc' \n"
                    << "- Add or remove a node from the tree - Enter 'add' or 'rem' \n";
        std::cin.ignore();
        std::cin >> input2;

        if (input2 == "min") {
            std::cout << "Searching for the minimum of the tree. \n";
            //*found = bstmain.minimum()
            //std::cout << "The minimum of the tree is " << found.data_;
        }

        else if (input2 == "max") {
            std::cout << "Searching for the maximum of the tree. \n";
            //*found = bstmain.maximum()
            //std::cout << "The maximum of the tree is " << found.data_;
        }

        else if (input2 == "search") {
            std::cout << "Which value would you like to search the tree for? \n";
            /*std::cin.ignore();
            input3 = std::cin.get();
            *found = bstmain.search(input3);
            if (*found) {
                std::cout << found.data_ << " is a part of the tree. \n"
                          << "Its left child is " << found.left_child_.data_ << "\n"
                          << "Its right child is " << found.right_child_.data_ << "\n"
                          << "Its parent is " << found.parent_.data_ << "\n";
            }
            else {
                std::cout << input3 << " could not be found within the tree. \n";
            }*/
        }

        else if (input2 == "pre") {
            std::cout << "Which value would you like to find the predecessor of? \n";
            /*std::cin.ignore();
            input3 = std::cin.get();
            *found = bstmain.search(input3);
            if (found) {
                Bst_node* predecessor = bstmain.predecessor(found);
                if (predecessor) {
                    std::cout << "The predecessor of " << input3 << " is " << predecessor.data_ << "\n";
                }
                else {
                    std::cout << input3 << " does not have a predecessor within the tree. \n";
                }
            }
            else {
                std::cout << input3 << " could not be found within the tree and therefore does"  
                          << " not have a predecessor. \n";
            }*/
        }

        else if (input2 == "suc") {
            std::cout << "Which value would you like to find the successor of? \n";
            /*std::cin.ignore();
            input3 = std::cin.get();
            *found = bstmain.search(input5);
            if (found3) {
                Bst_node* successor = bstmain.successor(found);
                if (successor) {
                    std::cout << "The successor of " << input3 << " is " << successor.data_ << "\n";
                }
                else {
                    std::cout << input3 << " does not have a successor within the tree. \n";
                }
            }
            else {
                std::cout << input3 << " could not be found within the tree and therefore does not "
                          << "have a successor. \n";
            }*/
        }

        else if (input2 == "add") {
            std::cout << "Which value would you like to add to the tree? \n";
            /*std::cin.ignore();
            input3 = std::cin.get(); 
            *found = bstmain.search(input3);
            if (found) {
                std::cout << input3 << " could not be added to the tree because it already exists. \n";
            }
            else {
                Bst_node* added = bstmain.add_node(input3);
                std::cout << input3 << " has been added to the tree. \n"
                          << "Its right child is " << added.right_child_.data_  << "\n";
                          << "Its left child is " << added.left_child_.data_  << "\n";
                          << "Its parent is " << added.parent_.data_  << "\n";
            }*/
        }

        else if (input2 == "rem") {
            std::cout << "Which value would you like to remove from the tree? \n";
            /*std::cin.ignore();
            input3 = std::cin.get();
            *found = bstmain.search(input3);
            if (found) {
                std::cout << input3 << " has been removed from the tree. \n";
            }
            else {
                std::cout << input3 << " could not be found within the tree and was therefore not removed. \n";
            }*/
        }
    }
    std::cout << "Shutting down the program. Goodbye! \n";

    //printBST();
    return 1;
}