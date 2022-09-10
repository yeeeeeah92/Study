#include <iostream>
using namespace std;

class seller
{
    private : 
        const int price;
        int numOfApples;
        int money;
    public : 
        seller (int price, int num, int money) : price(price), numOfApples(num), money(money) {}    // const 변수 초기화
        int saleApples (int money)
        {
            numOfApples -= money / price;
            money += money;
        }
        void showResult() const
        {
            ////////////////////////////
        }
};