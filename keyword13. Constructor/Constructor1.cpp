#include <iostream>
using namespace std;

class SimpleClass
{
    private : 
        int num1, num2;
    public : 
        SimpleClass()
        {
            num1 = 0;
            num2 = 0;
        }
        SimpleClass(int n)
        {
            num1 = n;
            num2 = 0;
        }
        SimpleClass(int n1, int n2)
        {
            num1 = n1;
            num2 = n2;
        }

        void ShowData() const
        {
            cout << num1 << ' ' << num2 << endl;
        }
};

int main(void)
{
    SimpleClass sc1;        // == SimpleClass * ptr1 = new SimpleClass(); == SimpleClass * ptr1 = new SimpleClass; != SimpleClass sc1();
    sc1.ShowData();         // SimpleClass sc1();은 함수 내에 정의된 함수의 원형으로 오인될 수 있어서 C++에서는 이를 생성자로 인정하지 않는다.

    SimpleClass sc2(100);   // == SimpleClass * ptr2 = new SimpleClass(100);
    sc2.ShowData();

    SimpleClass sc3(100, 200);  // == SimpleClass * ptr3 = new SimpleClass(100, 200);
    sc3.ShowData();

    return 0;
}