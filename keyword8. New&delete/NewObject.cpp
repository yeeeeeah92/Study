#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
    public : 
        Simple() 
        {
            cout << "I'm Simple Constructor. " << endl;
        }
};

int main(void)
{
    cout << "Case 1 : " << endl;
    Simple * sp1 = new Simple;
    cout << "Case 2 : " << endl;
    Simple * sp2 = (Simple *)malloc(sizeof(Simple));

    cout << "EOF" << endl;

    delete(sp1);
    free(sp2);
}