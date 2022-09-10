#include <iostream>
using namespace std;

class FruitSeller
{
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

    public : 
        void InitMembers(int price, int num, int money)
        {
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }

        int SaleApples(int money)
        {
            numOfApples -= (money / APPLE_PRICE);
            myMoney += money;

            return (money / APPLE_PRICE);
        }

        void ShowSalesResult()
        {
            cout << "remained apples : " << numOfApples << endl;
            cout << "earned : " << myMoney << endl;
        }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;

    public :
        void InitMembers(int money)
        {
            myMoney = money;
            numOfApples = 0;
        }

        void BuyApples(FruitSeller &seller, int money)
        {
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }

        void ShowBuyResult()
        {
            cout << "remained money : " << myMoney << endl;
            cout << "num of apples : " << numOfApples << endl;
        }
};

int main()
{
    FruitSeller seller;
    FruitBuyer buyer;

    seller.InitMembers(1000, 20, 0);
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "seller's status" << endl;
    seller.ShowSalesResult();
    cout << "buyer's status" << endl;
    buyer.ShowBuyResult();

    return 0;
}