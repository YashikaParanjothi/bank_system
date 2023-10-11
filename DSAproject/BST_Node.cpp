# include "BST_Node.h"

BST_Node::BST_Node() : name(""), adress(""), balance(0)
{
    // Default implementation for the default constructor
}

BST_Node::BST_Node(string name, string adress, int accountno, int password, int balance)
    : name(name), adress(adress), account_number(accountno), password(password), balance(balance)
{
    // Default implementation for the parameterized constructor
}

// Use "=default" for the default constructor
BST_Node::BST_Node() = default;

// Use "=default" for the copy constructor
BST_Node::BST_Node(const BST_Node&) = default;
