#include <iostream>
using namespace std;

class AAA
{
    public : 
        AAA(int n)
        {
            cout << "defined constructor" << endl;
        }
};

int main(void)
{
    // AAA * a = new AAA;       --> 생성자가 없을 경우 사용 가능하나 생성자가 1개라도 있으면 Default Constructor는 없음
}