#include "customer.h"

namespace MENU
{
    enum
    {
        NEW_ACCOUNT,
        DEPOSIT_MONEY,
        WITHDRAW_MONEY,
        PRINT_ALL,
        EXIT
    };
};

void selectMenu(unsigned int &menu)
{
    cout << "---------- MENU ----------" << endl;
    cout << "   1. New Account" << endl;
    cout << "   2. Deposit Money" << endl;
    cout << "   3. Withdraw Money" << endl;
    cout << "   4. Print Account All" << endl;
    cout << "   5. Exit Banking" << endl << endl;
    cout << "Which Service? : " << endl;

    cin >> menu;
}

int main(void)
{
    unsigned int menu;
    do
    {
        
        /* code */
    } while (menu != MENU::EXIT);    
}