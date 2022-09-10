#include <iostream>
using namespace std;

int SimpleFunc(int a = 10)
{
    return a + 1;
}

int SimpleFunc()
{
    return 10;
}

int main()
{
    cout << SimpleFunc(1) << endl;  // 이렇게 하면 build error 안남
    //cout << SimpleFunc() << endl;   // 이렇게 하면 위 두 함수 중 어떤 type인지 몰라서 build error 남
}

// 위 함수의 오버로딩에 문제가 있음
// SimpleFunc 둘 다 매개변수가 없는 type으로도 호출 가능한 형태임