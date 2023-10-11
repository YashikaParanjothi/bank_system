# include <iostream>
# include <fstream>
# include "Hashtable.h"
# include <vector>
#include <memory>

using namespace std;

Hashtable::Hashtable()
{
    start = nullptr;
}

void Hashtable::starthash()
{
    for (int i = 0; i < 12; i++)
    {
        auto temp1 = make_unique<Node>(i);
        if (start == nullptr)
        {
            start = move(temp1);
        }
        else
        {
            Node* current = start.get();
            while (current->next != nullptr)
            {
                current = current->next.get();
            }
            current->next = move(temp1);
        }
    }
    loadhashtable();
}

void Hashtable::add(int a, int p)
{
    static int i = 0;
    ofstream write;
    write.open("hashtable.txt", ios::app);
    if (i != 0)
    {
        write << endl;
        write << a << endl << p;
    }
    else
    {
        i++;
        write << a << endl << p;
    }
    write.close();

    starthash();
}

bool Hashtable::match(int a, int p)
{
    bool flag = false;
    int r = a % 10;
    Node* c = start.get();
    while (c->data != r)
    {
        c = c->next.get();
    }
    Node_1* c1 = c->pre.get();
    while (c1 != nullptr)
    {
        if (c1->accountNumber == a && c1->password == p)
        {
            flag = true;
            break;
        }
        c1 = c1->next.get();
    }
    return flag;
}

void Hashtable::display()
{
    Node* current = start.get();
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next.get();
    }
}

void Hashtable::loadhashtable()
{
    int acc, r, pass;

    ifstream read;
    read.open("hashtable.txt");
    while (!read.eof())
    {
        read >> acc;
        read >> pass;
        if (match(acc, pass))
        {
            continue;
        }
        if (acc != -858993460 && pass != -858993460)
        {
            r = acc % 10;
            Node* c = findNode(r);
            if (c != nullptr)
            {
                addNodeToHashTable(c, acc, pass);
            }
        }
        else
        {
            cout << "NO password present" << endl;
        }
    }
    read.close();
}

void Hashtable::displayPasswords()
{
    starthash();
    Node* c = start.get();
    while (c != nullptr)
    {
        Node_1* c1 = c->pre.get();
        while (c1 != nullptr)
        {
            // Display passwords logic
            c1 = c1->next.get();
        }
        c = c->next.get();
    }
}

Node* Hashtable::findNode(int r)
{
    Node* c = start.get();
    while (c != nullptr && c->data != r)
    {
        c = c->next.get();
    }
    return c;
}

void Hashtable::addNodeToHashTable(Node* c, int acc, int pass)
{
    auto temp = make_unique<Node_1>(acc, pass);
    if (c->pre == nullptr)
    {
        c->pre = move(temp);
    }
    else
    {
        Node_1* root = c->pre.get();
        while (root->next != nullptr)
        {
            root = root->next.get();
        }
        root->next = move(temp);
    }
}
