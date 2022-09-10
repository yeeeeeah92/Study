#include <iostream>
using namespace std;

namespace BestComImp1
{
    void SimpleFunc();
}

namespace ProgComImp2
{
    void SimpleFunc();
}

int main()
{
    BestComImp1::SimpleFunc();
    ProgComImp2::SimpleFunc();
}

void BestComImp1::SimpleFunc()
{
    cout << "BestComImp1 defined func" << endl;
}

void ProgComImp2::SimpleFunc()
{
    cout << "ProgComImp2 defined func" << endl;
}