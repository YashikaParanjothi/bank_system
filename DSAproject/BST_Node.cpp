# include "BST_Node.h"

BST_Node::BST_Node() : name(""), adress(""), account_number(0), password(0), balance(0)
{
}

BST_Node::BST_Node(string name, string adress, int accountno, int password, int balance)
    :  name(name), adress(adress), account_number(accountno), password(password), balance(balance)
{
}
