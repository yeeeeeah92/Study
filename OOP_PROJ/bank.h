#ifndef __BANK_H_
#define __BANK_H_

#include <iostream>
#include "customer.h"

class Bank
{
    private : 
        Customer* customerList;
        int numOfCustomers;
    public : 
        Bank() 
        {

        }
        
        Customer makeAccount(string account, string name, int money)
        {

        }
        
        Customer depositMoney(string account, string name, int money)
        {

        }

        ~Bank()
        {

        }
};

#endif