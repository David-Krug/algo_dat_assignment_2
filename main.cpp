#include "bst.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void print_nil(int key, int nilcount, std::ofstream& file)
{
    file << "    nil" << nilcount << " [shape=point]; \n";
    file << "    " << key << " -> nil" << nilcount;
}

void print_node(Bst_Node node, std::ofstream& file) {
    static int nil = 0;
    Bst_Node current = node;

    if (node.left_child_) {
        file << "    " << node.data_ << " -> " << node.left_child_->data_ << "; \n";
        print_node(*node.left_child_, file);
    }
    else {
        print_nil(node.data_, nil++, file);
    }

    if (node.right_child_) {
        file << "    " << node.data_ << " -> " << node.right_child_->data_;
        print_node(*node.right_child_, file);
    }
    else {
        print_nil(node.data_, nil++, file);
    }
}

void printBST(Bst_Node const& node) {
    std::ofstream Graphfile("Graph.txt");
    Graphfile << "digraph BST { \n";
    Graphfile << "    node [fontname=\"Arial\"]; \n";
    Graphfile << "    graph [ordering=\"out\"]; \n";

    if (!node.data_) {
        Graphfile << "\n";
    }
    else if (!node.right_child_ && !node.left_child_) {
        Graphfile << "    " << node.data_ << "; \n";
    }
    else {
        print_node(node, Graphfile);
    }

    Graphfile << "\n    }";
    Graphfile.close();
}

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

    std::cout << "\nBuilding the tree...\n";
    Bst bstmain;
    for (int i : sequence) {
        bstmain.add_node(i);
    }
    std::cout << "\nThe tree in order:\n";
    bstmain.in_order(bstmain.root_);

    std::string input2 = "start", input3 = "start"; 

    while (input2 != "quit") {

        std::cout << "\n \n Which function of the tree would you like to execute? (enter 'quit' to exit) \n"
                    << "- Find maximum or minimum - Enter 'max' or 'min' \n"
                    << "- Search the tree for a specific value - Enter 'search' \n"
                    << "- Find the pre- or successor of a node - Enter 'pre' or 'suc' \n"
                    << "- Add or remove a node from the tree - Enter 'add' or 'rem' \n"
                    << "- Print the tree in order. - Enter 'io' \n"
                    << "- Print the tree to a text file in the dot language. - Enter 'print' \n";
        std::cin.ignore();
        std::cin >> input2;

        if (input2 == "min") {
            std::cout << "Searching for the minimum of the tree. \n";
            std::cout << "The minimum of the tree is " << bstmain.minimum(bstmain.root_)->data_ << std::endl;
        }

        else if (input2 == "max") {
            std::cout << "Searching for the maximum of the tree. \n";
            std::cout << "The maximum of the tree is " << bstmain.maximum(bstmain.root_)->data_ << std::endl;
        }

        else if (input2 == "search") {
            std::cout << "Which value would you like to search the tree for? \n";
            std::string str3;
            std::cin >> str3;
            auto input3 = stoi(str3);
            if (bstmain.search(input3, bstmain.root_) == nullptr) {
                std::cout << input3 << " is not in the tree. \n";
            }
            else {
                std::cout << input3 << " is part of the tree. \n";
            }
        }

        else if (input2 == "pre") {
          std::cout << "Which value would you like to find the predecessor of? \n";
          std::string str3;
          std::cin >> str3;
          auto input3 = stoi(str3);
          auto found = bstmain.search(input3, bstmain.root_);
          if (found != nullptr) {
            std::cout << bstmain.predecessor(found)->data_ << " Is the predecessor of " << found->data_ << std::endl;
          }
          else {
              std::cout << input3 << " could not be found within the tree and was therefore has no predecessor. \n";
          }
        }

        else if (input2 == "suc") {
          std::cout << "Which value would you like to find the successor of? \n";
          std::string str3;
          std::cin >> str3;
          auto input3 = stoi(str3);
          auto found = bstmain.search(input3, bstmain.root_);
          if (found != nullptr) {
            std::cout << bstmain.successor(found)->data_ << " Is the successor of "<< found->data_<< std::endl;
          }
          else {
            std::cout << input3 << " could not be found within the tree and was therefore has no successor. \n";
          }
        }

        else if (input2 == "add") {
            std::cout << "Which value would you like to add to the tree? \n";
            std::string str3;
            std::cin >> str3;
            auto input3 = stoi(str3);
            bstmain.add_node(input3);
        }

        else if (input2 == "rem") {
          std::cout << "Which value would you like to remove from the tree? \n";
          std::string str3;
          std::cin >> str3;
          auto input3 = stoi(str3);
          auto found = bstmain.search(input3,bstmain.root_);
          if (found != nullptr) {
            bstmain.remove_node(found);
            std::cout << input3 << " has been removed from the tree. \n";
          }
          else {
            std::cout << input3 << " could not be found within the tree and was therefore not removed. \n";
          }
        }
        else if (input2 == "print") {
          auto arg = bstmain.root_;
          printBST(*arg);
          std::cout << "The tree has been printed to the file Graph.txt" << std::endl;
        }
        else if (input2 == "io") {
          std::cout << "The tree in order:" <<  std::endl;
          bstmain.in_order(bstmain.root_);
        }
    }
    std::cout << "Shutting down the program. Goodbye! \n";

    return 1;
}