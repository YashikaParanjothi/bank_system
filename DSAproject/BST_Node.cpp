# include "BST_Node.h"

BST_Node::BST_Node() : name(""), adress("")
{
}

BST_Node::BST_Node(string name, string adress, int accountno, int password, int balance)
    : name(name), adress(adress), account_number(accountno), password(password), balance(balance)
{
}
BST_Node::BST_Node() = default;
BST_Node::BST_Node(const BST_Node&) = default;
