#include <iostream>
using namespace std;

class Base
{
    public : 
        Base() { cout << "Base Constructor" << endl;}
        void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base    // 다중상속시 동일 함수가 여러번 상속되는 것을 방지하고자 virtual keyword를 사용한다.
{
    public : 
        MiddleDerivedOne() : Base()
        {
            cout << "MiddleDerivedOne Constructor" << endl;
        }
        void MiddleFuncOne()
        {
            SimpleFunc();
            cout << "MiddleDerivedOne" << endl;
        }
};

class MiddleDerivedTwo : virtual public Base    // 다중상속시 동일 함수가 여러번 상속되는 것을 방지하고자 virtual keyword를 사용한다.
{
    public : 
        MiddleDerivedTwo() : Base()
        {
            cout << "MiddleDerivedTwo Constructor" << endl;
        }
        void MiddleFuncTwo()
        {
            SimpleFunc();
            cout << "MiddleDerivedTwo" << endl;
        }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
    public : 
        LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
        {
            cout << "LastDerived Constructor" << endl;
        }
        void ComplexFunc()
        {
            MiddleFuncOne();
            MiddleFuncTwo();
            SimpleFunc();
        }
};

int main()
{
    cout << "Before Construct Object..." << endl;
    LastDerived ldr;    // 실제 실행 시 Base 생성자가 2번 호출되는 것이 아니라 1번 호출된다. virtual keyword를 통해 가상상속 하였기 때문!
    cout << "After Construct Object..." << endl;
    ldr.ComplexFunc();
    return 0;
}