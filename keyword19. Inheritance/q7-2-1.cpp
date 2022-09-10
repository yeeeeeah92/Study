#include <iostream>
using namespace std;

class Rectangle
{
    private : 
        int a;
        int b;
    public : 
        Rectangle(int na, int nb) : a(na), b(nb) {}
        void ShowAreaInfo()
        {
            cout << a << " x " << b << " = " << a*b << endl;
        }
};

class Square : public Rectangle
{
    private : 
    public : 
        Square(int n) : Rectangle(n, n) {}
};

int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}