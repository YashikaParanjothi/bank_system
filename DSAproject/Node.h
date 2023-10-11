# pragma once
# include "Node_1.h"
# include <iostream>
# include <fstream>
# include <string>

class Node
{
public:
    explicit Node(int);  
    Node *next;
    Node_1 *pre;
    int data;
    
    Node();
    explicit Node(int);
};
