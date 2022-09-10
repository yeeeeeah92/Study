#include <iostream>
using namespace std;

namespace BestComImp1
{
    void SimpleFunc()
    {
        cout << "BestCom Defined Func" << endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc()
    {
        cout << "ProgCom Defined Func" << endl;
    }
}

int main()
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}