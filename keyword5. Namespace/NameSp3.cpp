#include <iostream>
using namespace std;

namespace BestComImp1
{
    void SimpleFunc();
    void PrettyFunc();
}

namespace ProgComImp1
{
    void SimpleFunc();
}

int main()
{
    BestComImp1::SimpleFunc();

    return 0;
}

void BestComImp1::SimpleFunc()
{
    cout << "BestCom defined func" << endl;
    PrettyFunc();
    ProgComImp1::SimpleFunc();
}

void BestComImp1::PrettyFunc()
{
    cout << "BestCom defined Pretty-func" << endl;
}

void ProgComImp1::SimpleFunc()
{
    cout << "ProgCom defined func" << endl;
}