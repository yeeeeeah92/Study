#ifndef __CUSTOMER_H_
#define __CUSTOMER_H_

#include <iostream>
#include <cstring>
using namespace std;

class Customer
{
    private : 
        string account;
        string name;
        int money;
    public : 
        Customer (string account, string name, int money)
        {
            this->account = account;
            this->name = name;
            this->money = money;
        }
        ~Customer()
        {

        }
};

#endif