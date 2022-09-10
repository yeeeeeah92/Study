#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;
    const int * ptr = &num;
    const int * &dptr = ptr;

    cout << "ptr->num : " << *ptr << endl;
    cout << "dptr->num : " << *dptr << endl;

    return 0;
}