#include <iostream>
using namespace std;

class BaseOne
{
    public : 
        void SimpleFunc()
        {
            cout << "BaseOne" << endl;
        }
};

class BaseTwo
{
    public : 
        void SimpleFunc()
        {
            cout << "BaseTwo" << endl;
        }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
    public : 
        void ComplexFunc()
        {
            BaseOne::SimpleFunc();  // 다중상속의 경우 동일한 이름의 함수를 호출할 때 구분할 수 있도록 명시 해 주어야 한다.
            BaseTwo::SimpleFunc();
        }
};

int main()
{
    MultiDerived mdr;
    mdr.ComplexFunc();
    return 0;
}