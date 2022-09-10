#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
    private : 
        string str;
    public : 
        void SetString(string a)
        {
            str = a;
        }
        void ShowString()
        {
            cout << str << endl;
        }
};

int main()
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}