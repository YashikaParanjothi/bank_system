#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"

void admin()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while (condition != 6)
    {
        cout << "welcome ADMIN" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to add account " << endl;
        cout << "press 2 to delete account " << endl;
        cout << "press 3 to check all accounts " << endl;
        cout << "press 4 to see the password of an account " << endl;
        cout << "press 5 to edit account " << endl;
        cout << "press 6 to exit" << endl;
        cin >> condition;

        if (condition == 1)
        {
            string name = "", address = "";
            int accountNumber;
            int password;
            int balance;
            cout << "enter name" << endl;
            cin >> name;
            cout << "enter address" << endl;
            cin >> address;
            cout << "enter account number" << endl;
            cin >> accountNumber;
            cout << "enter password" << endl;
            cin >> password;
            cout << "enter balance" << endl;
            cin >> balance;
            t.add_Account(name, address, accountNumber, password, balance);
        }

        if (condition == 2)
        {
            int accountNumber = 0;
            cout << "enter account number" << endl;
            cin >> accountNumber;
            t.load_Server();
            t.Root = t.delete_Account(t.Root, accountNumber);
            cout << "account deleted successfully" << endl;
            h.delete_password(accountNumber);
            cout << "password deleted" << endl;
            t.update_server(t.Root);
            cout << "server updated" << endl;
        }

        if (condition == 3)
        {
            t.load_Server();
            t.printoinfo(t.Root);
        }

        if (condition == 4)
        {
            h.displayPasswords();
        }

        if (condition == 6)
        {
            condition = 6;
        }
    }
}
