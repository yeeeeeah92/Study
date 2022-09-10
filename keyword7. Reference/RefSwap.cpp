#include <iostream>
using namespace std;

void SwapByRef2(int &rval1, int& rval2)
{
    int temp;
    temp = rval1;
    rval1 = rval2;
    rval2 = temp;
}

int main(void)
{
    int val1 = 10;
    int val2 = 20;

    SwapByRef2(val1, val2);

    cout << "val1 : " << val1 << endl;
    cout << "val2 : " << val2 << endl;

    return 0;
}